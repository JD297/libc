#!/bin/bash

##	Return Code Method Tests

###	Test return from main()
testbin=test_00001_return_0; ./tests/bin/$testbin; res=$?; ./tests/bin/expc_$testbin; expc=$?; if [ $res -ne $expc ]; then printf "%s: [FAILED]: expected return %d: was: %d\n" $testbin $expc $res; fi
testbin=test_00002_return_7; ./tests/bin/$testbin; res=$?; ./tests/bin/expc_$testbin; expc=$?; if [ $res -ne $expc ]; then printf "%s: [FAILED]: expected return %d: was: %d\n" $testbin $expc $res; fi
testbin=test_00003_return_-1; ./tests/bin/$testbin; res=$?; ./tests/bin/expc_$testbin; expc=$?; if [ $res -ne $expc ]; then printf "%s: [FAILED]: expected return %d: was: %d\n" $testbin $expc $res; fi

###	Test string.h

####	Test strcmp()
testbin=test_00004_return_string_strcmp_1; ./tests/bin/$testbin; res=$?; ./tests/bin/expc_$testbin; expc=$?; if [ $res -ne $expc ]; then printf "%s: [FAILED]: expected return %d: was: %d\n" $testbin $expc $res; fi
testbin=test_00005_return_string_strcmp_2; ./tests/bin/$testbin; res=$?; ./tests/bin/expc_$testbin; expc=$?; if [ $res -ne $expc ]; then printf "%s: [FAILED]: expected return %d: was: %d\n" $testbin $expc $res; fi
testbin=test_00006_return_string_strcmp_3; ./tests/bin/$testbin; res=$?; ./tests/bin/expc_$testbin; expc=$?; if [ $res -ne $expc ]; then printf "%s: [FAILED]: expected return %d: was: %d\n" $testbin $expc $res; fi

####	Test strlen()
testbin=test_00007_return_string_strlen_1; ./tests/bin/$testbin; res=$?; ./tests/bin/expc_$testbin; expc=$?; if [ $res -ne $expc ]; then printf "%s: [FAILED]: expected return %d: was: %d\n" $testbin $expc $res; fi
testbin=test_00008_return_string_strlen_2; ./tests/bin/$testbin; res=$?; ./tests/bin/expc_$testbin; expc=$?; if [ $res -ne $expc ]; then printf "%s: [FAILED]: expected return %d: was: %d\n" $testbin $expc $res; fi
