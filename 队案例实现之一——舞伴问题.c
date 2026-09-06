#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#define MAXSIZE 100
#define OK 1
#define ERROR -1
#define true 1
#define false 0

typedef struct {
    char name[20];
    char sex;
}Person;

typedef struct Queue{
    Person *data;
    int front;
    int rear;
}Queue;

// 初始化
int InitQueue(Queue *q){
    q->data=(Person*)malloc(sizeof(Person)*MAXSIZE);
    if(!q->data) return ERROR;
    q->front=q->rear=0;
    return OK;
}

// 入队
int EnQueue(Queue *q,Person p){
    if(q->rear==MAXSIZE) return ERROR;
    if(strlen(p.name)>20) return ERROR;
    q->data[q->rear]=p;
    q->rear++;
    return OK;
}

// 出队
int DeQueue(Queue *q,Person *p){
    if(q->front==q->rear) return ERROR;
    *p=q->data[q->front];
    q->front++;
    return OK;
}

// 判空
int QueueEmpty(Queue *q){
    if(q->front==q->rear) return true;
    return false;
}

// 销毁队
int Destroy(Queue *q){
    free(q->data);
    q->data=NULL;
    q->front=q->rear=0;
    return OK;
}

// 取队头
int GetHead(Queue *q,Person *p){
    if(q->rear==q->front) return ERROR;
    *p=q->data[q->front];
    return OK;
}

void DancePartner(Person dancer[],int num){
    Queue Md;
    Queue Fd;
    InitQueue(&Md);
    InitQueue(&Fd);

    for(int i=0;i<num;i++){
        Person p=dancer[i];
        if(p.sex=='F') EnQueue(&Fd,p);
        else EnQueue(&Md,p);
    }

    while (!QueueEmpty(&Fd) && !QueueEmpty(&Md))
    {   
        Person p;
        DeQueue(&Fd,&p);
        printf("%s ",p.name);
        DeQueue(&Md,&p);
        printf("%s\n",p.name);
    }
     
    if(!QueueEmpty(&Fd)){
        Person p;
        GetHead(&Fd,&p);
        printf("%s",p.name);
    }
    else if(!QueueEmpty(&Md)){
        Person p;
        GetHead(&Md,&p);
        printf("%s",p.name);
    }
    Destroy(&Fd);
    Destroy(&Md);
}

// 测试用例
int main(){
    Person people[]={
        {"小红",'F'},
        {"小蓝",'F'},
        {"张三",'M'},
        {"李四",'M'},
        {"王五",'M'}
    };
    int n = sizeof(people)/sizeof(people[0]);
    DancePartner(people,n);
    return 0;
}
