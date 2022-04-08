#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node * next;
}*head;
void createList(int n);
void displayList();
int main()
{
    int n, data;

    head = NULL;
    printf("Enter the size of the list: ");
    scanf("%d", &n);
    createList(n);
    displayList();
return 0;
}
void createList(int n)
{
    int i, data;
    struct node *prev, *curr;

    if(n >= 1)
    {
        head = (struct node *)malloc(sizeof(struct node));
        printf("Enter data of 1 node: ");
        scanf("%d", &data);
        head->data = data;
        head->next = NULL;
        prev = head;
        for(i=2; i<=n; i++)
        {
            curr = (struct node *)malloc(sizeof(struct node));

            printf("Enter data of %d node: ", i);
            scanf("%d", &data);

            curr->data = data;
            curr->next = NULL;

            prev->next = curr;
            prev = curr;
        }
        prev->next = head;
        printf("\n\tCircular link list created successfuly\n\n");
    }
}

void displayList()
{
    struct node *temp;
    int n = 1;

        temp = head;
        printf("Circular link list: ");

        do {
            printf("%d-->",temp->data);

            temp = temp->next;
            n++;
        }while(temp != head);

    printf("%d\n",temp->data);
}
