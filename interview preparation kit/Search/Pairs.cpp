#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> arr;
    for (int i = 0; i < n; i++) {
        int temp;
        cin >> temp;
        arr.push_back(temp);
    }

    sort(arr.begin(), arr.end());

    // for (int i = 0; i < n; i++) {
    //     cout << arr[i] << "\n";
    // }

    int i = 0, j = 1, count = 0;

    // Initial approach where run time is close to O(n^2) using two pointers
    /*********************************************************
                                                             *
    // for (; i < n-1; i++) {                                *
    //     j = n-1;                                          *
    //     for (; abs(arr[i]-arr[j]) > k && j > i; j--);     *
    //     if (abs(arr[i]-arr[j]) == k) count++;             *
    // }                                                     *       
                                                             *
    *********************************************************/

    // More efficient approach using two pointers. Run time close to O(n)
    while (j < n) {
        int diff = arr[j] - arr[i];

        if (diff == k) {
            count++;
            j++;
        } else if (diff < k) {
            j++;
        } else {
            i++;
        }
    }

    cout << count;

    return 0;
}
