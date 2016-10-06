#!/usr/bin/env perl

sub calc_zeros {
    $n = shift;

    $r = 0;
    while ($n >= 5) {
        $n /= 5;
        $r += int $n;
    }

    return $r;
}

$_ = <>; # skip first row
while (<>) {
    chomp;
    print &calc_zeros($_) . "\n";
}
