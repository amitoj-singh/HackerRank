#include<bits/stdc++.h>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int Q;
    cin >> Q;
    stack<string> undo;
    string S = "";
    while (Q--) {
        
        int Q_i;
        cin >> Q_i;

        switch (Q_i) {
            case 1:
                {
                    string temp;
                    cin >> temp;
                    undo.push(S);
                    S += temp;
                }
                break;
            case 2: 
                {
                    int k;
                    cin >> k;
                    undo.push(S);
                    S.erase(S.length()-k);
                }
                break;
            case 3:
                {
                    int k;
                    cin >> k;
                    cout << S[k-1] << endl;
                }
                break;
            case 4:
                {
                    S = undo.top();
                    undo.pop();
                }
                break;
        }
    }
    return 0;
}
