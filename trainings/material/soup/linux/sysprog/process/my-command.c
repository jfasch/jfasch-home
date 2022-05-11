#include <stdio.h>   // printf, fprintf, stderr


int main(int argc, char** argv)
{
    const char* command;
    const char* param1;
    const char* param2;

    if (argc != 3) {
        fprintf(stderr, "%s: requires 2 parameters\n", argv[0]);
        return 1;
    }

    command = argv[0];
    param1 = argv[1];
    param2 = argv[2];

    printf("Command: %s\n", command);
    printf("Parameter 1: %s\n", param1);
    printf("Parameter 2: %s\n", param2);

    return 0;
}
