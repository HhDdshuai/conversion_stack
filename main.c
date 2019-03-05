#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#define MaxSize 100001
typedef int elem_type;

typedef struct{
    elem_type data[MaxSize];
    int top;
}SqStack;
//��ʼ��ջ
void InitStack(SqStack *S){
    S->top = -1;
}
//ջ�п�
int IsEmpty(SqStack *S){
    if(S->top == -1)
        return 1;
    else
        return 0;
}
//ѹջ
void  Push(SqStack *S,elem_type x){
    if(S->top == MaxSize - 1){
        printf("Stack full.\n");
        //return;
    }else
        S->data[++S->top] = x;
}
//ȡջ��Ԫ��
void getTop(SqStack *S){
    elem_type x;
    if(IsEmpty(S))
        printf("Stack empty.\n");
    else{
        x = S->data[S->top];
        printf("%d\n",x);
    }
}
//��ջ
elem_type Pop(SqStack *S){
    elem_type x;
    if(IsEmpty(S)){
        printf("Stack Empty.");
        return NULL;
    }
    else{
        x = S->data[S->top--];
        return x;
    }
}
//ջ���
void Clear_Stack(SqStack *S){
    S->top = -1;
}
//����ת�� ʮ -> *����
int Conversion(int a,int res[],SqStack *S,int num_s){
    int i = 0;
    for(;a > 0;a /= num_s){
        Push(S,a % num_s);
    }
    while(!IsEmpty(S)){
        res[i++] = Pop(S);
    }
    return i;
}
int main()
{
    int a,res[MaxSize];
    char str[31];
    int i = 0,j,len;
    SqStack *S;
    S = (SqStack *)malloc(sizeof(SqStack));
    InitStack(S);
    scanf("%d",&a);
    len=Conversion(a,res,S,2);

    //printf("%d",len);
    for(;i < len;i++)
        printf("%d",res[i]);

    return 0;
}
