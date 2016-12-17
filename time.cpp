#include <stdio.h>
#include <time.h>

void my_function();

int main()
{
    clock_t c0, c1;
    time_t t0, t1;

    t0 = time(NULL);
    c0 = clock();

    my_function();

    t1 = time(NULL);
    c1 = clock();

    printf("wall clock time: %ld\n", (long) (t1 - t0));
    printf("CPU time: %f\n", (float) (c1 - c0) / CLOCKS_PER_SEC);

    return 0;
}

void my_function()
{
    for(int i=0;i<10000000000;i++);
}
