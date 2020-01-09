#include <bits/stdc++.h>

using namespace std;

// Complete the repeatedString function below.
long repeatedString(string s, long n) {
    int lengthOfs = s.length(); // length of the string
    int numberOfa = 0; //number of 'a' in a string
    long counter_a; // number of 'a' in the infinite string
    long numOfStrings; // number of complete strings that will be included in the combined string of length n
    bool allAs = true; // considering all the characters of a string to be 'a'

    // if string contain only a's then we directly return n
    for (int i = 0; i < lengthOfs; i++) {
        if (s[i] != 'a') {
            allAs = false;
            break;
        }
    }
    if (allAs)
        return n;

    // this will count number of 'a' in the given string
    for (int i = 0; i < lengthOfs; i++) {
        if (s[i] == 'a')
            numberOfa++;
    }

    numOfStrings = floor(n / lengthOfs); // considering only integer part 
    counter_a = numberOfa * numOfStrings; // number of a's in complete strings included in the infinite string
    n %= lengthOfs; // updating n to consider partial characters left out of the last string

    // calculating number of a's in the last string
    for (int i = 0; i < lengthOfs && n > 0; i++) {
        if (s[i] == 'a') {
            counter_a++;
            n--;
        } else {
            n--;
        }
    }
    return counter_a;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    long n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    long result = repeatedString(s, n);

    fout << result << "\n";

    fout.close();

    return 0;
}
