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
  int i,n;
  stack *head=NULL;
  printf("Enter the size of array:");
  scanf("%d",&n);
  int ar[n];
  for(i=0;i<n;i++)
  {
    scanf("%d",&ar[i]);
  }
  for(i=0;i<n;)
  {
    if(isEmpty(head)||ar[i]<peek(head))
    {
      push(&head,ar[i]);
      i++;
    }
    else
    {
      pop(&head);
    }
  }
  if(isEmpty(head))
  {
    printf("There are no elements in array which are greater than all elements to their right");
  }
  else
  {
    printf("Elements greater than all elements to their right are:");
    while(!isEmpty(head))
    {
      printf("%d ",peek(head));
      pop(&head);
    }
  }
  return 0;
}
