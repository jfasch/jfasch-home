set(ENV{SOME_VARIABLE} "value")
execute_process(COMMAND sh "-c" "echo child: SOME_VARIABLE=\$SOME_VARIABLE")
