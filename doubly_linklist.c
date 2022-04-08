#include<stdio.h>
#include<stdlib.h>
struct Node
{
    int data;
    struct Node *next;
    struct Node *prev;
}*head;

void createlinklist(int n)
{
    int i,data;
    struct Node *newnode, *temp;

    head = (struct Node*)malloc(sizeof(struct Node));
    printf("Enter the node 1: ");
    scanf("%d",&data);
    head->data=data;
    head->prev=NULL;
    head->next=NULL;

    temp=head;
    for(i=2; i<=n; i++)
    {
        newnode=(struct Node*)malloc(sizeof(struct Node));
        printf("Enter the node %d: ",i);
        scanf("%d",&data);
        newnode->data = data;
        newnode->next=NULL;
        newnode->prev=temp;
        temp->next=newnode;
        temp=temp->next;

    }
    printf("\n");

}

void display()
{
    struct Node *temp;

    temp = head;
    printf("NULL <<-->> ");
    while(temp!=NULL)
    {

        printf("|| %d ||  <<-->>  ", temp->data);
        temp= temp->next;

    }
    printf("NULL\n");
}
int main()
{
    int n;
    printf("Enter the number of node: ");
    scanf("%d",&n);
    createlinklist(n);
    printf("The double link list: ");
    display();

    return 0;
}
