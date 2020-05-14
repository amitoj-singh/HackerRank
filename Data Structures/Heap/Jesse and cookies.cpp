#include <bits/stdc++.h>

using namespace std;

int main() {

    int n, k;
    cin >> n >> k;

    priority_queue <int, vector<int>, greater<int> > pq; // min-heap declaration

    for (unsigned i = 0; i < n; i++){
        int temp;
        cin >> temp;
        pq.push(temp);
    }

    int count = 0;

    while (pq.top() < k) {
        count++;
        if (!pq.empty()) { // if (pq.empty() == false)
            int sweet1 = pq.top();
            pq.pop();
            if (!pq.empty()) {
                int sweet2 = pq.top();
                pq.pop();
                int newSweet = 1 * sweet1 + 2 * sweet2;
                pq.push(newSweet);
            }
            else {
                count = -1;
                break;
            }    
        }
        else {
            count = -1;
            break;
        }
        
    }

    cout << count;

    return 0;
}
