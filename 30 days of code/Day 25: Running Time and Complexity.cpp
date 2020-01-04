#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int T, n, remainder;
    bool isPrime = true;
    vector<int> vect;
    cin >> T;
    for (int i = 0; i < T; i++) {
        cin >> n;
        vect.push_back(n);
    }

    for (int i = 0; i < T; i++) {
        bool isPrime = true;
        if (vect[i] == 1) {
            cout << "Not prime\n";
            continue;
        }

        for (int j = 2; j <= sqrt(vect[i]); j+=1) {
            remainder = vect[i] % j;
            if (remainder == 0) {
                cout << "Not prime\n";
                isPrime = false;
                break;
            }
        }
        if (isPrime) {
            cout << "Prime\n";
        }
    }  
    return 0;
}
