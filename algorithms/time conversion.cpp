#include <bits/stdc++.h>
#include <sstream>
#include <string>

using namespace std;

/*
 * Complete the timeConversion function below.
 */
string timeConversion(string s) {
    /*
     * Write your code here.
     */
    string temp = s.substr(0, 2);
    if (s[8] == 'A') {
        s.erase(8); // erase AM from string
        if (temp.compare("12") == 0) {
            string stemp = "00";
            s.erase(0, 2);
            return stemp.append(s);
        }
        return s.substr(0,8);
    }
    s.erase(8); // erase PM from string
    if (temp.compare("12") == 0) {
        return s;
    }
    int x = stoi(s.substr(0, 2)); // store value of hh in x by converting to int using stoi()
    x += 12;
    s.erase(0, 2);
    return to_string(x).append(s);
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string result = timeConversion(s);

    fout << result << "\n";

    fout.close();

    return 0;
}
