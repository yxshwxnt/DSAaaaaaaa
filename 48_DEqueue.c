#include<stdio.h>
#include<stdlib.h>
 
struct queue
{
    int size;
    int f;
    int r;
    int* arr;
};
 
 
int isEmpty(struct queue *q){
    if(q->r==q->f){
        return 1;
    }
    return 0;
}
 
int isFull(struct queue *q){
    if(q->r==q->size-1){
        return 1;
    }
    return 0;
}
 
void enqueueR(struct queue *q, int val){
    if(isFull(q)){
        printf("This Queue is full\n");
    }
    else{
        q->r++;
        q->arr[q->r] = val;
        printf("Enqued element: %d\n", val);
    }
} 

void enqueueF(struct queue *q,int val){ 
    if(q->f==-1){ 
        printf("Cannot add element\n"); 
    }
    else{ 
        q->f--; 
        q->arr[q->f]=val; 
        printf("Enqued element: %d\n", val);
    }
}
 
int dequeueF(struct queue *q){
    int a = -1;
    if(isEmpty(q)){
        printf("This Queue is empty\n");
    }
    else{
        q->f++;
        a = q->arr[q->f]; 
    }
    return a;
} 

int dequeueR(struct queue *q){ 
    int a=-1; 
    if(isEmpty(q)){ 
        printf("This Queue is empty\n");
    }
    else{ 
        q->r--; 
        a=q->arr[q->r]; 
    }
    return a; 
}
 
int main(){
    struct queue q;
    q.size = 4;
    q.f = q.r = -1;
    q.arr = (int*) malloc(q.size*sizeof(int));
    
    // Enqueue few elements
    enqueueR(&q, 12);
    enqueueR(&q, 15);
    enqueueR(&q, 1); 
    printf("Dequeuing element %d\n", dequeueF(&q));
    printf("Dequeuing element %d\n", dequeueF(&q));
    printf("Dequeuing element %d\n", dequeueF(&q)); 
    enqueueR(&q, 45);
    enqueueR(&q, 45);
    enqueueR(&q, 45);
 
    return 0;
}
