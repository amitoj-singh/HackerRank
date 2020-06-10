#include <bits/stdc++.h>

using namespace std;

// Complete the extraLongFactorials function below.
void extraLongFactorials(int n) {

    vector<int> fact, temp;
    int x = n;

    while (x > 0) {
        fact.push_back(x%10);
        x /= 10;
    }
    n--;

    while(n > 0) {
        x = n;
        int carry = 0;

        for (int i = 0; i < fact.size(); i++) {
            int mul = carry + x * fact[i];
            carry = mul / 10;
            temp.push_back(mul%10);
        }

        while (carry > 0) {
            temp.push_back(carry%10);
            carry /= 10;
        }

        fact.clear();
        fact = temp;
        temp.clear();

        n--;
    }

    for (int i = fact.size()-1; i >= 0; i--) {
        cout << fact[i];
    }
}

int main()
{
    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    extraLongFactorials(n);

    return 0;
}
