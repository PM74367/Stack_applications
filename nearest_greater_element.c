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
  printf("Enter the size of array:");
  scanf("%d",&n);
  int *ar=(int *)malloc(sizeof(int)*n);
  int *res=(int *)malloc(sizeof(int)*n);
  printf("Enter elements in array:\n");
  for(i=0;i<n;i++)
  {
    scanf("%d",&ar[i]);
  }
  stack *head=NULL;
  for(i=0;i<n;)
  {
    if(isEmpty(head)||ar[i]<=ar[peek(head)])
    {
      push(&head,i);
      i++;
    }
    else
    {
      res[peek(head)]=ar[i];
      pop(&head);
    }
  }
  while(!isEmpty(head))
  {
    res[peek(head)]=-1;
    pop(&head);
  }
  for(i=0;i<n;i++)
  {
    printf("%d --> %d\n",ar[i],res[i]);
  }
  free(ar);
  free(res);
  return 0;
}
