#!/usr/bin/perl -w

while (<>) {
    chomp;
    if (/^[ \t][ \t]+# (.*)$/) {
	print "$1\n";
    }
}
