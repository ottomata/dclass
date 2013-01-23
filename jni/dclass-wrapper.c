#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <jni.h>
#include <stdio.h>
#include "dclass-wrapper.h"
#include "dclass_client.h"


jstring generate_dummy_return_string(JNIEnv *env) {
  char* newstring;

  jstring ret = 0;

  /*newstring = (char\*)malloc(30);*/
  newstring = (char*)malloc(30);

  if(newstring == NULL) 
  {      
      return ret;
  }

  memset(newstring, 0, 30);  
  
  newstring = "foo: Test program of JNI.\\n";

  ret = (*env)->NewStringUTF(env, newstring);
  return ret;
}


/*JNIEXPORT jstring JNICALL Java_DclassWrapper_nativeFoo (JNIEnv \*env, jobject obj)*/
JNIEXPORT jstring JNICALL Java_org_wikimedia_analytics_dclassjni_DclassWrapper_nativeFoo (JNIEnv *env, jobject obj)
{
  jstring ret = 0;

  ret = generate_dummy_return_string(env);
  return ret;
}

/**
  * Will store the pointer in the Java class so we can reuse it on multiple calls
  * of JNI API
  *
  */

long set_dclass_index_pointer(JNIEnv *env, jobject obj,long value) {
  jclass cls = (*env)->GetObjectClass(env,obj);
  jfieldID fid;
  fid = (*env)->GetFieldID(env,cls,"pointer_di","J");
  if (fid == NULL){
    printf("[ERR] fid is null at line %d inside dclass-wrapper.c\n",__LINE__);
    return;
  };

  (*env)->SetLongField(env,obj,fid,(jlong)value);
};


/* returns pointer to dclass_index (stored in the Java class) */

long get_dclass_index_pointer(JNIEnv *env, jobject obj) {
  jclass cls = (*env)->GetObjectClass(env,obj);
  jfieldID fid;
  fid = (*env)->GetFieldID(env,cls,"pointer_di","J");
  if (fid == NULL){
    printf("[ERR] fid is null at line %d inside dclass-wrapper.c\n",__LINE__);
    return;
  };

  long value = (*env)->GetLongField(env,obj,fid);

  return value;
};


// -Xcheck:jni
// -verbose:jni

JNIEXPORT void JNICALL Java_org_wikimedia_analytics_dclassjni_DclassWrapper_initUA (JNIEnv *env, jobject obj) {
  dclass_index *di;

  di = malloc(sizeof(dclass_index));
  char *loadFile="/usr/share/libdclass/dtrees/openddr.dtree";
  char *outFile="";
  char *parameter=NULL;

  /*int ret=openddr_load_resources(di,loadFile);*/
  int ret=dclass_load_file(di,loadFile);

  set_dclass_index_pointer(env,obj,(long)di);
}

JNIEXPORT void JNICALL Java_org_wikimedia_analytics_dclassjni_DclassWrapper_destroyUA (JNIEnv *env, jobject obj) {
  long l_di = get_dclass_index_pointer(env,obj);

  dclass_index *di = (dclass_index *) l_di;
  dclass_free(di);
}



JNIEXPORT jobject JNICALL Java_org_wikimedia_analytics_dclassjni_DclassWrapper_classifyUA (JNIEnv *env, jobject obj,jstring paramUA)
{
  int i;
  int ds_ret;
  char *_paramUA;
  dclass_index *di;

  
  jclass mapClass = (*env)->FindClass(env, "java/util/HashMap");
  if(mapClass == NULL)
  {
    printf("[JNI] Didn't find java/util/HashMap class line ==> %d \n",__LINE__);
    return NULL;
  }

  
  // get and convert and print parameter
  _paramUA = (*env)->GetStringUTFChars( env, paramUA , NULL ) ;
  /*_paramUA = (*env)->GetStringChars( env, paramUA , NULL ) ;*/


  long l_di = get_dclass_index_pointer(env,obj);

  di = (dclass_index *) l_di;

  /*******************************************************************************/

  /*return generate_dummy_return_string();*/
  const dclass_keyvalue *kvd;
  kvd=dclass_classify(di,_paramUA);

  /*use the right size for the Java hashmap */
  jsize map_len = kvd->size;
  /* init the java hashmap */
  jmethodID init = (*env)->GetMethodID(env, mapClass, "<init>", "(I)V");
  if(init == NULL) {
    printf("[JNI] Couldn't get ctor for java/util/HashMap line ==> %d\n",__LINE__);
    return NULL;
  };
  jobject hashMap = (*env)->NewObject(env, mapClass, init, map_len);
  if(hashMap == NULL) {
    printf("[JNI] Couldn't create new object java/util/HashMap line ==> %d\n",__LINE__);
    return NULL;
  };

  jmethodID put = (*env)->GetMethodID(env, mapClass, "put",
            "(Ljava/lang/Object;Ljava/lang/Object;)Ljava/lang/Object;");

  if(put == NULL) {
    printf("[JNI] Couldn't get put method id for HashMap line ==> %d\n",__LINE__);
    return NULL;
  };


  if(kvd && kvd->size) {
    for(i=0;i<kvd->size;i++) {
      jstring value;
      jstring key  ;
      key   = (*env)->NewStringUTF(env, kvd->keys[i]);
      value = (*env)->NewStringUTF(env, kvd->values[i]);

      (*env)->CallObjectMethod(env, hashMap, put, key, value);
      (*env)->DeleteLocalRef(env, key);
      (*env)->DeleteLocalRef(env, value);
    };
  };
  return hashMap;
}
