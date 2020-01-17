#include <bits/stdc++.h>

using namespace std;

// Complete the twoStrings function below.
string twoStrings(string s1, string s2) {
    map<char, int> substr; // hashmap to store the characters of the string and an integer as its value
    for (int i = 0; i < s1.length(); i++) {
        substr[s1[i]]++; // store each character of s1 string as key in the hashmap and increment its value.
    }

    for (int i = 0; i < s2.length(); i++) {
        if (--substr[s2[i]] > 0) { // for every character in s2 (pre)decrement its value, whenever we found the value to be greater than zero means we found a substring
            return "YES";
        }
    }
    return "NO";
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int q;
    cin >> q;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int q_itr = 0; q_itr < q; q_itr++) {
        string s1;
        getline(cin, s1);

        string s2;
        getline(cin, s2);

        string result = twoStrings(s1, s2);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}
