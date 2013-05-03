#include "EXTERN.h"
#include "perl.h"
#include "XSUB.h"

#include "ppport.h"
#include "../../src/dtree_client.h"
#include "../../src/dclass_client.h"

#include <stdio.h>

#include "const-c.inc"
#define KEY_DTREE_POINTER "__dtree_pointer"
MODULE = UA::dClass		PACKAGE = UA::dClass		

INCLUDE:    const-xs.inc
PROTOTYPES: ENABLE

SV*
loadDDR(self,path)
  SV* self
  SV* path
  CODE:
    STRLEN path_l;
    char *path_buf = SvPV(path,path_l);
    printf("path=%s\n",path_buf);
    dclass_index *di = malloc(sizeof(dclass_index));
    dclass_load_file(di,path_buf);
    printf("[XS] di=%ld\n",di);

    // store the pointer
    HV *sv_hv_self = (HV*) SvRV(self);
    SV *sv_di = newSViv((int)di);
    hv_store(sv_hv_self,KEY_DTREE_POINTER,strlen(KEY_DTREE_POINTER),sv_di,0);
    
    RETVAL = NULL;
  OUTPUT:
    RETVAL


SV*
freeDDR(self)
  SV* self
  CODE:
    HV *sv_hv_self = (HV*) SvRV(self);
    SV **sv_di = hv_fetch(sv_hv_self,KEY_DTREE_POINTER,strlen(KEY_DTREE_POINTER),0);
    printf("[XS] freeDDR\n");
    dclass_index *di = SvIV(*sv_di);
    RETVAL = NULL;
  OUTPUT:
    RETVAL


SV*
classifyUA(self,ua)
  SV* self
  SV* ua
  CODE:
    STRLEN ua_l;
    char *ua_buf = SvPV(ua,ua_l);
    RETVAL = NULL;
  OUTPUT:
    RETVAL
