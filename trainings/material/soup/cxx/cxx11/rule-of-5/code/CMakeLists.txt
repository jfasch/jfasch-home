add_executable(c++11-rule5-rule-of-zero-string rule-of-zero-string.cpp)
add_executable(c++11-rule5-rule-of-zero-unique-ptr rule-of-zero-unique-ptr.cpp)
add_executable(c++11-rule5-rule-of-three-handwritten-string-wrong rule-of-three-handwritten-string-wrong.cpp)
add_executable(c++11-rule5-rule-of-three-handwritten-string-almost-right rule-of-three-handwritten-string-almost-right.cpp)
add_executable(c++11-rule5-rule-of-three-handwritten-string-right rule-of-three-handwritten-string-right.cpp)
add_executable(c++11-rule5-rule-of-five-handwritten-string-move-missing rule-of-five-handwritten-string-move-missing.cpp)
add_executable(c++11-rule5-rule-of-five-handwritten-string-move rule-of-five-handwritten-string-move.cpp)
target_compile_options(c++11-rule5-rule-of-five-handwritten-string-move PRIVATE -Wno-self-move)

add_executable(c++11-rule5-move-only-timerfd move-only-timerfd.cpp)


