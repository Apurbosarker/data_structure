#include <stdio.h>
#include <stdlib.h>

struct node {
    int num;
    struct node * nextptr;
}*stnode;


void ClListcreation(int n);
void ClLinsertNodeAtBeginning(int num);
void ClLinsertNodeAtAny(int num, int pos);
void displayClList(int a);

int main()
{
    int n,num1,a,insPlc;
    stnode = NULL;
	printf("\n\n Circular Linked List : Insert a node at any position in  a circular linked list :\n");
	printf("--------------------------------------------------------------------------------------\n");

    printf(" Input the number of nodes : ");
    scanf("%d", &n);
    ClListcreation(n);
    a=1;
    printf("Circular link list: ");
    displayClList(a);
	printf(" Input the position to insert a new node : ");
    scanf("%d", &insPlc);
    printf(" Input data for the position %d : ", insPlc);
    scanf("%d", &num1);
    ClLinsertNodeAtAny(num1,insPlc);
    a=2;
    printf("Updated circular link list: ");
    displayClList(a);
    return 0;
}

void ClListcreation(int n)
{
    int i, num;
    struct node *preptr, *newnode;

    if(n >= 1)
    {
        stnode = (struct node *)malloc(sizeof(struct node));

        printf(" Input data for node 1 : ");
        scanf("%d", &num);
        stnode->num = num;
        stnode->nextptr = NULL;
        preptr = stnode;
        for(i=2; i<=n; i++)
        {
            newnode = (struct node *)malloc(sizeof(struct node));
            printf(" Input data for node %d : ", i);
            scanf("%d", &num);
            newnode->num = num;
            newnode->nextptr = NULL;
            preptr->nextptr = newnode;
            preptr = newnode;
        }
        preptr->nextptr = stnode;
    }
}

void ClLinsertNodeAtBeginning(int num)
{
    struct node *newnode, *curNode;

        newnode = (struct node *)malloc(sizeof(struct node));
        newnode->num = num;
        newnode->nextptr = stnode;
        curNode = stnode;
        while(curNode->nextptr != stnode)
        {
            curNode = curNode->nextptr;
        }
        curNode->nextptr = newnode;
        stnode = newnode;

}

void ClLinsertNodeAtAny(int num, int pos)
{
    struct node *newnode, *curNode;
    int i;


        newnode = (struct node *)malloc(sizeof(struct node));
        newnode->num = num;
        curNode = stnode;
        for(i=2; i<=pos-1; i++)
        {
            curNode = curNode->nextptr;
        }
        newnode->nextptr = curNode->nextptr;
        curNode->nextptr = newnode;

}

void displayClList(int m)
{
    struct node *tmp;
    int n = 1;
  tmp = stnode;

        do {
            printf("|| %d ||--->>", tmp->num);

            tmp = tmp->nextptr;
            n++;
        }while(tmp != stnode);
        printf("|| %d ||\n", tmp->num);
    }

