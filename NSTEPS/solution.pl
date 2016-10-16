#!/usr/bin/env perl

chomp($nTests = <>);
foreach (1..$nTests) {
    chomp($str = <>);
    ($x, $y) = split / /, $str;

    if ($x % 2 == 0) {
        if ($y == $x) {
            $val = 2 * $x;
        } elsif ($y == $x - 2) {
            $val = 2 * $x - 2;
        } else {
            $val = "No Number";
        }
    } else {
        if ($y == $x) {
            $val = 2 * $x - 1;
        } elsif ($y == $x - 2) {
            $val = 2 * $x - 3;
        } else {
            $val = "No Number";
        }
    }

    print "$val\n";
}
