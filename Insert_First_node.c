#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *next;
};
struct Node *head;
void insert(int x)
{
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
    temp->data = x;
    temp->next = head;
    head = temp;
}
void display()
{
    struct Node *temp = head;
    printf("List is:  ");
    while (temp != NULL)
    {

        printf("%d-->", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}
int main()
{
    head = NULL;
    int i, n, x;
    printf("Enter how many number of node: ");
    scanf("%d", &n);
    for (i = 1; i <= n; i++)
    {
        printf("Enter the value of node %d: ", i);
        scanf("%d", &x);
        insert(x);
        display();
    }
    return 0;
}
