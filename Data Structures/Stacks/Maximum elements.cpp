#include<bits/stdc++.h>
using namespace std;

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int n;
    cin >> n;
    stack <int> s;
    while (n--) {
        int typ, x;
        cin >> typ;
        if (typ == 1) {
            cin >> x;
            if (s.empty()) {
                s.push(x);
            } else {
                s.push(max(x, s.top()));
            }
        } else if (typ == 2) {
            s.pop();
        } else {
            cout << s.top() << endl;
        }
    }
    return 0;
}
