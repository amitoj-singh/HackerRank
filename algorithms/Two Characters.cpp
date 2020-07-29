#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

// Complete the alternate function below.
int alternate(string s) {
    int maxL = 0;
    set<char> charsSet;
    for (unsigned i = 0; i < s.size(); i++) {
        charsSet.insert(s[i]);
    }
    vector<char> chars (charsSet.begin(), charsSet.end());
    
    for (unsigned i = 0; i < chars.size(); i++) {
        for (unsigned j = i+1; j < chars.size(); j++) {
            char x = chars[i], y = chars[j];
            int L = 0;
            string temp = "";
            for (unsigned idx = 0; idx < s.size(); idx++) {
                if (s[idx] == x || s[idx] == y) {
                    if (temp.size() > 0 && temp[temp.size()-1] == s[idx]) {
                        L = 0;
                        break;
                    }
                    temp += s[idx];
                    L++;
                }
            }
            cout << temp;
            if (L > maxL)
                maxL = L;
        }
    }
    return maxL;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string l_temp;
    getline(cin, l_temp);

    int l = stoi(ltrim(rtrim(l_temp)));

    string s;
    getline(cin, s);

    int result = alternate(s);

    fout << result << "\n";

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}
