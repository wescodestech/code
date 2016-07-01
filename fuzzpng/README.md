Sample fuzzing libpng 1.6

Sample application to read a png file and attempt
to fuzz it with afl as a learning exercise. Nothing
too fancy has been done yet with this code.

Info on afl-fuzz can be found at http://lcamtuf.coredump.cx/afl/

afl-fuzz does a few checks before running the fuzzer. I set the
following env variables to get afl-fuzz up and running quickly.
More research should be done on these to ensure optimal results
are achieved.

export AFL_I_DONT_CARE_ABOUT_MISSING_CRASHES=1
export AFL_SKIP_CPUFREQ=1

afl-fuzz can wreak havoc on SSDs. To spare your lovely SSDs, you
should create a ramdisk for afl.
