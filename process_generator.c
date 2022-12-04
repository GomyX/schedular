#include "headers.h"

void clearResources(int);



void read_ints (const char* file_name)
{
  FILE* file = fopen (file_name, "r");
  process p[10];
  //struct List process_list;
  heap_t *list = (heap_t *)calloc(1, sizeof(heap_t));
  
  
 
  
  for (int i = 0; i < 100; i++){
    if (!feof (file)){
      fscanf (file, "%d %d %d %d", &p[i].ID, &p[i].ArrTime, &p[i].RunTime, &p[i].Priority);
      //printf ("ID: %d \t arrival: %d \t runtime: %d \t priority: %d \n",p[i].id,p[i].arrival, p[i].runtime, p[i].priority);
      //struct MNode x= p[i];
      //ins(process_list, NULL,x);
      push(list,p[i].ArrTime,&p[i]);
      
    }

  }
  while(top(list)!=NULL){  //test read & data structure
        process *puff;
        puff=pop(list);
        printf("Process %d is out\n",puff->ID);
    }
  
  fclose (file);        
}

struct msgbuff  // buffer to store process in
{
    long mtype;
    int ID;
    int ArrTime;
    int RunTime;
    int Priority;
};


void sendinfo(int clk, heap_t *list)
{
    struct msgbuff message;
    key_t generator_id;
    int sendp;
    int recievep;


   generator_id=msgget((key_t)1234, 0666 | IPC_CREAT);

   while(top(list)!=NULL)
    {
       if(top(list)->ArrTime<=clk)   
        {
           process *sendProcess;
            sendProcess=pop(list);             //copying data of process to buffer

            message.ID=sendProcess->ID;
            message.ArrTime=sendProcess->ArrTime;
            message.Priority=sendProcess->Priority;
            message.RunTime=sendProcess->RunTime;
            
            message.mtype=1;

            int size=sizeof(message)-sizeof(message.mtype);
            printf("%d\n",size);
            sendp=msgsnd(generator_id,&message,size,!IPC_NOWAIT);

            if(sendp==-1)         //ckeckers
            {
                printf("error to send\n");
                exit(-1);
            }
            else
            {
                printf("message send\n"); 
                 
            }

        }
    }
    message.ID=0;           //when the reciever should stop, when he find ID=0;
    message.ArrTime=0;
    message.Priority=0;
    message.RunTime=0;

    int size=sizeof(message)-sizeof(message.mtype);
    sendp=msgsnd(generator_id,&message,size,!IPC_NOWAIT);
    if(sendp==-1)
    {
        printf("error to send\n");
        exit(-1);
    }
    else
    {
        printf("message send\n");
            
    }
}


int main(int argc, char * argv[])
{
    int algorithm_num;
    signal(SIGINT, clearResources);
    // TODO Initialization
    // 1. Read the input files.             omarayyad (done)
    read_ints("test.txt");
    // 2. Ask the user for the chosen scheduling algorithm and its parameters, if there are any.   //printf ("enter the algorithim you want    1)jfs   2)sfst   3)jfkdkjf") scanf (int n =1 2 3 )   thabet&saber (done)
    printf("Algorithms: \n 1- Preemptive Highest Priority First (PHPF). \n 2- Shortest Remaining time Next (SRTN). \n 3- Short Job First (SJF). \n");
    printf("Which one whould you choose?\t");
    scanf("%d", &algorithm_num);
    // 3. Initiate and create the scheduler and clock processes.                   s= scedular (n)   thabet&saber
    // 4. Use this function after creating the clock process to initialize clock    thabet&saber
    initClk();
    // To get time use this
    int x = getClk();
    printf("current time is %d\n", x);
    // TODO Generation Main Loop
    // 5. Create a data structure for processes and provide it with its parameters.         //we will store the processes as STRUCTS in a LinkedList  ayyad &Nasrah
    
    // 6. Send the information to the scheduler at the appropriate time.                    //function(clk,LinkedList) return processToBeSent         nasrah
    sendinfo(x,list)
    // 7. Clear clock resources
    destroyClk(true);
}

void clearResources(int signum)
{
    //TODO Clears all resources in case of interruption             //Qeestion the TA     //think of as the user sends an interrupt so this interrupt to be handeled
}
