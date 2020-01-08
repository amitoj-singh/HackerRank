#include <bits/stdc++.h>

using namespace std;

// Complete the countingValleys function below.
// ALGO:
// whenever we go down from 0 (i.e. sea level) we must come back to 0. Using this fact whenever We encounter 'D' from sea level we can count it as a valley.
int countingValleys(int n, string s) {
    int result = 0, counter = 0;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == 'U') {
            counter++;
        } else if (s[i] == 'D') {
            counter--;
            if (counter == -1) {
                result++;
            }
        }        
    }
    return result;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string s;
    getline(cin, s);

    int result = countingValleys(n, s);

    fout << result << "\n";

    fout.close();

    return 0;
}
