#include <bits/stdc++.h>

using namespace std;

// Complete the pangrams function below.
string pangrams(string s) {
    transform(s.begin(), s.end(), s.begin(), ::toupper);
    set<char> alphabet;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] >= 65 && s[i] <= 90)
            alphabet.insert(s[i]);
    }
    if (alphabet.size() == 26)
        return "pangram";
    return "not pangram";
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string result = pangrams(s);

    fout << result << "\n";

    fout.close();

    return 0;
}
