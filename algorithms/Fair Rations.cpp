#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    int sum = 0, minLoaves = 0, carry = 0;
    for (int i = 0; i < n; i++) {
        int bread;
        cin >> bread;
        sum += bread;
        bread += carry;
        if (bread%2 == 1) {
            minLoaves += 2;
            carry = 1;
        } else {
            carry = 0;
        }

    }
    if (sum%2 == 1)
        cout << "NO";
    else
        cout << minLoaves;
    return 0;
}
