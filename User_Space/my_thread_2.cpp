#include <iostream>
#include <unistd.h>
#include "my_thread_2.hpp"


void* my_thread_2(void*)
{
        int *p; int a=10;
        p = &a;
        printf("My thread function_1 \n");
        return (void*) p;
}
