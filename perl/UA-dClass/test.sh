#!/bin/bash
perl Makefile.PL ;
make ;
echo "===============================";
echo "===============================";
perl -Ilib -Iblib/arch/auto/UA/dClass/  \
     -I./blib/                          \
      t/01-basic.t;
