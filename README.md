
Steps to build the debian package libdclass:

  ## optional ( to clean out old packages )
  # rm -f ../libdclass_*;
  make clean; 
  ## optional ( to clean between consecutive package builds)
  # rm -rf configure Makefile debian/libdclass;
  libtoolize; 
  aclocal; 
  autoheader; 
  autoconf; 
  automake --add-missing; 
  dpkg-buildpackage -us -uc;
  ## optional (to show contentl of the package)
  # dpkg -c ../libdclass_0.1_i386.deb
