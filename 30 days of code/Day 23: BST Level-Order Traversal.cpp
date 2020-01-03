#include <iostream>
#include <cstddef>
#include <queue>
#include <string>
#include <cstdlib>

using namespace std;    
class Node{
    public:
        int data;
        Node *left,*right;
        Node(int d){
            data=d;
            left=right=NULL;
        }
};
class Solution{
    public:
        Node* insert(Node* root, int data){
            if(root==NULL){
                return new Node(data);
            }
            else{
                Node* cur;
                if(data<=root->data){
                    cur=insert(root->left,data);
                    root->left=cur;
                }
                else{
                   cur=insert(root->right,data);
                   root->right=cur;
                 }           
           return root;
           }
        }

    void levelOrder(Node * root){
      //Write your code here
        if (root != NULL) {
            queue<Node*> tempQ;
            //enqueue current root
            tempQ.push(root);

            while (!tempQ.empty()) {
                Node* current = tempQ.front();
                tempQ.pop();
                cout << current->data << " ";

                //enqueue child elements from next level in order
                if (current->left != NULL) 
                    tempQ.push(current->left);
                if (current->right != NULL)
                    tempQ.push(current->right);
            }
        }
    }

};//End of Solution
int main(){
    Solution myTree;
    Node* root=NULL;
    int T,data;
    cin>>T;
    while(T-->0){
        cin>>data;
        root= myTree.insert(root,data);
    }
    myTree.levelOrder(root);
    return 0;
}
