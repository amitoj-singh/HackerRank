#include <bits/stdc++.h>

using namespace std;

// Complete the strangeCounter function below.
long strangeCounter(long t) {
    long value = 3, i = 1;

    while (i < t) {
        i += value;
        value *= 2;
    }

    if (i == t)
        return value;

    value = 1;
    i--;

    while (i > t) {
        i--;
        value++;
    }
    
    return value;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    long t;
    cin >> t;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    long result = strangeCounter(t);

    fout << result << "\n";

    fout.close();

    return 0;
}
