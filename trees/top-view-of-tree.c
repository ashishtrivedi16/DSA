struct node {
    int data;
    struct node* left;
    struct node* right;
};


void for_left(node * root)
{
    if(root->left != NULL)
        for_left(root->left);
    cout << root->data << " ";
}


void for_right(node * root)
{
    cout << root->data << " ";
    if(root->right != NULL)
        for_right(root->right);
}

void topView(node * root)
{
    if(root->left != NULL)
        for_left(root->left);
    cout << root->data << " ";
    if(root->right != NULL)
        for_right(root->right);
    
}
