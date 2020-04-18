//global variables
bool isBST = true;
int prev = -1;

void in_Order(Node *root) {
    if (root) {
        in_Order(root->left);
        if (root->data > prev)
            prev = root->data;
        else {
            isBST = false;            
            return;
        }
        in_Order(root->right);
    }
}

bool checkBST(Node* root) {
    // Perform inorder traversal of tree and ensure it should be strictly increasing
    in_Order(root);
    return isBST;
}
