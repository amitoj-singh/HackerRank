#include <bits/stdc++.h>

using namespace std;

// Complete the substrCount function below.
long substrCount(int n, string s) {

    long count = n;
    for (int i = 0; i < n; i++) {
        char startChar = s[i];
        int diffCharIdx = -1;
        for (int j = i+1; j < n; j++) {
            char currChar = s[j];
            if (startChar == currChar) {
                if (diffCharIdx == -1 || (j - diffCharIdx) == (diffCharIdx - i))
                    count++;
            }
            else {
                if (diffCharIdx == -1)
                    diffCharIdx = j;
                else
                    break;
            }
        }
    }

    return count;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string s;
    getline(cin, s);

    long result = substrCount(n, s);

    fout << result << "\n";

    fout.close();

    return 0;
}
