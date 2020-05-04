#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int q;
    cin >> q;

    stack<int> enqueueStack, dequeueStack;

    while(q--) {
        int type;
        cin >> type;
        
        switch(type) {
            case 1: {
                int x;
                cin >> x;
                enqueueStack.push(x);
                break;
            }
                
            case 2:
            case 3: {
                if (dequeueStack.empty()) {
                    while(!enqueueStack.empty()) {
                        dequeueStack.push(enqueueStack.top());
                        enqueueStack.pop();
                    }
                }
                if (type == 2)
                    dequeueStack.pop();
                else
                    cout << dequeueStack.top() << endl;
            }
        }
    }
    return 0;
}
