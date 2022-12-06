#include "headers.h"

struct msgbuff
{
    long mtype;
    int ID;
    int ArrTime;
    int RunTime;
    int Priority;
};

void recivedinfo(heap_t *list)
{
    
    key_t generator_id;
    int recievep;
    
    
    generator_id=msgget((key_t)1234, 0666 | IPC_CREAT);

   while(1)
    {
        struct msgbuff message2;            
        
        message2.mtype=1;
        int size2=sizeof(message2)-sizeof(message2.mtype);
        printf("%d\n",size2);
        recievep=msgrcv(generator_id,&message2,size2,0,!IPC_NOWAIT);
        if (recievep==-1)
        {
            printf("error to recive\n");
            exit(-1);  
        }
        else
        {
            printf("recieved\n");
            
            process recievedProcess;          // store data from buff in a process

            recievedProcess.ID=message2.ID;
            recievedProcess.ArrTime=message2.ArrTime;
            recievedProcess.Priority=message2.Priority;
            recievedProcess.RunTime=message2.RunTime;

            if(recievedProcess.ID==0)         // when it stops
            {
                break;
            }
            push(list,recievedProcess.ArrTime,&recievedProcess);
           
        }
    }
    //msgctl(generator_id, IPC_RMID, (struct msqid_ds *) 0);
}


int main(int argc, char * argv[])
{
//     initClk();
    
//     //TODO implement the scheduler :)
//     //upon termination release the clock resources
    
//     destroyClk(true);
}
