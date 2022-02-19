#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *next;
};
void print(struct Node *head);
int searchNode(struct Node *head, int data)
{
    int index = 1;
    while (head != NULL)
    {
        if (head->data == data)
        {
            return index;
        }
        index++;
        head = head->next;
    }
    return -1;
}
int createLinkList(int a[], int size)
{
    struct Node *head = NULL, *temp = NULL, *current = NULL;
    int i;
    for (i = 0; i < size; i++)
    {
        temp = (struct Node *)malloc(sizeof(struct Node));
        temp->data = a[i];
        temp->next = NULL;
        if (head == NULL)
        {
            head = temp;
            current = temp;
        }
        else
        {
            current->next = temp;
            current = current->next;
        }
    }
    return head;
}
void print(struct Node *head)
{
    while (head != NULL)
    {
        printf("%d->", head->data);
        head = head->next;
    }
    printf("NULL\n");
}
int main()
{
    int a[100];
    int i,n;
    printf("Please enter size of node: ");
    scanf("%d",&n);
    printf("Please enter node data: \n");
    for(i=0; i<n; i++)
    {
        scanf("%d",&a[i]);
    }
    struct Node *head;
    printf("Link list: ");
    head = createLinkList(a, n);
    print(head);
    int x;
    printf("enter search data:");
    scanf("%d",&x);
    printf("index: %d", searchNode(head, x));
    return 0;
}
