#!/usr/bin/env perl

chomp($nTests = <>);
foreach (1..$nTests) {
    chomp($str = <>);

    $nLevels = int($str);
    $val = (3 * $nLevels ** 2 + $nLevels) / 2;
    $val %= 1000007;

    print "$val\n";
}
