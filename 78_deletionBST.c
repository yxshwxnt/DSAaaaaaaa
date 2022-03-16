#include<stdio.h>
#include<malloc.h>

struct node{
    int data;
    struct node* left;
    struct node* right;
};

struct node* createNode(int data){
    struct node *n; 
    n = (struct node *) malloc(sizeof(struct node));
    n->data = data; 
    n->left = NULL; 
    n->right = NULL; 
    return n; 
} 

void inOrder(struct  node* root){
    if(root!=NULL){
        inOrder(root->left);
        printf("%d ", root->data);
        inOrder(root->right);
    }
} 

struct node* inOrderPredecessor(struct node* root){    //left subtree ka right most child
    root=root->left; 
    while(root->right!=NULL){ 
        root=root->right; 
    }
    return root; 
} 

struct node* deleteNode(struct node* root,int val){ 
    struct node* iPre; 
    if(root==NULL){ 
        return NULL; 
    }
    if(root->left==NULL && root->right==NULL){      //node is a leaf node
        free(root);  
        return NULL;
    }
    //Search for root to be deleted 
    if(val < root->data){ 
        root->left=deleteNode(root->left,val); 
    }
    else if(val > root->data){ 
        root->right=deleteNode(root->right,val); 
    }
    //Deletion stratergy when node is found 
    else{ 
        iPre=inOrderPredecessor(root); 
        root->data=iPre->data; 
        root->left=deleteNode(root->left,iPre->data); 
    } 
    return root; 
}

int main(){
    struct node *p = createNode(5);
    struct node *p1 = createNode(3);
    struct node *p2 = createNode(6);
    struct node *p3 = createNode(1);
    struct node *p4 = createNode(4);
    // Finally The tree looks like this:
    //      5
    //     / \
    //    3   6
    //   / \
    //  1   4  

    // Linking the root node with left and right children
    p->left = p1;
    p->right = p2;
    p1->left = p3;
    p1->right = p4;

    inOrder(p); 
    deleteNode(p,5); 
    printf("\n"); 
    inOrder(p); 
    return 0;
}
