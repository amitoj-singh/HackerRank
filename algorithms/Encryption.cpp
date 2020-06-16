#include <bits/stdc++.h>

using namespace std;

// Complete the encryption function below.
string encryption(string s) {
    int l = s.length();
    int r = floor(sqrt(l));
    int c = ceil(sqrt(l));
    if (r == c)
        r--;
    string newS = "";
    for (int i = 0; i <= r; i++) {
        int x = i;
        while (x < l) {
            newS += s[x];
            x += c;
        }
        newS += " ";
    }
    return newS;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string result = encryption(s);

    fout << result << "\n";

    fout.close();

    return 0;
}
