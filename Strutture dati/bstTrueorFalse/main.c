#include <stdio.h>
#include <malloc.h>
#include <stdbool.h>

typedef struct {
    struct TreeNode *left;
    struct TreeNode *right;
    int num;
} TreeNode;

TreeNode *insert(TreeNode *root, int val);

void inOrder(TreeNode *current);

int findMaxRight(TreeNode *root);

int findMinLeft(TreeNode *root);

bool bstTrueorFalse(TreeNode *root, int a, int b);

void Decrescente(TreeNode *root);



int main() {

    TreeNode *root = NULL;

    root = insert(root, 30);
    insert(root, 15);
    insert(root, 60);
    insert(root, 7);
    insert(root, 22);
    insert(root, 45);
    insert(root, 75);
    insert(root, 17);
    insert(root, 27);

    if (bstTrueorFalse(root, 8, 75))
        printf("vero\n");
    else
        printf("falso\n");

    Decrescente(root);

}


TreeNode *insert(TreeNode *root, int val) {

    TreeNode *newNode = (TreeNode *) malloc(sizeof(TreeNode));

    newNode->num = val;
    newNode->left = NULL;
    newNode->right = NULL;

    if (root == NULL)
        return newNode;

    if (val < root->num) {
        root->left = insert(root->left, val);
    } else {
        root->right = insert(root->right, val);
    }
    return root;
}

int findMaxRight(TreeNode *root) {

    if (root == NULL)
        return 0;

    while (root != NULL && root->right != NULL) {
        root = root->right;
    }
    return root->num;
}

int findMinLeft(TreeNode *root) {

    if (root == NULL)
        return 0;

    while(root!=NULL && root->left!=NULL)
        root=root->left;


    return root->num;
}

bool bstTrueorFalse(TreeNode *root, int a, int b){

    if(root == NULL)
        return false;
    if (root->num == a){
        if (root->left == NULL && findMaxRight(root)<=b){
            return true;
        }
    }
    if(root->num == b){
        if (root->right == NULL && findMinLeft(root) <= a){
            return true;
        }
    }
    if (findMaxRight(root)<=b && findMinLeft(root) >= a)
        return true;

    return false;
}

void Decrescente(TreeNode *root){

    if(root == NULL)
        return;

    Decrescente(root->right);
    printf("%d, ", root->num);
    Decrescente(root->left);
}



