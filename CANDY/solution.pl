#!/usr/bin/env perl

use strict;
use warnings;

while (1) {
    chomp (my $nPackets = <>);

    last if $nPackets == -1;

    my @packets;
    my $sum = 0;
    foreach (1..$nPackets) {
        chomp(my $nCandies = <>);

        push @packets, $nCandies;
        $sum += $nCandies;
    }

    if ($sum % $nPackets == 0) {
        my $candiesPerPacket = $sum / $nPackets;

        my $moves = 0;
        foreach my $packet (@packets) {
            $moves += $candiesPerPacket - $packet if $candiesPerPacket > $packet;
        }

        print "$moves\n";
    } else {
        print "-1\n";
    }
}
