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
  int i,n,order=1;
  printf("Enter the no. of decorated trucks:");
  scanf("%d",&n);
  int *ar=(int *)malloc(sizeof(int)*n);
  printf("Enter the order of trucks\n");
  for(i=0;i<n;i++)
  {
    scanf("%d",&ar[i]);
  }
  stack *head=NULL;
  for(i=0;i<n;)
  {
    if(ar[i]==order)
    {
      i++;
      order++;
    }
    else
    {
      if(isEmpty(head)||ar[i]<peek(head))
      {
        push(&head,ar[i]);
        i++;
      }
      else{
        if(isEmpty(head))
        {
          printf("Not possible");
          return 0;
        }
        else
        {
          if(peek(head)==order)
          {
            pop(&head);
            order++;
          }
          else
          {
            printf("Not possible");
            return 0;
          }
        }
      }
    }
  }
  if(!isEmpty(head))
  {
    while(!isEmpty(head))
    {
      if(order==peek(head))
      {
        order++;
        pop(&head);
      }
      else
      {
        printf("Not possible");
        break;
      }
    }
  }
  printf("Possible");
  free(ar);
  return 0;
}
