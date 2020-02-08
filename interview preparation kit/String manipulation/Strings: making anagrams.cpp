#include <bits/stdc++.h>

using namespace std;

// Complete the makeAnagram function below.
int makeAnagram(string a, string b) {

    unordered_map<char, int> freq;
    int num_deletions = 0;
    int lenA = a.length(), lenB = b.length();

    for (int i = 0; i < lenA; i++)
        freq[a[i]]++; // adding frequencies of characters in string a
    for (int i = 0; i < lenB; i++)
        freq[b[i]]--; // subtracting frequencies of characters in string b

    for (char itr = 'a'; itr <= 'z'; itr++) {
        num_deletions += abs(freq[itr]);
    }
    
    return num_deletions;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string a;
    getline(cin, a);

    string b;
    getline(cin, b);

    int res = makeAnagram(a, b);

    fout << res << "\n";

    fout.close();

    return 0;
}
