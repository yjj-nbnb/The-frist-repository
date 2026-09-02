#include<stdio.h>
#include<stdlib.h>

typedef struct StackNode{
    int data;
    struct StackNode *next;
}StackNode,*LinkStack;

// 初始化
int InitStack(LinkStack *s){
    *s=NULL;
    return 1;
}
// 入栈
int Push(LinkStack *s,int e){
    LinkStack newstack=(LinkStack)malloc(sizeof(StackNode));
    if(!newstack) return -1;
    newstack->data=e;
    newstack->next=*s;
    *s=newstack;
    return 1;
}
// 出栈
int Pop(LinkStack *s,int *e){
    if(*s==NULL) return -1;
    *e=(*s)->data;
    LinkStack p=*s;
    (*s)=(*s)->next;
    free(p);
    return 1;
}
// 取栈顶元素
int GetTop(LinkStack s){
    if(s!=NULL){
        return s->data;
    }
    return -1;
}
// 测试用例
int main(){
    LinkStack s;
    InitStack(&s);
    Push(&s,20);
    Push(&s,30);
    printf("%d\n",GetTop(s));
    int r;
    Pop(&s,&r);
    printf("%d\n",r);
    printf("%d\n",GetTop(s));
    free(s);
    return 0;
}