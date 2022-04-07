#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

struct node
{
    int info;
    struct node *left;
    struct node *right;
};

struct node *new_node(int data)
{
    struct node *ptr=(struct node*)malloc(sizeof(struct node));
    ptr->info = data;
    ptr->left = NULL;
    ptr->right = NULL;
    return ptr;
}
struct node *insert(struct node *root, int data){
    if(root==NULL){
      return new_node(data);
    }
    else
    {
        if(data<root->info){
            root->left =insert(root->left,data);
        }
        else{
            root->right =insert(root->right,data);
        }
    }
    return root;
}
void implement(struct node *root){
        if(root){
        printf("%d ",root->info);
        implement(root->left);
        implement(root->right);
    }
}
int main(){
    struct Node *root= NULL;
    root = insert(root, 5);
    root = insert(root, 2);
    root = insert(root, 10);
    root = insert(root, 3);
    root = insert(root, 6);
    root = insert(root, 60);
    root = insert(root, 80);
    printf("The given Binary search tree \n");
    implement(root);
    return 0;
}