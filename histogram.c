//Program to find largest area in histogram
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
  int i,elements,area=0,max_area=0;
  stack *head=NULL;
  printf("Enter no. of elements in histogram array:");
  scanf("%d",&elements);
  int *hist=(int *)malloc(sizeof(int)*elements);
  printf("Enter length of each bar:\n");
  for(i=0;i<elements;i++)
  {
    scanf("%d",&hist[i]);
  }
  for(i=0;i<elements;)
  {
    if(isEmpty(head)||hist[i]>=hist[peek(head)])
    {
      push(&head,i);
      i++;
    }
    else
    {
      int ht=hist[peek(head)];
      pop(&head);
      int len=isEmpty(head)?i:i-peek(head)-1;
      area=len*ht;
      if(area>max_area)
      {
        max_area=area;
      }
    }
  }
  while(!isEmpty(head))
  {
    int ht=hist[peek(head)];
    pop(&head);
    int len=isEmpty(head)?i:i-peek(head)-1;
    area=len*ht;
    if(area>max_area)
    {
      max_area=area;
    }
  }
  printf("Maximum area of histogram is %d",max_area);
  free(hist);
  return 0;
}
