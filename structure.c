#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *next;
};
int main()
{
    struct Node *A = NULL, *B = NULL, *C = NULL;
    A = (struct Node *)malloc(sizeof(struct Node));
    B = (struct Node *)malloc(sizeof(struct Node));
    C = (struct Node *)malloc(sizeof(struct Node));
    A->data = 20;
    B->data = 40;
    C->data = 50;
    A->next = B;
    B->next = C;
    C->next = NULL;
    while (A != NULL)
    {
        printf("%d -> ", A->data);
        A = A->next;
    }
    printf("NULL\n");

    return 0;
}
