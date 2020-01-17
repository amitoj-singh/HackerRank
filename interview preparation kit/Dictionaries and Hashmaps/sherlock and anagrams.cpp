#include <bits/stdc++.h>

using namespace std;

bool isAnagram(string s1, string s2) {
    int charFreq[26] = {0};
    for (int i = 0; i < s1.length(); i++) { // length of s1 = length of s2. This is condition is checked before calling function.
        charFreq[s1[i]-'a']++; // adding 1 for every character of s1
        charFreq[s2[i]-'a']--; // subtracting 1 for every character of s2
    }

    for (int i = 0; i < 26; i++) {
        if (charFreq[i] != 0) // if string is not anagramatic then there will be atleast one element whose value will be non zero.
            return false;
    }

    return true;
}


// Complete the sherlockAndAnagrams function below.
int sherlockAndAnagrams(string s) {
    int count = 0;
    vector<string> substrings;

    int len = s.length();
    for (int i = 0; i < len; i++) {
        for (int j = 1; j <= len-i; j++) {
            substrings.push_back(s.substr(i, j));
        }
    }
    
    int numOfSubstrings = substrings.size();
    for (int i = 0; i < numOfSubstrings; i++) {
        for (int j = i+1; j < numOfSubstrings; j++) {
            if (substrings[i].length() == substrings[j].length() && isAnagram(substrings[i], substrings[j])) {
                count++;
            }
        }
    }

    return count;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int q;
    cin >> q;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int q_itr = 0; q_itr < q; q_itr++) {
        string s;
        getline(cin, s);

        int result = sherlockAndAnagrams(s);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}
