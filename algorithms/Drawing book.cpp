#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the pageCount function below.
 */
int pageCount(int n, int p) {

    int start;
    if (n%2 == 0)
        start = (p-1 <= n-p) ? 1 : n;
    else
        start = (p-1 < n-p) ? 1 : n;

    if (start == 1)
        return p/2;

    int count = 0;
    int cur = n;

    if (n%2 == 0) {        
        while(cur > p) {
            count++;
            cur -= 2;
        }
    } else {
        while (cur-1 > p) {
            count++;
            cur -= 2;
        }
    }

    return count;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    int p;
    cin >> p;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    int result = pageCount(n, p);

    fout << result << "\n";

    fout.close();

    return 0;
}
