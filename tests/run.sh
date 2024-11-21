#!/bin/bash

## Return Code Method Tests
returntests=$(find tests/src/ -type f -exec basename "{}" .c \; | grep "_return")

for returntest in $returntests
do
	testbin=$returntest; printf "Running test %s" $testbin; ./tests/bin/$testbin; res=$?; ./tests/bin/expc_$testbin; expc=$?; if [ $res -ne $expc ]; then printf "%s: [FAILED]: expected return %d: was: %d\n" $testbin $expc $res; else printf "[OK]\n"; fi
done

## Diff Method Tests
difftests=$(find tests/src/ -type f -exec basename "{}" .c \; | grep "test_diff")

for difftest in $difftests
do
	testbin=$difftest; printf "Running test: %s: " $testbin; ./tests/bin/$testbin 1> tests/out/$testbin.stdout; ./tests/bin/expc_$testbin 1> tests/out/expc_$testbin.stdout ; diff tests/out/expc_$testbin.stdout tests/out/$testbin.stdout; res=$?; expc=0; if [ $res -ne $expc ]; then printf "%s: [FAILED]: expected return %d: was: %d\n" $testbin $expc $res; else printf "[OK]\n"; fi
done
