add_test([=[TreeTest.Sum]=]  /home/ramon/ramon/alg-fabbri-IPRJ-UERJ/alg/graph/tests/run-graph-tests [==[--gtest_filter=TreeTest.Sum]==] --gtest_also_run_disabled_tests)
set_tests_properties([=[TreeTest.Sum]=]  PROPERTIES WORKING_DIRECTORY /home/ramon/ramon/alg-fabbri-IPRJ-UERJ/alg/graph/tests SKIP_REGULAR_EXPRESSION [==[\[  SKIPPED \]]==])
set(  run-graph-tests_TESTS TreeTest.Sum)
