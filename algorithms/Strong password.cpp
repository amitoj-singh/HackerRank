#include <bits/stdc++.h>

using namespace std;

// Complete the minimumNumber function below.
int minimumNumber(int n, string password) {
    // Return the minimum number of characters to make the password strong
    int upper = 0, lower = 0, digit = 0, specialChar = 0, needed = 0;
    for (int i = 0; i < password.size(); i++) {
        if (password[i] >= 65 && password[i] <= 90)
            upper++;
        else if (password[i] >= 97 && password[i] <= 122)
            lower++;
        else if (password[i] >= 48 && password[i] <= 57)
            digit++;
        else 
            specialChar++;
    }
    int total = upper + lower + digit + specialChar;
    cout << upper << " " << lower << " " << digit << " " << specialChar << endl;
    cout << needed << endl;
    if (upper == 0)
        needed++;
    if (lower == 0)
        needed++;
    if (digit == 0)
        needed++;
    if (specialChar == 0)
        needed++;
    if ((total + needed) < 6)
        needed += 6 - (total + needed);
    cout << needed << endl;
    return needed;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string password;
    getline(cin, password);

    int answer = minimumNumber(n, password);

    fout << answer << "\n";

    fout.close();

    return 0;
}
