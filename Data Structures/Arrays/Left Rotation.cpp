#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, d, temp;
    vector<int> arr;
    cin >> n >> d;
    for (int i = 0; i < n; i++) {
        cin >> temp;
        arr.push_back(temp);
    }

    for (int i = d; i < n; i++) {
        cout << arr[i] << " ";
    }

    for (int i = 0; i < d; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}
