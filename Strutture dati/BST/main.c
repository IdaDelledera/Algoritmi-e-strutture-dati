#include <stdio.h>
#include <malloc.h>


typedef struct {
    struct TreeNode *left;
    struct TreeNode *right;
    int num;
}TreeNode;


void inOrder(TreeNode *current);

TreeNode *insert(TreeNode *root, int val);

void preOrder(TreeNode *current);

void postOder(TreeNode *current);

void nodePresent(TreeNode *root, int val);

void findMin(TreeNode *root);

void findMax(TreeNode *root);

TreeNode *delete(TreeNode *root, int val);


int main() {

    TreeNode *root = NULL;


    root=insert(root, 40);
    insert(root, 15);
    insert(root, 12);
    insert(root, 22);
    insert(root, 50);
    insert(root, 60);

    printf("Visita inorder -> ");
    inOrder(root);
    puts("");

    printf("Visita preorder -> ");
    preOrder(root);
    puts("");

    printf("Visita in postorder -> ");
    postOder(root);
    puts("");

    nodePresent(root, 50);

    findMin(root);

    findMax(root);

    delete(root, 60);
    //delete(root, 40);
    inOrder(root);


    return 0;
}


TreeNode *insert(TreeNode *root, int val){

    TreeNode *newNode = (TreeNode *) malloc(sizeof(TreeNode));

    newNode->num=val;
    newNode->left=NULL;
    newNode->right=NULL;

    if(root==NULL)
        return newNode;

    if (val < root->num){
        root->left=insert(root->left, val);
    }else{
        root->right=insert(root->right, val);
    }
    return root;
}

void inOrder(TreeNode *current){
    if (current != NULL) {
        inOrder(current->left);
        printf("%d, ", current->num);
        inOrder(current->right);
    }
}

void preOrder(TreeNode *current){
    if(current!=NULL){
        printf("%d, ", current->num);
        preOrder(current->left);
        preOrder(current->right);
    }
}

void postOder(TreeNode *current){
    if(current!=NULL){
        postOder(current->left);
        postOder(current->right);
        printf("%d, ", current->num);
    }
}


void nodePresent(TreeNode *root, int val) {

    if(root == NULL)
        printf("\nIl valore %d non esiste nel BST", val);

    if(val == root->num)
        printf("\nIl valore %d esiste nel BST", val);

    if(val > root->num)
        nodePresent(root->right, val);
    else if(val < root->num)
        nodePresent(root->left, val);
}

void findMin(TreeNode *root){

    while (root!=NULL && root->left!=NULL){
        root=root->left;
    }
    printf("\nIl minimo valore del BST e' %d\n", root->num);
}

void findMax(TreeNode *root){

    while (root!=NULL && root->right!=NULL){
        root=root->right;
    }
    printf("\nIl valore massimo all'interno del BST e' %d\n", root->num);
}

TreeNode *delete(TreeNode *root, int val){

    if (root == NULL) {
        return root;
    }

    if (val < root->num) {
        root = delete(root->left, val);
    } else if (val > root->num) {
        root = delete(root->right, val);
    } else {
        if (root->left == NULL) {
            TreeNode *tmp = root->right;
            free(root);
            return tmp;
        } else if (root->right == NULL) {
            TreeNode *tmp = root->left;
            free(root);
            return tmp;
        } else {
            TreeNode *tmp;
            while (root!=NULL && root->left!=NULL){
                root=root->left;
            }
            tmp=root->left;
            root->num = tmp->num;
            root->right = delete(root->right, tmp->num);
        }
        return root;
    }
}

