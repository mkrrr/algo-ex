
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void *myMalloc(size_t size)
{
}

void myFree(void *mem)
{
}

void checkLeak()
{
}

void checkCorrupt()
{
}

int main(int argc, char * argv[])
{
    char *buf = myMalloc(1024);
    buf = myMalloc(128);
    buf = myMalloc(256);
    buf = myMalloc(512);
    buf = myMalloc(64);
    buf = myMalloc(8);
    myFree(buf);
    checkLeak();
    checkCorrupt();
}
