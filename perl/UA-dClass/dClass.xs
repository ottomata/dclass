#include "EXTERN.h"
#include "perl.h"
#include "XSUB.h"

#include "ppport.h"

#include <stdio.h>

#include "const-c.inc"

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
