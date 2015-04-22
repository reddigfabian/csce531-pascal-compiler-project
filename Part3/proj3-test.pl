#!/usr/bin/perl -w

# Perl script for testing CSCE 531 project 3 submissions (Ctrl flow & arrays)

# Usage (must be run in the parent directory of pas-proj3):
# $ proj3-test.pl --self-test

# Writes to file "pas-proj1comments.txt" in your directory

# edit as needed
$project_directory = "$ENV{HOME}/public_html/csce531/handouts/pas-proj3";
$semester = 'sp15';

# This varies by system
# On CSE Linux systems
# $bison_parse_error_msg = "syntax error";
# On my Mac G5
# $bison_parse_error_msg = "parse error";

############ You should not have to edit below this line ##############

$testSuiteDir = "$project_directory/test";
$submissionRoot = "$ENV{HOME}/courses/csce531/$semester/pas-proj3/submissions";
$testFilePrefix = 'T3L';
$hwDir = 'pas-proj3';
$timeout = 11;			# seconds
$prog_name = 'ppc3';

%lib_files = (
    '80' => 'lib80',
    '80extra' => 'lib80extra',
    '90' => 'lib90',
    '90extra' => 'lib90',
    '100' => 'lib100',
    '100extra' => 'lib100',
    '110' => 'lib110',
);

# Hash to hold the test results
%error_counts = ();

# Check existence of test suite directory
die "No test suite directory $testSuiteDir\n"
    unless -d $testSuiteDir;

#sub main
{
    # Get Pascal source test files
    opendir DIR, $testSuiteDir;
    my @filenames = readdir DIR;
    my @testfilenames = ();
    while (@filenames) {
        $name = shift @filenames;
	next if $name !~ /^($testFilePrefix.*)\.pas$/;
	push @testfilenames, ($1);
    }

    # Typical element is $test_source_hash{$level}->{$ok_or_err} = $base
    %test_source_hash = ();

    foreach $base (@testfilenames) {
	$base =~ /^$testFilePrefix(.*)_(err|ok)$/;
	$test_source_hash{$1}{$2} = $&;
    }

    # Get execution test files
    opendir DIR, "$testSuiteDir/out";
    @filenames = readdir DIR;
    @testfilenames = ();
    while (@filenames) {
        $name = shift @filenames;
	next if $name !~ /^($testFilePrefix.*)_ok\.out$/;
	push @testfilenames, ($1);
    }

    # Typical element is $test_exec_out_hash{$level} = $base
    %test_exec_out_hash = ();
    # similar
    %test_exec_in_hash = ();

    foreach $base (@testfilenames) {
	$base =~ /^$testFilePrefix(.*)$/;
	$test_exec_out_hash{$1} = $base;
	if (-e "$testSuiteDir/out/${base}_ok.in") {
	    $test_exec_in_hash{$1} = $base;
	}
    }

    if (@ARGV && $ARGV[0] eq '--self-test') {
	$uname = 'self-test';
	process_user();
    }
    elsif (@ARGV) {
	while (@ARGV) {
	    $uname = shift @ARGV;
	    process_user();
	}
    }
    else {
	opendir DIR, $submissionRoot
	    or die "Cannot open submission directory $submissionRoot ($!)\n";
	@usernames = readdir DIR;
	closedir DIR;

	while (@usernames) {
	    $uname = shift @usernames;
	    next if $uname =~ /^\./;
	    next unless -d "$submissionRoot/$uname";
	    process_user();
	}
    }
}


sub process_user {
    print(STDERR "Processing $uname/$hwDir\n\n");
    if ($uname eq 'self-test') {
	$udir = `pwd`;
	chomp $udir;
    }
    else {
	$udir = "$submissionRoot/$uname";
    }
    die "No subdirectory corresponding to $uname ($!)\n"
	unless -d $udir;

    open(COMMENTS, "> $udir/${hwDir}comments.txt");

    cmt("Comments for $uname -------- " . now() . "\n");

    chdir $udir;

    if (!(-d $hwDir)) {
	cmt("  No $hwDir subdirectory found\n");
	close COMMENTS;
	return;
    }

    chdir $hwDir
	or die "Cannot change to $udir/$hwDir directory ($!)\n";

    # try make clean, regardless of what happens
    system("make", "clean");

    opendir DIR, "$udir/$hwDir"
	or die "Cannot open $udir/$hwDir directory ($!)\n";
    @filenames = readdir DIR;
    closedir DIR;
    $count = 0;
    while (@filenames) {
	$filename = shift @filenames;
	chomp $filename;
	next if $filename =~ /^\./;
	if ($filename =~ /lex\.yy|y\.tab|\.o$|parse\.c|scan\.c|ppc3/) {
	    cmt("Removing illegal file: $filename\n");
	    unlink $filename;
	    $count++;
	}
    }
    cmt("No illegal files found\n")
	if $count == 0;

    # Temporary patch -- remove afterwards
    # system("cp", "/class/csce531-001/handouts/pas-proj1/backend-x86.h", ".");
    # system("cp", "/class/csce531-001/handouts/pas-proj1/backend-x86.c", ".");
    # End temporary patch

    %error_counts = ();

    print(STDERR "\nTesting compile ...\n");
    test_compiler($prog_name);

    report_compiler_summary();

    %error_counts = ();

    print(STDERR "\n\nTesting execution ...\n");
    test_execution($prog_name);

    report_execution_summary();

    close COMMENTS;

    # try cleaning -- don't care what happens
    system("make", "clean");

    if ($uname eq 'self-test') {
	print(STDERR "\nDone.\nComments are in ${hwDir}comments.txt\n");
    }
    else {
	print(STDERR "\nDone.\nComments are in $uname/${hwDir}comments.txt\n");
    }
}


