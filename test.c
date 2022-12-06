#include "pq.h"

int main()
{
    
    heap_t *list = (heap_t *)calloc(1, sizeof(heap_t)); ;
    process p1,p2,p3;
    p1.ID=1;
    p1.ArrTime=3;
    p1.RunTime=10;
    p1.Priority=5;
    p2.ID=2;
    p2.ArrTime=4;
    p2.RunTime=5;
    p2.Priority=2;
    p3.ID=3;
    p3.ArrTime=7;
    p3.RunTime=10;
    p3.Priority=3;
    push(list,p1.Priority,&p1);
    push(list,p2.Priority,&p2);
    push(list,p3.Priority,&p3);
    while(top(list)!=NULL){
        process *puff;
        puff=pop(list);
        printf("Process %d is out\n",puff->ID);
    }
    printf("List is empty now!!\nd");
    return 0;
}
