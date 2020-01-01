#include <bits/stdc++.h>

using namespace std;

void swap(int &x, int &y)
{
    int temp;
    temp = x;
    x = y;
    y = temp;
}

int main() {
    int n, swap_counter=0;
    cin >> n;
    vector<int> a(n);
    
    for(int a_i = 0; a_i < n; a_i++){
        cin >> a[a_i];
    }
    
    // Write Your Code Here
    for ( int i = 0; i < n; i++ ) {
        for ( int j = i + 1; j < n; j++ ) {
            if ( a [i] > a [j] ) {
                swap(a [i], a [j]);
                swap_counter++;
            }
        }
    } 

    cout << "Array is sorted in " << swap_counter << " swaps." << endl;
    cout << "First Element: " << a[0] << endl;
    cout << "Last Element: " << a[n-1];

        return 0;
}
