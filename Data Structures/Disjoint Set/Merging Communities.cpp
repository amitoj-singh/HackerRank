#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int find(int x, vector<int> &r) {
    if (r[x] != x)
        r[x] = find(r[x], r);
    return r[x];
}


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int n, q;
    cin >> n >> q;

    vector<int> root(n+1), count(n+1);

    for (int i = 0; i <= n; i++) {
        root[i] = i;
        count[i] = 1;
    } 

    while (q--) {
        char type;
        cin >> type;
        if (type == 'M') {
            int i, j;
            cin >> i >> j;
            int r_i = find(i, root);
            int r_j = find(j, root);

            if (r_i != r_j) {
                root[r_i] = r_j;
                count[r_j] += count[r_i];
                count[r_i] = 0;
            }
        } 
        else if (type == 'Q') {
            int i;
            cin >> i;
            cout << count[find(i, root)] << endl;
        }
    }
    return 0;
}
