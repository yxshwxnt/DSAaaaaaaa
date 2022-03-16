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

int isBST(struct  node* root){
    static struct node* prev=NULL;    //variable value wont be diff for diff calls in recursion
    if(root!=NULL){
        if(!isBST(root->left)){ 
            return 0; 
        }
        if(prev!=NULL && root->data <= prev->data){ 
            return 0;
        }
        prev=root; 
        return isBST(root->right);
    }
    else{ 
        return 1; 
    }
}

struct node* search(struct node* root,int key){ 
    if(root==NULL){ 
        return NULL; 
    }
    if(key==root->data){ 
        return root;
    }
    else if(key<root->data){ 
        search(root->left,key);
    }
    else{ 
        search(root->right,key);
    }
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

    struct node* n=search(p,6); 
    if(n!=NULL){ 
        printf("Found: %d\n",n->data);
    }
    else{ 
        printf("Element not found\n");
    }

    return 0;
}
