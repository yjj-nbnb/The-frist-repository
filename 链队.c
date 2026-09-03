#include<stdio.h>
#include<stdlib.h>
#define OK 1
#define ERROR -1

typedef struct Qnode{
    int data;
    struct Qnode *next;
}Qnode,*Pqnode;

typedef struct{
    Pqnode front;
    Pqnode rear;
}LinkQueue;

// 初始化
int InitQueue(LinkQueue *q){
    q->front=q->rear=(Pqnode)malloc(sizeof(Qnode));
    if(!q->front) return ERROR;
    q->front->next=NULL;
    return OK;
}

// 入队
int EnQueue(LinkQueue *q,int e){
    Pqnode pnew=(Pqnode)malloc(sizeof(Qnode));
    if(!pnew) return ERROR;
    pnew->data=e;
    pnew->next=NULL;
    q->rear->next=pnew;
    q->rear=pnew;
    return OK;
}

// 出队
int DeQueue(LinkQueue *q,int *e){
    if(q->front==q->rear) return ERROR;
    Pqnode p=q->front->next;
    *e=p->data;
    q->front->next=p->next;
    if(p==q->rear) q->rear=q->front;
    free(p);
    return OK;
}

// 取队头元素
int GetHead(LinkQueue *q){
    if(q->front==q->rear) return ERROR;
    return q->front->next->data;
}

// 销毁
int Destroy(LinkQueue *q){
    Pqnode cur,next;
    cur=q->front;
    while(cur!=NULL){
        next=cur->next;
        free(cur);
        cur=next;
    }
    q->front=q->rear=NULL;
    return OK;
}
// 测试用例
int main(){
    LinkQueue q;
    InitQueue(&q);
    EnQueue(&q,100);
    EnQueue(&q,200);
    EnQueue(&q,300);
    int r=GetHead(&q);
    printf("当前队头%d\n",r);
    int e;
    DeQueue(&q,&e);
    printf("删除了%d\n",e);
    DeQueue(&q,&e);
    r=GetHead(&q);
    printf("当前队头%d",r);
    Destroy(&q);
    return 0;
}
