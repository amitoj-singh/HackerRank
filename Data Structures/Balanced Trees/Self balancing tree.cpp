/* Node is defined as :
typedef struct node
{
    int val;
    struct node* left;
    struct node* right;
    int ht;
} node; */

int height(node * n) {
    if (!n) { // if (n == NULL)
        return -1;
    }
    return n->ht;
}

node* rightRotate(node *n) {
    node *x = n->left;
    node *T2 = x->right;
  
    // Perform rotation  
    x->right = n;
    n->left = T2;
  
    // Update heights  
    n->ht = max(height(n->left), height(n->right)) + 1;  
    x->ht = max(height(x->left), height(x->right)) + 1;  

    return x;  
}

node* leftRotate(node *n) {  
    node *x = n->right;
    node *T2 = x->left;

    // Perform rotation  
    x->left = n;
    n->right = T2;

    // Update heights  
    n->ht = max(height(n->left), height(n->right)) + 1;
    x->ht = max(height(x->left), height(x->right)) + 1;

    return x;
}

node* insert(node * root, int val) {
	if (!root) { // if (root == NULL)
        node *newNode = new node;    
        newNode->val = val;
        newNode->left = NULL;
        newNode->right = NULL;
        newNode->ht = 0;
        return newNode;
    } 
    
    if (val < root->val) {
        root->left = insert(root->left, val);
    } else if (val > root->val) {
        root->right = insert(root->right, val);
    }
    
    root->ht = 1 + max(height(root->left), height(root->right)); // update height
    
    int balance = height(root->left) - height(root->right); // calculate balaceFactor
    
    if (balance > 1 && val < root->left->val) { // left-left case
        root = rightRotate(root);
    } else if (balance < -1 && val > root->right->val) { // right-right case
        root = leftRotate(root);
    } else if (balance > 1 && val > root->left->val) { // left-right case
        root->left = leftRotate(root->left);
        root = rightRotate(root);
    } else if (balance < -1 && val < root->right->val) { // right-left case
        root->right = rightRotate(root->right);
        root = leftRotate(root);
    }
    return root;  
}

// References:
// https://www.geeksforgeeks.org/avl-tree-set-1-insertion/
