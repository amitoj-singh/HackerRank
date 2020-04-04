#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   

    int T;
    cin >> T;
    char str[10000];
    for ( int i=0; i<T; i++)
    {
        cin >> str;
        for ( int j=0; j<strlen(str); j=j+2 )
            cout << str[j];
        cout << " ";
        for ( int j=1; j<strlen(str); j=j+2)
            cout << str[j];
        cout << endl;
    }
    return 0;
}
