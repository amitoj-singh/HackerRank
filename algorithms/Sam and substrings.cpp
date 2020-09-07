#include <bits/stdc++.h>

using namespace std;

// Complete the substrings function below.
long long int substrings(string n) {
    long long int result = 0, mul = 1, mod = 1000000007;
    for (int i = n.size()-1; i >= 0; i--) {
        result = (result + (n[i]-'0')*mul*(i+1)) % mod;
        mul = (mul*10 + 1) % mod;
    }
    return result;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string n;
    getline(cin, n);

    long long int result = substrings(n);

    fout << result << "\n";

    fout.close();

    return 0;
}
