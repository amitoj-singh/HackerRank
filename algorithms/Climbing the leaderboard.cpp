#include <bits/stdc++.h>

using namespace std;

int main() {
    vector<int> rank, alice;
    int n, m, prev, curr, AliceScore;
    
    cin >> n >> prev;

    rank.push_back(-1);
    rank.push_back(prev);
    for (int i = 1; i < n; i++) {
        cin >> curr;
        if (prev != curr)
            rank.push_back(curr);
        prev = curr;
    }

    cin >> m;
    for (int i= 0; i < m; i++) {
        cin >> AliceScore;
        alice.push_back(AliceScore);
    }

    // O(n+m)
    int curRank = rank.size()-1;
    for (int i = 0; i < m; i++) {
        while(curRank > 0 && rank[curRank] < alice[i]) {
            curRank--;
        }
        if (rank[curRank] > alice[i] || rank[curRank] == -1) {
            curRank++;
        }
        cout << curRank << endl;
    }

    return 0;
}
