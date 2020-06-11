#include <bits/stdc++.h>

using namespace std;

// Complete the appendAndDelete function below.
string appendAndDelete(string s, string t, int k) {
    int min = 0, max, sizeS = s.length(), sizeT = t.size(), i = 0;
    
    // i will be the index of first unequal character in string 's' and 't'
    while (i < sizeT && i < sizeS && s[i] == t[i])
        i++;

    // min will hold the minimum number of operations required to convert 's' into 't'
    if (i < sizeS)
        min += sizeS - i; 

    if (i < sizeT)
        min += sizeT - i;

    max = sizeS + sizeT; // max number of operations

    if (k > max || k == min) { // we can perform delete operation on empty string any number of times
        return "Yes";
    }

    if (k > min) { // and (k < max)
        // This is the most tricky part.
        // On solving a few examples I noticed that if min is odd and k is odd then answer is "Yes", similarly if min is even and k is even then also answer is "Yes"
        if ((min%2 == 0 && k%2 == 0) || (min%2 == 1 && k%2 == 1))
            return "Yes";
    }

    return "No"; // All other cases will fail
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string t;
    getline(cin, t);

    int k;
    cin >> k;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string result = appendAndDelete(s, t, k);

    fout << result << "\n";

    fout.close();

    return 0;
}
