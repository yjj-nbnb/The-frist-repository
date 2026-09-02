#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define MAXNUM 100
#define ERROR -1

int Maxcofa(int x,int y){
    int a=abs(x);
    int b=abs(y);
    int c;
    while(b!=0){
        c=a%b;
        a=b;
        b=c;
    }
    return a;
}


int main(){
    printf("请输入你想求最大公因数的一组数:\n");
    int *p=(int*)malloc(sizeof(int)*MAXNUM);
    if(p==NULL){
        printf("内存分配失败\n");
        return ERROR;
    }
    int counter=0;
    int res;
    while(scanf("%d",&p[counter])!=EOF){
        counter++;
        if(counter>=MAXNUM){
            free(p);
            printf("输入的数太多了\n");
            return ERROR;
        }
    }
    if(counter<=1){
        printf("输入过少或没有输入\n");
        free(p);
        return ERROR;
    }
    res=p[0];
    for(int i=0;i<counter;i++){
        res=Maxcofa(res,p[i]);
        if(res==1) break;
    }
    printf("最大公因数为%d",res);
    free(p);
    return 0;
}