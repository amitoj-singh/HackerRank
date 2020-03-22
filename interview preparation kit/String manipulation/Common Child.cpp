#include <bits/stdc++.h>

using namespace std;

// Complete the commonChild function below.
//https://en.wikipedia.org/wiki/Longest_common_subsequence_problem
int commonChild(string s1, string s2) {
    int size = s1.length()+1;
    vector<vector<int>> arr (size, vector<int> (size));
    for (int i = 0; i < size; i++) {
        arr[i][0] = 0;
        arr[0][i] = 0;
    }

    for (int i = 1; i < size; i++) {
        for (int j = 1; j < size; j++) {
            if (s1[i-1] == s2[j-1])
                arr[i][j] = arr[i-1][j-1] + 1;
            else 
                arr[i][j] = max(arr[i-1][j], arr[i][j-1]);
        }
    }

    return arr[size-1][size-1];

}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s1;
    getline(cin, s1);

    string s2;
    getline(cin, s2);

    int result = commonChild(s1, s2);

    fout << result << "\n";

    fout.close();

    return 0;
}
