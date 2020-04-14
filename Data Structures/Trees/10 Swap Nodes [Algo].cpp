#include <bits/stdc++.h>

using namespace std;

class Node {
    public:
        int data;
        Node *left;
        Node *right;

        Node(int data) {
            this->data = data;
            this->left = NULL;
            this->right = NULL;
        }
};

void swap(Node *root, int K) {
    queue<Node *> que;
    que.push(root);
    que.push(NULL);
    int level = 1;

    while (!que.empty()) {
        Node *temp = que.front();
        que.pop();
        if (!temp) { // if (temp != NULL)
            if (que.empty())
                break;
            level++;
            que.push(NULL);
        }
        else {
            if (level%K == 0 && (temp->left || temp->right)) {
                Node *s = temp->left;
                temp->left = temp->right;
                temp->right = s;
            }
            if (temp->left) 
                que.push(temp->left);
            if (temp->right) 
                que.push(temp->right);
        }
    }
}

void inOrderTraversal(Node *root, vector<int> &resultArr) {
    if (root) {
        inOrderTraversal(root->left, resultArr);
        resultArr.push_back(root->data);
        inOrderTraversal(root->right, resultArr);
    }
}

/*
 * Complete the swapNodes function below.
 */
vector<vector<int>> swapNodes(vector<vector<int>> indexes, vector<int> queries) {
    /*
     * Write your code here.
    */
    queue<Node *> que;
    Node *root = new Node(1);
    que.push(root);
    int size = indexes.size();
    for (int i = 0; i < size; i++) {
        Node *temp = que.front();
        que.pop();
        if (indexes[i][0] != -1) {
            Node *left = new Node(indexes[i][0]);
            temp->left = left;
            que.push(left);
        }
        if (indexes[i][1] != -1) {
            Node *right = new Node(indexes[i][1]);
            temp->right = right;
            que.push(right);
        }
    }

    vector<vector<int>> result;
    size = queries.size();
    for (int i = 0; i < size; i++) {
        swap(root, queries[i]);
        vector<int> inOrder;
        inOrderTraversal(root, inOrder);
        result.push_back(inOrder);
    }

    return result;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    vector<vector<int>> indexes(n);
    for (int indexes_row_itr = 0; indexes_row_itr < n; indexes_row_itr++) {
        indexes[indexes_row_itr].resize(2);

        for (int indexes_column_itr = 0; indexes_column_itr < 2; indexes_column_itr++) {
            cin >> indexes[indexes_row_itr][indexes_column_itr];
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    int queries_count;
    cin >> queries_count;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    vector<int> queries(queries_count);

    for (int queries_itr = 0; queries_itr < queries_count; queries_itr++) {
        int queries_item;
        cin >> queries_item;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        queries[queries_itr] = queries_item;
    }

    vector<vector<int>> result = swapNodes(indexes, queries);

    for (int result_row_itr = 0; result_row_itr < result.size(); result_row_itr++) {
        for (int result_column_itr = 0; result_column_itr < result[result_row_itr].size(); result_column_itr++) {
            fout << result[result_row_itr][result_column_itr];

            if (result_column_itr != result[result_row_itr].size() - 1) {
                fout << " ";
            }
        }

        if (result_row_itr != result.size() - 1) {
            fout << "\n";
        }
    }

    fout << "\n";

    fout.close();

    return 0;
}
