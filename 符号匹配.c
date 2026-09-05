#include<stdio.h>
#include<stdlib.h>
#define OK 1
#define true 1
#define false 0
#define ERROR -1
#define MAXSIZE 100

typedef struct Stack{
    char *base;
    char *top;
    int stacksize;
}Stack;

// 初始化
int InitStack(Stack *s){
    s->base=(char*)malloc(sizeof(char)*MAXSIZE);
    if(!s->base) return ERROR;
    s->top=s->base;
    s->stacksize=MAXSIZE;
    return OK;
}

// 入栈
int Push(Stack *s,char e){
    if(s->top-s->base==s->stacksize) return ERROR;
    *s->top++=e;
    return OK;
}

// 出栈
int Pop(Stack *s,char *e){
    if(s->base==s->top) return ERROR;
    *e=*(--s->top);
    return OK;
}

// 取栈顶元素
int GetTop(Stack *s,char *e){
    if(s->base==s->top) return ERROR;
    *e=*(s->top-1);
    return OK;
}

// 销毁栈
int Destroy(Stack *s){
    free(s->base);
    s->base=s->top=NULL;
    return OK;
}

// 是否为空
int StackEmpty(Stack *s){
    if(s->base==s->top) return true;
    return false;
}

int main(){
    Stack s;
    InitStack(&s);
    int flag=1;
    char ch;
    char e,r;
    scanf("%c",&ch);
    while(ch!='#' && flag){
        switch (ch)
        {
        case '[':
        case '(':
            Push(&s,ch);
            break;
        case ')':
            if(!StackEmpty(&s)){
                GetTop(&s,&e);
                if(e=='('){
                    Pop(&s,&r);
                }
                else{
                    flag=0;
                }
            }
            else{
                flag=0;
            }
            break;
        case ']':
           if(!StackEmpty(&s)){
                GetTop(&s,&e);
                if(e=='['){
                    Pop(&s,&r);
                }
                else{
                    flag=0;
                }
            }
            else{
                flag=0;
            }
            break;
        }
        scanf("%c",&ch);
    }
    if(StackEmpty(&s) && flag) return true;
    else return false;
}