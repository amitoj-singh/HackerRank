#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    /*
        * Da = Actual date on which book is returned
        * Ma = Actual month in which book is returned   
        * Ya = Actual year in which book is returned
        * De = Expected date on which book is returned    
        * Me = Expected month in which book is returned
        * Ye = Expected year in which book is returned
    */
    int Da, Ma, Ya, De, Me, Ye, fine;
    cin >> Da >> Ma >> Ya >> De >> Me >> Ye;

    if (Ye == Ya) { // if the book is returned in same year
        if (Me == Ma) { // if the book is returned in same month
            if (De >= Da ) // if book is returned before expected date in same month and year
                fine = 0;
            else // if book is returned in expected month but after expected date
                fine = 15 * (Da - De);
        }
        else if (Me > Ma) // if book is returned in same year but before expected month
            fine = 0;
        else
            fine = 500 * (Ma - Me); // if book is returned in same year but after expected month
    }
    else if (Ye > Ya) // if book is returned before expected year
        fine = 0;
    else // if book is returned after expected year
        fine = 10000;
    
    cout << fine;

    return 0;
}
