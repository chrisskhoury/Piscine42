# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    perl_generator.pl                                  :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cel-khou <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/07/23 15:54:39 by cel-khou          #+#    #+#              #
#    Updated: 2018/07/23 16:00:01 by cel-khou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#!/usr/bin/perl
use warnings;
use strict;

die "program x y density" unless (scalar(@ARGV) == 3);

my ($x, $y, $density) = @ARGV;

print "$y.ox\n";

for (my $i = 0; $i < $y; $i++) {
    for (my $j = 0; $j < $x; $j++) {
		if (int(rand($y) * 2) < $density) {
    		print "o";
		}
		else {
			print ".";
		}
	}
	print "\n";
}
