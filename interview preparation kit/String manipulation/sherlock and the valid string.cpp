#include <bits/stdc++.h>

using namespace std;

// Complete the isValid function below.
string isValid(string s) {
    if (s.length() <= 3)
        return "YES";

    vector<int> letters(26, 0);
    for (int i = 0; i < s.length(); i++) {
        letters[s[i]-'a']++;
    }
    
    sort(letters.begin(), letters.end());
    
    int i = 0; 
    while (letters[i] == 0)
        i++;
    
    int min = letters[i];
    int max = letters[25];
    
    if (min == max)
        return "YES";
    else if (((max - min == 1) && (max > letters[24])) || (min == 1) && (letters[i+1] == max))
        return "YES";
    return "NO";
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string result = isValid(s);

    fout << result << "\n";

    fout.close();

    return 0;
}
