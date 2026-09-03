#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 10

typedef struct Queue{
    int *data;
    int front;
    int rear;
}Queue;

// 初始化
int InitQueue(Queue *q){
    q->data=(int*)malloc(sizeof(int)*MAXSIZE);
    if(!q->data) return -1;
    q->front=q->rear=0;
    return 1;
}

// 队的长度
int Length(Queue q){
    return (q.rear-q.front+MAXSIZE)%MAXSIZE;
}

// 入队
int EnQueue(Queue *q,int e){
    if((q->rear+1)%MAXSIZE==q->front) return -1;
    q->data[q->rear]=e;
    q->rear=(q->rear+1)%MAXSIZE;
    return 1;
}

// 出队
int DeQueue(Queue *q,int *e){
    if(q->front==q->rear) return -1;
    *e=q->data[q->front];
    q->front=(q->front+1)%MAXSIZE;
    return 1;
}

// 取队头元素
int GetHead(Queue q){
    if(q.front==q.rear){
        return -1;
    }
    return (q.data[q.front]);
}

// 销毁队
int DestroyQueue(Queue *q){
    free(q->data);
    q->data=NULL;
    q->front=q->rear=0;
    return 1;
}

// 测试用例
int main(){
    Queue q;
    InitQueue(&q);
    EnQueue(&q,10);
    EnQueue(&q,20);
    EnQueue(&q,30);
    printf("当前队的长度为%d\n",Length(q));
    int r;
    DeQueue(&q,&r);
    printf("删除了%d\n",r);
    printf("当前队头为%d\n",GetHead(q));
    DestroyQueue(&q);
    return 0;
}