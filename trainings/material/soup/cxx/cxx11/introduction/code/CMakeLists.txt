ADD_EXECUTABLE(c++-intro-overview c++-intro-overview.cpp)
TARGET_LINK_LIBRARIES(c++-intro-overview Threads::Threads)


ADD_EXECUTABLE(c++-intro-010-c++03-version c++-intro-010-c++03-version.cpp)
TARGET_LINK_LIBRARIES(c++-intro-010-c++03-version Threads::Threads)

ADD_EXECUTABLE(c++-intro-020-brace-initialization c++-intro-020-brace-initialization.cpp)
TARGET_LINK_LIBRARIES(c++-intro-020-brace-initialization Threads::Threads)

ADD_EXECUTABLE(c++-intro-030-auto-iterator c++-intro-030-auto-iterator.cpp)
TARGET_LINK_LIBRARIES(c++-intro-030-auto-iterator Threads::Threads)

ADD_EXECUTABLE(c++-intro-040-auto-pair c++-intro-040-auto-pair.cpp)
TARGET_LINK_LIBRARIES(c++-intro-040-auto-pair Threads::Threads)

ADD_EXECUTABLE(c++-intro-050-const-auto-ref-pair c++-intro-050-const-auto-ref-pair.cpp)
TARGET_LINK_LIBRARIES(c++-intro-050-const-auto-ref-pair Threads::Threads)

ADD_EXECUTABLE(c++-intro-060-range-based-for-pair c++-intro-060-range-based-for-pair.cpp)
TARGET_LINK_LIBRARIES(c++-intro-060-range-based-for-pair Threads::Threads)

ADD_EXECUTABLE(c++-intro-070-range-based-for-tuple-unpack c++-intro-070-range-based-for-tuple-unpack.cpp)
TARGET_LINK_LIBRARIES(c++-intro-070-range-based-for-tuple-unpack Threads::Threads)

ADD_EXECUTABLE(c++-intro-080-real-functions c++-intro-080-real-functions.cpp)
TARGET_LINK_LIBRARIES(c++-intro-080-real-functions Threads::Threads)

ADD_EXECUTABLE(c++-intro-090-std-function c++-intro-090-std-function.cpp)
TARGET_LINK_LIBRARIES(c++-intro-090-std-function Threads::Threads)

ADD_EXECUTABLE(c++-intro-100-lambda c++-intro-100-lambda.cpp)
TARGET_LINK_LIBRARIES(c++-intro-100-lambda Threads::Threads)

ADD_EXECUTABLE(c++-intro-110-threads c++-intro-110-threads.cpp)
TARGET_LINK_LIBRARIES(c++-intro-110-threads Threads::Threads)

ADD_EXECUTABLE(c++-intro-120-variant c++-intro-120-variant.cpp)
TARGET_LINK_LIBRARIES(c++-intro-120-variant Threads::Threads)
# upgrade to gcc 15.1.1:
# /usr/include/c++/15/bits/shared_ptr_base.h:1068:13: error: ‘((std::__shared_count<__gnu_cxx::_S_atomic>*)<unknown>)[9].std::__shared_count<>::_M_pi’ may be used uninitialized [-Werror=maybe-uninitialized]
#  1068 |         if (_M_pi != nullptr)
#       |             ^~~~~
# /usr/include/c++/15/bits/std_function.h:245:11: warning: ‘((std::_Function_base*)((char*)<unknown> + 16))[2].std::_Function_base::_M_manager’ may be used uninitialized [-Wmaybe-uninitialized]
#   245 |       if (_M_manager)
#       |           ^~~~~~~~~~
target_compile_options(c++-intro-120-variant PRIVATE "-Wno-maybe-uninitialized")

ADD_EXECUTABLE(c++-intro-130-class-nocopy c++-intro-130-class-nocopy.cpp)
TARGET_LINK_LIBRARIES(c++-intro-130-class-nocopy Threads::Threads)

ADD_EXECUTABLE(c++-intro-140-final c++-intro-140-final.cpp)
TARGET_LINK_LIBRARIES(c++-intro-140-final Threads::Threads)

ADD_EXECUTABLE(c++-intro-150-initializer-list c++-intro-150-initializer-list.cpp)
TARGET_LINK_LIBRARIES(c++-intro-150-initializer-list Threads::Threads)




