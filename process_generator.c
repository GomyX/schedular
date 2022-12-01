#include "headers.h"

void clearResources(int);

struct process{
        int id , arrival, runtime, priority;
};

void read_ints (const char* file_name)
{
  FILE* file = fopen (file_name, "r");
  struct process p;

  fscanf (file, "%d %d %d %d", &p.id, &p.arrival, &p.runtime, &p.priority);    
  while (!feof (file))
    {  
      printf ("ID: %d \t arrival: %d \t runtime: %d \t priority: %d \n",p.id,p.arrival, p.runtime, p.priority);
      fscanf (file, "%d %d %d %d", &p.id, &p.arrival, &p.runtime, &p.priority);     
    }
  fclose (file);        
}

int main(int argc, char * argv[])
{
    signal(SIGINT, clearResources);
    // TODO Initialization
    // 1. Read the input files.             omarayyad 

    read_ints("test.txt");
    // 2. Ask the user for the chosen scheduling algorithm and its parameters, if there are any.   //printf ("enter the algorithim you want    1)jfs   2)sfst   3)jfkdkjf") scanf (int n =1 2 3 )   thabet&saber
    // 3. Initiate and create the scheduler and clock processes.                   s= scedular (n)   thabet&saber
    // 4. Use this function after creating the clock process to initialize clock    thabet&saber
    initClk();
    // To get time use this
    int x = getClk();
    printf("current time is %d\n", x);
    // TODO Generation Main Loop
    // 5. Create a data structure for processes and provide it with its parameters.         //we will store the processes as STRUCTS in a LinkedList  ayyad &Nasrah
    // 6. Send the information to the scheduler at the appropriate time.                    //function(clk,LinkedList) return processToBeSent         nasrah
    // 7. Clear clock resources
    destroyClk(true);
}

void clearResources(int signum)
{
    //TODO Clears all resources in case of interruption             //Qeestion the TA     //think of as the user sends an interrupt so this interrupt to be handeled
}
