#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define ERROR -1
#define OK 1
#define MAXSIZE 20

typedef struct Stack{
    char *data;
    int top;
    int stacksize;
}Stack;
// 初始化
int InitStack(Stack *s){
    s->data=(char*)malloc(sizeof(char)*MAXSIZE);
    if(!s->data) return ERROR;
    s->top=0;
    s->stacksize=MAXSIZE;
    return OK;
}
// 入栈
int Push(Stack *s,char ch){
    if(s->top >= s->stacksize) return ERROR;
    s->data[s->top++]=ch;
    return OK;
}
// 出栈
int Pop(Stack *s,char *ch){
    if(s->top==0) return ERROR;
    *ch=s->data[--s->top];
    return OK;
}
// 销毁栈
int Destroy(Stack *s){
    free(s->data);
    s->data=NULL;
    s->stacksize=s->top=0;
    return OK;
}

void Judge(char *ch){
    int flag=0;
    Stack s;
    InitStack(&s);
    int n=strlen(ch);
    for(int i=0;i<n/2;i++){
        Push(&s,ch[i]);
    }
    char e;
    for(int j=0;j<n/2;j++){
        Pop(&s,&e);
        if(e!=ch[n-j-1]){
            flag=1;
            break;
        }
    }
    if(flag==0){
        printf("是回文\n");
    }
    else{
        printf("不是回文\n");
    }
    Destroy(&s);
}

int main(void)
{
    Judge("abba");
    Judge("abcba");
    Judge("abcd");
    Judge("a");
    return 0;
}
