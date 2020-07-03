
#include <stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *left,*right;
};


struct node* newNode(int data)
{
    struct node *temp=(struct node*)malloc(sizeof(struct node*));
    temp->data=data;
    temp->left=NULL;
    temp->right=NULL;
}

void inorder(struct node *root)
{
    if(root==NULL)
    {
        return;
    }
    inorder(root->left);
    printf("%d  ",root->data);
    inorder(root->right);
    
}


struct node* search(struct node* root, int data) 
{ 
    if (root == NULL || root->data == data) 
       return root; 
     
    if (root->data < data) 
       return search(root->right, data); 
  
    return search(root->left, data); 
}


int main()
{
    struct node *n1=(struct node*)malloc(sizeof(struct node));
    n1->data=1;
    n1->left=NULL;
    n1->right=NULL;
    
    struct node *n3=newNode(3);
    struct node *n4=newNode(4);
    struct node *n5=newNode(5);
    struct node *n6=newNode(6);
    struct node *n7=newNode(7);
    struct node *n10=newNode(10);
    struct node *n12=newNode(12);
    
    n10->left=n6;
    n10->right=n12;
    n6->left=n3;
    n6->right=n7;
    n3->left=n1;
    n3->left=n4;
    n4->left=n5;
    
    printf("Inorder Traversal\n");
    inorder(n10);
    
    struct node *temp=(struct node*)malloc(sizeof(struct node));
    temp->data=n10->data;
    temp->left=NULL;
    temp->right=NULL;
    
    struct node *find=search(n10,10);
    printf("\nData at searched node: %d",find->data);

    return 0;
}
