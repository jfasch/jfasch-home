ADD_EXECUTABLE(dynmem-tests dynmem-tests.cc)
TARGET_LINK_LIBRARIES(dynmem-tests GTest::Main)

ADD_EXECUTABLE(ownership-ctor-dtor ownership-ctor-dtor.cc)
ADD_EXECUTABLE(string-demo string-demo.cc)

