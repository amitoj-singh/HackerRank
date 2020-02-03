#include <bits/stdc++.h>

using namespace std;

// Complete the staircase function below.
void staircase(int n) {
    for (int i = 1; i <= n; i++) {
        int num_spaces = n-i;
        int num_hashes = i;
        while (num_spaces--)
            cout << " ";
        while (num_hashes--)
            cout << "#";
        cout << endl;
    }


}

int main()
{
    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    staircase(n);

    return 0;
}
