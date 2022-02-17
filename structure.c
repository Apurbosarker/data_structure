// #include <stdio.h>
// #include <stdlib.h>
// struct Node
// {
//     int data;
//     struct Node *next;
// };
// int main()
// {
//     struct Node *A = NULL, *B = NULL, *C = NULL;
//     A = (struct Node *)malloc(sizeof(struct Node));
//     B = (struct Node *)malloc(sizeof(struct Node));
//     C = (struct Node *)malloc(sizeof(struct Node));
//     A->data = 20;
//     B->data = 40;
//     C->data = 50;
//     A->next = B;
//     B->next = C;
//     C->next = NULL;
//     while (A != NULL)
//     {
//         printf("%d -> ", A->data);
//         A = A->next;
//     }
//     printf("NULL\n");

//     return 0;
// }

#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *next;
};
void print(struct Node *head);
void addNodeBegining(struct Node *head, int data)
{

    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
    temp->data = data;
    temp->next = head;
    struct Node *newhead = temp;
    print(newhead);
}
void addNodeEnding(struct Node *head, int data)
{
    struct Node *current = head;
    while (current->next != NULL)
    {
        current = current->next;
    }
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
    temp->data = data;
    temp->next = NULL;
    current->next = temp;
    print(head);
}

void addNodeMiddle(struct Node *head, int position, int data)
{

    int count = 1;
    struct Node *current = head;
    while (current != NULL)
    {
        count++;
        if (count == position)
        {
            struct Node *Newnode = (struct Node *)malloc(sizeof(struct Node));
            Newnode->data = data;
            Newnode->next = current->next;
            current->next = Newnode;
        }
        current = current->next;
    }
    print(head);
}

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
struct Node *createLinkList(int a[], int size)
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

int main()
{
    int a[5] = {1, 2, 3, 4, 5};
    struct Node *head;
    head = createLinkList(a, 5);
    print(head); // ager linklist
    addNodeBegining(head, 400);
    addNodeEnding(head, 388);
    addNodeMiddle(head, 3, 60);

    printf("index: %d", searchNode(head, 50));

    return 0;
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