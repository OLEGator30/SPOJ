#!/usr/bin/env perl

use Math::BigInt;

@factorials = (undef) x 100;
$factorials[0] = Math::BigInt->bone();
chomp($nTests = <>);
foreach (1..$nTests) {
    if ($_ > 1) { # WTF?!
        print "\n";
    }

    chomp($str = <>);
    $number = int $str;

    unless (defined $factorials[$number - 1]) {
        $i = $number - 2;
        --$i while not defined $factorials[$i];
        while ($i < $number) {
            ++$i;
            $factorials[$i] = $factorials[$i - 1]->copy();
            $factorials[$i]->bmul($i + 1);
        }
    }

    print $factorials[$number - 1];
}
