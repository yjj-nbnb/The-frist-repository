#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 100

typedef struct Stack{
    int *top;
    int *base;
    int stacksize;
}Stack;
// 初始化
int InitStack(Stack *s){
    s->base=(int*)malloc(sizeof(int)*MAXSIZE);
    if(!s->base) return -1;
    s->top=s->base;
    s->stacksize=MAXSIZE;
    return 1;    
}
// 入栈
int Push(Stack *s,int e){
    // 栈满
    if(s->top-s->base==s->stacksize) return -1;
    // 正常
    *s->top++=e;
    return 1;
}
// 出栈
int Pop(Stack *s,int *e){
    // 栈空
    if(s->top==s->base) return -1;
    // 正常
    *e=*--s->top;
    return 1;
}
// 取栈顶元素
int GetTop(Stack s){
    // 栈不空
    if(s.top!=s.base){
        return *(s.top-1);
    }
    return -1;
}
// 测试用例
int main(){
    Stack s;
    InitStack(&s);
    Push(&s,2);
    Push(&s,3);
    Push(&s,4);
    int r=GetTop(s);
    printf("%d\n",r);
    int c;
    Pop(&s,&c);
    r=GetTop(s);
    printf("%d\n",r);
    free(s.base);
    return 0;
}


