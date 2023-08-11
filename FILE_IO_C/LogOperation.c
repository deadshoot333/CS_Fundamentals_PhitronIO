#include<stdio.h>
#include<time.h>

int main()
{
    clock_t t;
    t=clock();
    FILE *logFile=fopen("log.txt","a");
    for(int i=0;i<10000;i++)
    {

    }
    t=clock()-t;
    double  timeTaken=((double)t)/CLOCKS_PER_SEC;
    fprintf(logFile,"Programme time executed at %f\n",timeTaken);
    return 0;
}