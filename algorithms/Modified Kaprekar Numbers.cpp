#include <bits/stdc++.h>

using namespace std;

// Complete the kaprekarNumbers function below.
bool isKaprekar(long n) {
    string sqr = to_string(n*n);
    int d = to_string(n).length();
    string r, l;
    if (sqr.length()%2 == 0) {
        r = sqr.substr(d, d);
        l = sqr.substr(0, d);
    } else {
        r = sqr.substr(d-1, d);
        l = sqr.substr(0, d-1);
    }

    if (r == "")
        r = "0";
    if (l == "")
        l = "0";

    if (stoi(r) + stoi(l) == n)
        return true;

    return false;
}       

void kaprekarNumbers(int p, int q) {
    bool found = false;
    for (int i = p; i <= q; i++) {
        if (isKaprekar(i)){
            cout << i << " ";
            found = true;
        }
    }

    if (!found)
        cout << "INVALID RANGE";
}

int main()
{
    int p;
    cin >> p;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    int q;
    cin >> q;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    kaprekarNumbers(p, q);

    return 0;
}



