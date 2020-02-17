#include<stdio.h>
#include<stdlib.h>
typedef struct stack
{
  int data;
  struct stack *next;
}stack;
void push(stack **head,int dataa)
{
  stack *new_node=(stack *)malloc(sizeof(stack));
  new_node->data=dataa;
  new_node->next=*head;
  *head=new_node;
}
void pop(stack **head)
{
  stack *temp=*head;
  *head=(*head)->next;
  free(temp);
}
int peek(stack *head)
{
  return head->data;
}
int isEmpty(stack *head)
{
  if(head==NULL)
     return 1;
  return 0;
}
int main()
{
  printf("Enter postfix expression to evaluate:");
  char *s=(char *)malloc(sizeof(char)*100);
  scanf("%s",s);
  int i=0;
  stack *head=NULL;
  while(s[i]!='\0')
  {
    if(s[i]>='0'&&s[i]<='9')
    {
      push(&head,s[i]-'0');
    }
    else
    {
      int a,b;
      if(!isEmpty(head))
      {
        a=peek(head);
        pop(&head);
        if(!isEmpty(head))
        {
          b=peek(head);
          pop(&head);
        }
        else
        {
          printf("Expression is not valid");
          return 0;
        }
      }
      else
      {
        printf("Expression is not valid");
        return 0;
      }
      if(s[i]=='+')
      {
        push(&head,a+b);
      }
      if(s[i]=='-')
      {
        push(&head,b-a);
      }
      if(s[i]=='*')
      {
        push(&head,a*b);
      }
      if(s[i]=='/')
      {
        push(&head,b/a);
      }
    }
    i++;
  }
  int res=peek(head);
  pop(&head);
  if(!isEmpty(head))
  {
    printf("Expression is not valid");
    return 0;
  }
  else
  {
    printf("Result is %d",res);
  }
  return 0;
}
