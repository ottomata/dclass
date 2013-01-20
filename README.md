

Steps to build the debian package libdclass:

    # first of all you need to pull the debianize submodule
    git submodule update --init
    # Then you need some tags. If you are building a new version
    # make sure you've pulled from upstream and merged. Afterwards
    # make sure to make a new tag and then
    ./git2deblogs.pl --generate
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