sub test_compiler {
    my ($prog) = @_;

    print(STDERR "\nCompiling: error msgs for $uname/$prog:\n");
    print(STDOUT "\nCompiling: system msgs for $uname/$prog:\n");

    cmt("\nTesting compiliation with $prog:\n");

    $error_counts{$prog} = 0;

    $rc = test_make($prog);

    if (!$rc) { # if couldn't make original prog
	cmt("Make of $prog failed\n");
	$error_counts{$prog}++;
	return;
    }

    foreach $level (sort by_extracted_number (keys(%test_source_hash))) {

	cmt("\n\nLEVEL $level:\n\n");

	foreach $key (sort { $b cmp $a; } (keys(%{$test_source_hash{$level}}))) {

	    $base = $test_source_hash{$level}{$key};

	    -e "$testSuiteDir/$base.pas" || die "$base.pas does not exist ($!)\n";
	    cmt("Running $prog with input $base.pas ...");
	    print(STDERR "----$base.pas:\n");
	    $testFile = "$testSuiteDir/$base.pas";
	    unlink "$base.s"
		if -e "$base.s";
	    unlink "$base.err"
		if -e "$base.err";
	    $error_counts{$base} = 0;
	    eval {
		local $SIG{ALRM} = sub { die "timed out\n" };
		alarm $timeout;
		$rc = system("./$prog < $testFile > $base.s 2> $base.err");
		alarm 0;
	    };
	    if ($@ && $@ eq "timed out\n") {
		cmt(" $@");		# program timed out before finishing
		$error_counts{$base}++;
		next;
	    }
	    elsif ($rc >> 8) {
		cmt(" nonzero termination status\n");
	    }
	    else {
		cmt(" zero termination status\n");
	    }

	    # Test error file in any case
	    if ($base =~ /_err$/ && -e "$base.err") {
		cmt("  $base.err exists\n  Comparing with solution file ...");
		$report = `diff $base.err $testSuiteDir/out/$base.err`;
		chomp $report;
		if ($report eq '') {
		    cmt(" files match\n");
		}
		else {
		    cmt(" files differ:\nvvvvv\n$report\n^^^^^\n");
		    $error_counts{$base}++;
		}
	    }
	    elsif (-e "$base.err") {   # testing with error-free source
		$report = `cat $base.err`;
		chomp $report;
		if ($report ne '') {
		    cmt("  errors reported:\nvvvvv\n$report\n^^^^^\n");
		    $error_counts{$base}++;
		}
	    }
	    elsif ($base =~ /_err$/) {
		cmt("  No error output for $base\n");
		$error_counts{$base}++;
	    }

	    next if ($base =~ /_err$/);

	    # At this point, Pascal source is error-free.

	    if (!(-e "$base.s")) {
		cmt("  output file $base.s does not exist\n");
		$error_counts{$base}++;
		next;
	    }

	    cmt("  $base.s exists ... will assemble and run later\n");

        }
    }
}


