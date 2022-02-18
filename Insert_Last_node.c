#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *next;
} * head;
void createLinkList(int n)
{
    int i, data;
    struct Node *newnode, *temp;
    head = (struct Node *)malloc(sizeof(struct Node));
    printf("Enter data of node 1: ");
    scanf("%d", &data);
    head->data = data;
    head->next = NULL;
    temp = head;
    for (i = 2; i <= n; i++)
    {
        newnode = (struct Node *)malloc(sizeof(struct Node));
        printf("Enter data of node %d: ", i);
        scanf("%d", &data);
        newnode->data = data;
        newnode->next = NULL;
        temp->next = newnode;
        temp = temp->next;
    }
}
void addNodeEnding(int data)
{
    struct Node *newnode, *temp;
    newnode = (struct Node *)malloc(sizeof(struct Node));
    newnode->data = data;
    newnode->next = NULL;
    temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newnode;
}
void displaylist()
{
    struct Node *temp;
    temp = head;
    while (temp != NULL)
    {
        printf("%d-->", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}
int main()
{
    int n, data;
    printf("Enter how many nodes: ");
    scanf("%d", &n);
    createLinkList(n);
    printf("Data in the list\n");
    displaylist();
    printf("Enter the data insert last node: ");
    scanf("%d", &data);
    addNodeEnding(data);
    printf("Success! final link list: ");
    displaylist();
    return 0;
}