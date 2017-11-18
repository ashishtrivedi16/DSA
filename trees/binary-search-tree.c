#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *left;
    struct node *right;
};

void mirrorBST(struct node* root);
int externalNodes(struct node* root);
int internalNodes(struct node* root);
int totalNodes(struct node* root);
void deleteBST(struct node* root);
int height(struct node* root);
struct node* maxvalue(struct node* node);
struct node* minvalue(struct node* node);
struct node* insert(struct node *node, int value);
void preordertraversal(struct node *node);
void inordertraversal(struct node *node);
void postordertraversal(struct node *node);
struct node* delete(struct node *root, int value);

struct node* insert(struct node* node, int value){
    if(node == NULL){
        node = (struct node*)malloc(sizeof(struct node));
        node->data = value;
        node->left = NULL;
        node->right = NULL;
    }else if(value < node->data){
        node->left = insert(node->left, value);
    }else if(value > node->data){
        node->right = insert(node->right, value);
    }
    return node;
}
struct node* delete(struct node* root, int value)
{
    if (root == NULL)
        return root;
    else if(value < root->data)
        root->left = delete(root->left, value);
    else if(value > root->data)
        root->right = delete(root->right, value);
    else
    {
        if(root->left == NULL)
        {
            struct node* temp = root->right;
            free(root);
            return temp;
        }
        if(root->right == NULL)
        {
            struct node* temp = root->left;
            free(root);
            return temp;
        }
        struct node* temp = minvalue(root->right);
        root->data = temp->data;
        root->right = delete(root->right, temp->data);
    }
    return root;
}

void preordertraversal(struct node* node){
    if (node != NULL) {
        printf("%d\t", node->data);
        preordertraversal(node->left);
        preordertraversal(node->right);
    }
}

void inordertraversal(struct node* node){
    if (node != NULL) {
        inordertraversal(node->left);
        printf("%d\t", node->data);
        inordertraversal(node->right);
    }
}

void postordertraversal(struct node* node){
    if (node != NULL) {
        postordertraversal(node->left);
        postordertraversal(node->right);
        printf("%d\t", node->data);
    }
}

struct node* minvalue(struct node* node){
    while (node->left != NULL) {
        node = node->left;
    }
    return node;
}

struct node* maxvalue(struct node* node){
    while (node->right != NULL) {
        node = node->right;
    }
    return node;
}

int height(struct node* root){
    if (root == NULL) {
        return 0;
    } else {
        int lheight = height(root->left);
        int rheight = height(root->right);
        
        if (lheight > rheight) {
            return lheight + 1;
        } else {
            return rheight + 1;
        }
    }
}

void deleteBST(struct node* root){
    if (root != NULL) {
        deleteBST(root->left);
        deleteBST(root->right);
        free(root);
    }
}

int totalNodes(struct node* root){
    if (root == NULL) {
        return 0;
    } else {
        return totalNodes(root->left) + totalNodes(root->right) + 1;
    }
}

int internalNodes(struct node* root){
    if (root == NULL) {
        return 0;
    }
    if (root->left == NULL && root->right == NULL) {
        return 0;
    } else {
        return internalNodes(root->left) + internalNodes(root->right) + 1;
    }
}

int externalNodes(struct node* root){
    if (root == NULL) {
        return 0;
    }
    if (root->left == NULL && root->right == NULL) {
        return 1;
    } else {
        return externalNodes(root->left) + externalNodes(root->right);
    }
}

void mirrorBST(struct node* root){
    if (root != NULL) {
        mirrorBST(root->left);
        mirrorBST(root->right);
        struct node* temp = root->left;
        root->left = root->right;
        root->right = temp;
    }
}

int main(void){
    int value, options;
    struct node* root = NULL;
    do {
        printf("***************** Main Menu *****************\n");
        printf("1) Insert an element\n");
        printf("2) Delete an element\n");
        printf("3) Preorder traversal\n");
        printf("4) Inorder traversal\n");
        printf("5) Postorder traversal\n");
        printf("6) Minimum value in tree\n");
        printf("7) Maximum value in tree\n");
        printf("8) Height of tree\n");
        printf("9) Delete BST\n");
        printf("10) Number of nodes in tree\n");
        printf("11) Number of internal nodes in tree\n");
        printf("12) Number of external nodes in tree\n");
        printf("13) Mirror image of tree\n");
        printf("14) Exit\n");
        printf("Enter your option: ");
        scanf("%d", &options);
        switch (options) {
            case 1:
                printf("Enter -1 to quit\n");
                printf("Enter a number:");
                scanf("%d",&value);
                while (value != -1){
                    if (root == NULL){
                        root = insert(root,value);
                    }else{
                        insert(root,value);
                    }
                    printf("Enter a number:");
                    scanf("%d",&value);
                }
                break;
            case 2:
                printf("Enter value to delete: ");
                scanf("%d", &value);
                delete(root, value);
                break;
            case 3:
                preordertraversal(root);
                printf("\n");
                break;
            case 4:
                inordertraversal(root);
                printf("\n");
                break;
            case 5:
                postordertraversal(root);
                printf("\n");
                break;
            case 6:
                printf("%d\n", minvalue(root)->data);
                break;
            case 7:
                printf("%d\n", maxvalue(root)->data);
                break;
            case 8:
                printf("Height of tree is: %d\n", height(root));
                break;
            case 9:
                deleteBST(root);
                printf("Tree was deleted\n");
                break;
            case 10:
                printf("Total nodes are: %d\n", totalNodes(root));
                break;
            case 11:
                printf("Total internal nodes : %d\n", internalNodes(root));
                break;
            case 12:
                printf("Total external nodes : %d\n", externalNodes(root));
                break;
            case 13:
                mirrorBST(root);
                break;
        }
    } while (options != 14);
}
