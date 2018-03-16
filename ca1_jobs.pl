#!/usr/bin/env perl

use strict;
use warnings;

sub random_integer {
    my $min = shift;
    my $max = shift;
    return int(rand($max-$min)) + $min;
}

if (@ARGV < 3) {
    die("usage: ca1_jobs.pl <jobs> <max arrival time> <max runtime>");
}

my ($jobs, $max_arrival, $max_runtime) = @ARGV;
my $output;

for ( my $job = 0 ; $job < $jobs ; ++$job ) {

    my $arrival_time = random_integer(0, $max_arrival);
    my $run_time = random_integer(1, $max_runtime);
    
    $output .= "JOB_$job $arrival_time $run_time\n";
}

print $output;
