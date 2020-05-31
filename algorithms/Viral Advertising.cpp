#include <bits/stdc++.h>

using namespace std;

// Complete the viralAdvertising function below.
int viralAdvertising(int n) {
    int shares = 5, likes = shares/2, totalLikes = likes;
    for (int i = 2; i <= n; i++) {
        shares = likes*3;
        likes = shares/2;
        totalLikes += likes;
    }
    return totalLikes;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    int result = viralAdvertising(n);

    fout << result << "\n";

    fout.close();

    return 0;
}
