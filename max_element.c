#include<stdio.h>
#include<stdlib.h>
typedef struct stack
{
  int data;
  struct stack *next;
}stack;
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
void push(stack **head,stack **max,int dataa)
{
  stack *new_node=(stack *)malloc(sizeof(stack));
  new_node->data=dataa;
  new_node->next=*head;
  *head=new_node;
  if(isEmpty(*max))
  {
    stack *new_node1=(stack *)malloc(sizeof(stack));
    new_node1->data=dataa;
    new_node1->next=*max;
    *max=new_node1;
  }
  else
  {
    stack *new_node1=(stack *)malloc(sizeof(stack));
    new_node1->data=(peek(*max)>dataa?peek(*max):dataa);
    new_node1->next=*max;
    *max=new_node1;
  }
}
int main()
{
  int n,elem;
  stack *head=NULL,*max=NULL;
  do{
    printf("Enter operation which you want to perform on stack:\n1 for push\n2 for pop\n3 for maximum element so far\n-1 to quit\n");
    scanf("%d",&n);
    switch(n){
      case 1:
        printf("Enter element to push:");
        scanf("%d",&elem);
        push(&head,&max,elem);
        break;
      case 2:
        if(isEmpty(head))
          printf("Stack is empty\n");
        else
        {
          pop(&head);
          pop(&max);
        }
        break;
      case 3:
        if(isEmpty(head))
          printf("Stack is empty\n");
        else
          printf("Maximum element so far is %d\n",peek(max));
        break;
      default:
        printf("Enter valid option\n");
    }
  }while(n!=-1);
  return 0;
}
