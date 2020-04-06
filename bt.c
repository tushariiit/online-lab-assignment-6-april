#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *left;
    struct node *right;
};
int create()
{
    int d;
    struct node *newnode=(struct node*)malloc(sizeof(struct node));
    printf("enter data(-1 for empty):");
    scanf("%d",&d);
    if(d==-1)
    {
        printf("u have not entered any data.");
        return NULL;
    }
    else
    {
        newnode->data=d;
        printf("enter data for left child(-1 for empty)\n");
        newnode->left=create();
        printf("enter data for right child(-1 for empty)\n");
        newnode->right=create();
        return newnode;
    }
}
void inorder(struct node *node)
{
    if(node)
    {
     inorder(node->left);
     printf("%d\n",node->data);
     inorder(node->right);
    }
    else
    {
     return 0;
    }
}
void preorder(struct node *node)
{
     if(node)
    {
     printf("%d\n",node->data);
     preorder(node->left);
     preorder(node->right);
    }
    else
    {
     return 0;
    }
}
void postorder(struct node *node)
{
     if(node)
    {
     postorder(node->left);
     postorder(node->right);
     printf("%d\n",node->data);
    }
    else
    {
     return 0;
    }
}
int main()
{
    struct node *root=create();
struct node *t=root;
printf("Root child is %d\n ",t->data);
printf("the inorder is:\n");
inorder(t);
printf("the preorder is:\n");
preorder(t);
printf("the postorder is:\n");
postorder(t);
return 0;
}
