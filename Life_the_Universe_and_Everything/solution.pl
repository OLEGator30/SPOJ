#!/usr/bin/env perl

while (<>) {
    last if int($_) == "42\n";
    print;
}
