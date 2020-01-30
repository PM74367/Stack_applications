#include<stdio.h>
#include<stdlib.h>
typedef struct stack
{
  char data;
  struct stack *next;
}stack;
void push(stack **head,char dataa)
{
  stack *new_node=(stack *)malloc(sizeof(stack));
  new_node->data=dataa;
  new_node->next=*head;
  *head=new_node;
}
char pop(stack **head)
{
  stack *temp=*head;
  char data=(*head)->data;
  *head=(*head)->next;
  free(temp);
  return data;
}
int isEmpty(stack *head)
{
  if(head==NULL)
     return 1;
  return 0;
}
int main()
{
  int n;
  stack *head=NULL;
  printf("Enter the size of parenthesis array:");
  scanf("%d",&n);
  printf("Enter the parenthesis array:\n");
  while(n--)
  {
    char ch;
    scanf(" %c",&ch);
    if(ch=='(')
      push(&head,')');
    if(ch=='[')
      push(&head,']');
    if(ch=='{')
      push(&head,'}');
    if(ch==')'||ch==']'||ch=='}')
    {
      if(!isEmpty(head))
      {
        char temp=pop(&head);
        if(ch!=temp)
        {
          printf("Parenthesis are not balanced");
          return 0;
        }
      }
      else
      {
        printf("Parenthesis are not balanced");
        return 0;
      }
    }
  }
  if(isEmpty(head))
  {
    printf("Parenthesis are balanced");
  }
  else
  {
    printf("Parenthesis are not balanced");
  }
  return 0;
}
