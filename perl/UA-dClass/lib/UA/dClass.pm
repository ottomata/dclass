package UA::dClass;

use 5.014002;
use strict;
use warnings;
use Carp;

require Exporter;
use AutoLoader;

our @ISA = qw(Exporter);

our $VERSION = '2.02';

require XSLoader;
XSLoader::load('UA::dClass', $VERSION);


1;
__END__
# Below is stub documentation for your module. You'd better edit it!

=head1 NAME

UA::dClass - Perl extension Device Detection

=head1 SYNOPSIS

  use strict;
  use warnings;
  use UA::dClass;

  my $d = UA::dClass->new;
  my $h = $d->classify("...");

=head1 DESCRIPTION

=head1 SEE ALSO

=head1 AUTHOR

Stefan Petrea, E<lt>stefan@garage-coding.comE<gt>

=head1 COPYRIGHT AND LICENSE

Copyright (C) 2013 by Stefan Petrea

This library is free software; you can redistribute it and/or modify
it under the same terms as Perl itself, either Perl version 5.14.2 or,
at your option, any later version of Perl 5 you may have available.

=cut
