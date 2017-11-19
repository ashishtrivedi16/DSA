struct node
{
    int data;
    node* left;
    node* right;
}


int height(struct node* root){
    if(root == NULL)
        return 0;
    else{
        int lheight = height(root->left);
        int rheight = height(root->right);
    
        if(lheight > rheight)
            return lheight + 1;
        else
            return rheight + 1;
    }
}

void printLevel(struct node* root, int level){
    if(root == NULL)
        return;
    if(level == 1)
        cout << root->data << " ";
    else
        printLevel(root->left, level - 1);
        printLevel(root->right, level - 1);
}

void levelOrder(node * root) {
    int h = height(root);
    for(int i = 1; i <= h; i++)
        printLevel(root, i);
}
