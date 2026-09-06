#include<stdio.h>
#include<stdlib.h>
#define OK 1
#define ERROR -1
#define true 1
#define false 0
#define MAXSIZE 100

typedef struct{
    int top[2],bot[2];
    int *data;
    int m;
}DbStack;
// 初始化
int InitStack(DbStack *s){
    s->data=(int*)malloc(sizeof(int)*MAXSIZE);
    if(!s->data) return ERROR;
    s->m=MAXSIZE;
    s->top[0]=s->bot[0]=-1;
    s->top[1]=s->bot[1]=s->m;
    return OK;
}
// 判断栈空
int StackEmpty(DbStack *s){
    if(s->top[0]==-1 && s->top[1]==s->m) return true;
    return false;
}
// 判断栈满
int StackFull(DbStack *s){
    if(s->top[0]+1 >=s->top[1]) return true;
    return false;
}
// 左进栈
int EnLeftStack(DbStack *s,int e){
    if(!StackFull(s)){
        s->data[++s->top[0]]=e;
        return OK;
    }
    return ERROR;
}
// 右进栈
int EnRightStack(DbStack *s,int e){
    if(!StackFull(s)){
        s->data[--s->top[1]]=e;
        return OK;
    }
    return ERROR;
}
// 左出栈
int DeLeftStack(DbStack *s,int *e){
    if(s->top[0]==-1) return ERROR;
    *e=s->data[s->top[0]--];
    return OK;
}
// 右出栈
int DeRightStack(DbStack *s,int *e){
    if(s->top[1]==s->m) return ERROR;
    *e=s->data[s->top[1]++];
    return OK;
}
// 销毁栈
int Destroy(DbStack *s){
    free(s->data);
    s->data=NULL;
    s->top[0]=s->bot[0]=-1;
    s->top[1]=s->bot[1]=0;
    s->m=0;
    return OK;
}