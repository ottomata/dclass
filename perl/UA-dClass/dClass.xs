#include "EXTERN.h"
#include "perl.h"
#include "XSUB.h"

#include "ppport.h"

#include "const-c.inc"





MODULE = UA::dClass		PACKAGE = UA::dClass		

INCLUDE:    const-xs.inc
PROTOTYPES: ENABLE

SV*
classifyUA(self,UA)
  SV* self
  SV* UA
  CODE:
    STRLEN ua_l;
    char *ua_buf = SvPV(UA,ua_l);
    RETVAL = NULL;
  OUTPUT:
    RETVAL


