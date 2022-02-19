#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
} * head;
void create(int n);
void insertAtNth(int a, int b);
void display();
int main()
{
    int n, a, b;
    printf("Enter total number of nodes: ");
    scanf("%d", &n);
    create(n);
    printf("\n\tData in the list: ");
    display();
    printf("\nInsert in position no: ");
    scanf("%d", &b);
    printf("\nEnter data to insert at %dth position of the list: ", b);
    scanf("%d", &a);
    insertAtNth(a, b);
    printf("\n\tData in the list: ");
    display();
    return 0;
}
void create(int n)
{
    struct node *newNode, *temp;
    int data, i;
    head = (struct node *)malloc(sizeof(struct node));
    if (head == NULL)
    {
        printf("Unable to allocate memory.");
    }
    else
    {
        printf("Enter the data of node 1: ");
        scanf("%d", &data);
        head->data = data;
        head->next = NULL;
        temp = head;
        for (i = 2; i <= n; i++)
        {
            newNode = (struct node *)malloc(sizeof(struct node));
            if (newNode == NULL)
            {
                printf("Unable to allocate memory.");
                break;
            }
            else
            {
                printf("Enter the data of node %d: ", i);
                scanf("%d", &data);
                newNode->data = data;
                newNode->next = NULL;
                temp->next = newNode;
                temp = temp->next;
            }
        }
        printf("\nLinked list created successfully\n");
    }
}
void insertAtNth(int data, int pos)
{
    int i;
    struct node *newNode, *temp;
    newNode = (struct node *)malloc(sizeof(struct node));
    if (newNode == NULL)
    {
        printf("Unable to allocate memory.");
    }
    else
    {
        newNode->data = data;
        newNode->next = NULL;
        temp = head;
        for (i = 2; i < pos; i++)
        {
            temp = temp->next;
            if (temp == NULL)
                break;
        }
        if (temp != NULL)
        {
            newNode->next = temp->next;
            temp->next = newNode;
            printf("Data inserted successfully\n");
        }
        else
        {
            printf("Unable to insert data at %dth position.\n", pos);
        }
    }
}
void display()
{
    struct node *temp;
    if (head == NULL)
    {
        printf("List is empty.");
    }
    else
    {
        temp = head;
        while (temp != NULL)
        {
            printf("%d->", temp->data);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}