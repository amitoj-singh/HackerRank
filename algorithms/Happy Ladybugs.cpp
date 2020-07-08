#include <bits/stdc++.h>

using namespace std;

// Complete the happyLadybugs function below.
string happyLadybugs(string b) {
    string result = "NO";
    bool underScore = false;
    int n = b.size();
    map<char, int> freq;
    map<char, int>::iterator itr;
    for (int i = 0; i < n; i++) {
        freq[b[i]]++;
        if (b[i] == '_')
            underScore = true;
    }
    for (itr = freq.begin(); itr != freq.end(); itr++) {
        if (itr->first != '_' && itr->second == 1) {
            return "NO";
        }
    }
    if (underScore)
        return "YES";

    if (b[0] != b[1] || b[n-1] != b[n-2])
        return "NO";

    for (int i = 1; i < n-1; i++) {
        if (b[i] != b[i-1] && b[i] != b[i+1]) {
            return "NO";
        }
    }
    return "YES";
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int g;
    cin >> g;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int g_itr = 0; g_itr < g; g_itr++) {
        int n;
        cin >> n;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        string b;
        getline(cin, b);

        string result = happyLadybugs(b);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}
