#include <stdio.h>
#include <conio.h>
#include <math.h>
#define MAX 20
struct stack
{
int top;
float str[MAX];
}s;//stack
char postfix[MAX];//postfix
void push(float);
float pop();
int isoperand(char);
float operate(float,float,char);
int main()
{
int i=0;
printf("Enter Expression:");
scanf("%s",postfix);
float ans,op1,op2;
while(postfix[i]!='\0')
{
if(isoperand(postfix[i]))
push(postfix[i]-48);
else
{
op1=pop();
op2=pop();
ans=operate(op1,op2,postfix[i]);
push(ans);
printf("%f %c %f = %f\n",op2,postfix[i],op1,ans);
}
i++;
}
printf("%f",s.str[s.top]);
getch();
}
int isoperand(char x)
{
if(x>='0' && x<='9')
return 1;
else return 0;
}
void push(float x)
{
if(s.top==MAX-1)
printf("Stack is full\nStack overflow\n");
else
{
s.top++;
s.str[s.top]=x;
}
}
float pop()
{
if(s.top==-1)
{
printf("Stack is emplty\nSTACK UNDERFLOW\n");
getch();
}
else
{
s.top--;
return s.str[s.top+1];
}
}
float operate(float op1,float op2,char a)
{
switch(a)
{
case '+' : return op2+op1;
case '-' : return op2-op1;
case '*' : return op2*op1;
case '/' : return op2/op1;
case '^' : return pow(op2,op1);
}
}