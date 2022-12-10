#include "headers.h"

/* Modify this file as needed*/
int remainingtime;
int runningtime;
int start_time;
int finish_time;
int main(int agrc, char * argv[])
{
    initClk();
    remainingtime = atoi(argv[1]);
    runningtime = atoi(argv[1]);
    start_time = getClk();

    while (remainingtime > 0)
    {
        remainingtime = runningtime - (getClk()-start_time);
    }
     

    finish_time = getClk();
    //destroyClk(false);
    exit(getpid());
    
    return 0;
}
