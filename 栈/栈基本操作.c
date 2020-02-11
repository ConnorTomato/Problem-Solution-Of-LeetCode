#include<stdio.h>
#include<stdlib.h>
#define MAX_LEN 100
#define CRE 10

//栈的表示
typedef struct Stack{
    int len; //current size
    int *top;//栈顶指针
    int *base;//栈底指针
    int stacksize;//表示栈总共能存多少元素
}stack;

//创建栈
void CreatStack(stack *s){
    //创建栈空间
    s->base = (int *)malloc(MAX_LEN*sizeof(int));
    s->top  = s->base;
    s->len = 0;
    s->stacksize = MAX_LEN;
}

//入栈
void Push(stack *s,int e){
    if(s->top-s->base >= MAX_LEN)//如果溢出则增加内存分配
    {
        s->base = (int*)realloc(s->base,(s->stacksize + CRE)*sizeof(int));
        s->stacksize += CRE;
    }
    *s->top = e;
    s->top++;
}

//出栈
void Pop(stack *s,int *e){
    if(s->base == s->top)
        printf("ERROR!\n");
    else{
        s->top--;
        *e = *s->top;
        s->len--;
    }
}

//获取栈的长度
void Stacklen(stack s){
    printf("The size of stack is %d\n",s.stacksize);
    printf("The current size of stack is %d\n",s.len);
}

int main()
{
    stack s;
    int e;
    int f;
    int n;
    CreatStack(&s);
    printf("Creat Stack  over!\n");
    printf("The numbers:");
    scanf("%d",&n);
    printf("Input All Data:");

    for(int i=0; i<n; i++){
    scanf("%d",&e);
    Push(&s,e);
    }
    printf("Push Over!\n");
    printf("\n");

    printf("Pop Stack:\n");
    printf("\n");

    for(int i=0; i<n; i++){
    Pop(&s,&f);
    printf(" %d\t",f);
    }
    printf("\n");

    printf("Pop Over!\n");
    return 0;
}