sub test_execution {
    my ($prog) = @_;

    print(STDERR "Execution: error msgs for $uname/$prog:\n");
    print(STDOUT "Execution: system msgs for $uname/$prog:\n");

    cmt("\nTesting execution with $prog:\n");

    $error_counts{$prog} = 0;

    foreach $level (sort by_extracted_number (keys(%test_exec_out_hash))) {

	cmt("\n\nLEVEL $level:\n\n");

	$base = $test_exec_out_hash{$level};
	$error_counts{$base} = 0;

	-e "$testSuiteDir/out/${base}_ok.out" || die "${base}_ok.out does not exist ($!)\n";
	print(STDERR "----$base:\n");

	if (!(-e "${base}_ok.s")) {
	    cmt("Assembly file ${base}_ok.s does not exist\n");
	    $error_counts{$base}++;
	    next;
	}
	    
	unlink "a.out"
	    if -e "a.out";

	cmt("Trying to assemble ${base}_ok.s with gcc ");
	if (exists($lib_files{$level})) {
	    cmt("and $lib_files{$level} ... ");
	    $rc = system("gcc", "-m32", "${base}_ok.s", "$testSuiteDir/$lib_files{$level}.o");
	}
	else {
	    cmt("... ");
	    $rc = system("gcc", "-m32", "${base}_ok.s");
	}
	if ($rc >> 8) {
	    cmt(" failed\n");
	    $error_counts{$base}++;
	}
	else {
	    cmt(" succeeded\n");
	}

	if (-e "a.out") {
	    cmt("Executable a.out exists\n");
	}
	else {
	    cmt("Executable a.out does not exist\n");
	    next;
	}

	$testFile = "$testSuiteDir/out/${base}_ok.in";
	eval {
	    local $SIG{ALRM} = sub { die "timed out\n" };
	    alarm $timeout;
	    if (-e $testFile) {
	        cmt("./a.out < ${base}_ok.in > ${base}_ok.out 2> ${base}_ok_exec.err");
		$rc = system("./a.out < $testFile > ${base}_ok.out 2> ${base}_ok_exec.err");
	    }
	    else {
	        cmt("./a.out > ${base}_ok.out 2> ${base}_ok_exec.err");
		$rc = system("./a.out > ${base}_ok.out 2> ${base}_ok_exec.err");
	    }
	    alarm 0;
	};
	if ($@ && $@ eq "timed out\n") {
	    cmt(" $@");		# program timed out before finishing
	    $error_counts{$base}++;
	    next;
	}
	elsif ($rc >> 8) {
	    cmt(" terminated abnormally\n");
	    # $error_counts{$base}++;
	    if (-e "${base}_ok_exec.err") {
		cmt("  Standard error output:\nvvvvv\n");
		$report = `cat ${base}_ok_exec.err`;
		chomp $report;
		cmt("$report\n^^^^^\n");
	    }
	}
	else {
	    cmt(" terminated normally\n");
	    if (-e "${base}_ok_exec.err") {
		cmt("  Standard error output:\nvvvvv\n");
		$report = `cat ${base}_ok_exec.err`;
		chomp $report;
		cmt("$report\n^^^^^\n");
	    }
	}

	if (!(-e "${base}_ok.out")) {
	    cmt("  output file ${base}_ok.out does not exist\n");
	    $error_counts{$base}++;
	    next;
	}

	cmt("  ${base}_ok.out exists -- comparing with solution output file\n");
	$report = `diff ${base}_ok.out $testSuiteDir/out/${base}_ok.out`;
	chomp $report;
	if ($report eq '') {
	    cmt(" files match\n");
	    next;
	}
	cmt(" files differ:\nvvvvv\n$report\n^^^^^\n");
	$error_counts{$base}++;
    }
}



# Tries to make the given executable program.  Returns true iff success
sub test_make {
    my ($prog) = @_;
    my $execFile = "$prog";

    cmt("  Attempting to build $prog ...");
    $rc = system("make", "-B", $prog);
    if ($rc >> 8) {
	cmt(" make -B $prog failed\n");
	return 0;
    }

    if (!(-e $execFile)) {
	cmt(" $prog executable does not exist\n");
	return 0;
    }

    cmt(" ok\n");
    return 1;
}


sub report_compiler_summary {
    cmt("######################################################\n");
    cmt("Compilation summary for $uname:\n");

    foreach $base (sort(keys %error_counts)) {
	cmt("  $base: ");
	$cnt = $error_counts{$base};
	if ($cnt > 0) {
	    cmt(" problem(s) found");
	}
	elsif ($base !~ /_err$/) {
	    cmt(" ok");
	}
	else {
	    cmt(" error message(s) (check appropriateness)");
	}
	cmt("\n");
    }
    cmt("######################################################\n");
    # cmt(" 80% level: \n");
    # cmt(" 90% level: \n");
    # cmt("100% level: \n");
    # cmt("110% level: \n");
}


sub report_execution_summary {
    cmt("######################################################\n");
    cmt("Assembly/execution summary for $uname:\n");

    foreach $base (sort(keys %error_counts)) {
	cmt("  $base: ");
	$cnt = $error_counts{$base};
	if ($cnt > 0) {
	    cmt(" problem(s) found");
	}
	elsif ($base !~ /_err$/) {
	    cmt(" ok");
	}
	else {
	    cmt(" error message(s) (check appropriateness)");
	}
	cmt("\n");
    }
    cmt("######################################################\n");
    cmt(" 80% level: \n");
    cmt(" 90% level: \n");
    cmt("100% level: \n");
    cmt("110% level: \n");
}


sub cmt {
    my ($str) = @_;
#  print $str;
    print(COMMENTS $str);
}


sub now {
    my $ret;

    my ($sec,$min,$hour,$mday,$mon,$year,$wday,$yday,$isdst) = localtime;
    $ret = ('Sun','Mon','Tue','Wed','Thu','Fri','Sat')[$wday];
    $ret .= " ";
    $ret .= ('Jan','Feb','Mar','Apr','May','Jun','Jul',
	     'Aug','Sep','Oct','Nov','Dec')[$mon];
    $ret .= " $mday, ";
    $ret .= $year + 1900;
    $ret .= " at ${hour}:${min}:${sec} ";
    if ( $isdst ) {
	$ret .= "EDT";
    } else {
	$ret .= "EST";
    }
    return $ret;    
}


sub by_extracted_number
{
    my ($n1,$n2);
    $a =~ /^\d+/;
    $n1 = $&;
    $b =~ /^\d+/;
    $n2 = $&;
    $n1 <=> $n2;
}
