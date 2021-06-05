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

int findMaxLeft(TreeNode *root);

bool bstTrueorFalse(TreeNode *root, int a, int b);


int main() {

    TreeNode *root = NULL;

    root = insert(root, 40);
    insert(root, 15);
    insert(root, 70);
    insert(root, 3);
    insert(root, 10);
    insert(root, 60);


    if (bstTrueorFalse(root, 30, 70))
        printf("vero");
    else
        printf("falso");

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

void inOrder(TreeNode *current) {
    if (current != NULL) {
        inOrder(current->left);
        printf("%d, ", current->num);
        inOrder(current->right);
    }
}

int findMaxRight(TreeNode *root) {

    if (root == NULL)
        return 0;

    while (root != NULL && root->right != NULL) {
        root = root->right;
    }
    return root->num;
}

int findMaxLeft(TreeNode *root) {

    if (root == NULL)
        return 0;

    root = root->left;

    return findMaxRight(root);
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
        if (root->right == NULL && findMaxLeft(root)<=a){
            return true;
        }
    }

    if (findMaxRight(root)<=b && findMaxLeft(root)>=a)
        return true;

    return false;
}


