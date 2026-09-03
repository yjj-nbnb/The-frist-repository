#include<stdio.h>
#include<stdlib.h>
#define OK 1
#define ERROR -1
#define true 1
#define false 0
#define MAXSIZE 100

typedef struct stack{
    int *top;
    int *base;
    int stacksize;
}stack;

// 初始化
int InitStack(stack *s){
    s->base=(int*)malloc(sizeof(int)*MAXSIZE);
    if(!s->base) return ERROR;
    s->top=s->base;
    s->stacksize=MAXSIZE;
    return OK;
}

// 入栈
int Push(stack *s,int e){
    if(s->top-s->base==MAXSIZE) return ERROR;
    *s->top++=e;
    return OK;
}

// 出栈
int Pop(stack *s,int *e){
    if(s->base==s->top) return ERROR;
    *e=*--s->top;
    return OK;
}

// 取栈顶元素
int GetTop(stack *s){
    if(s->base!=s->top){
        return *(s->top-1);
    }
    return ERROR;
}

// 销毁
int Destroy(stack *s){
    if(s->base!=NULL){
        free(s->base);
        s->base=NULL;
    }
    s->top=NULL;
    return OK;
}
// 是否为空
int StackEmpty(stack *s){
    if(s->base==s->top) return true;
    return false;
}

int main(){
    int N;
    int e;
    stack s;
    InitStack(&s);
    scanf("%d",&N);
    while(N){
        Push(&s,N%8);
        N=N/8;
    }
    while(!StackEmpty(&s)){
        Pop(&s,&e);
        printf("%d",e);
    }
    return 0;
}