#include <bits/stdc++.h>

using namespace std;

// Complete the timeInWords function below.
string timeInWords(int h, int m) {
    vector<string> numbers = {
        "zero", 
        "one",
        "two",
        "three",
        "four",
        "five",
        "six",
        "seven",
        "eight",
        "nine",
        "ten",
        "eleven",
        "twelve",
        "thirteen",
        "fourteen",
        "fifteen",
        "sixteen",
        "seventeen",
        "eighteen",
        "nineteen",
        "twenty",
        "twenty one",
        "twenty two",
        "twenty three",
        "twenty four",
        "twenty five",
        "twenty six",
        "twenty seven",
        "twenty eight",
        "twenty nine"
    };
    string time = "";
    if (m == 0) {
        time += numbers[h] + " o' clock";
    } else if (m >= 1 && m <= 9) {
        time += numbers[m] + " minute past " + numbers[h];
    } else if (m == 15) {
        time += "quarter past " + numbers[h];
    } else if (m <= 29) {
        time += numbers[m] + " minutes past " + numbers[h];
    } else if (m == 30) {
        time += "half past " + numbers[h];
    } else if (m == 45) {
        time += "quarter to " + numbers[h+1];
    } else {
        m = 60 - m;
        time += numbers[m] + " minutes to " + numbers[h+1];
    }


    return time;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int h;
    cin >> h;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    int m;
    cin >> m;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string result = timeInWords(h, m);

    fout << result << "\n";

    fout.close();

    return 0;
}
