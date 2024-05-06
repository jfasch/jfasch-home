ADD_EXECUTABLE(example-O_RDONLY example-O_RDONLY.c)
ADD_EXECUTABLE(example-O_WRONLY example-O_WRONLY.c)
ADD_EXECUTABLE(example-O_CREAT-bogus example-O_CREAT-bogus.c)
ADD_EXECUTABLE(example-O_CREAT example-O_CREAT.c)
ADD_EXECUTABLE(example-O_EXCL example-O_EXCL.c)

ADD_SUBDIRECTORY(basics-exercise-copy)
