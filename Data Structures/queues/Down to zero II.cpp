#include <bits/stdc++.h>

using namespace std;

int main()
{
    int max = 1000001;
    int result[max];

    for (int i = 0; i < max; i++)
        result[i] = -1;
    
    result[0] = 0;
    result[1] = 1;
    result[2] = 2;
    result[3] = 3;

    for (int i = 0; i < max; i++) {
        if (result[i] == -1 || result[i] > result[i-1] + 1)
            result[i] = result[i-1] + 1;
        for (int j = 0; j <= i && j*i < max; j++) {
            if (result[j*i] == -1 || result[i] + 1 < result[j*i])
                result[j*i] = result[i] + 1;
        }
    }
    
    
    int q;
    cin >> q;

    for (int q_itr = 0; q_itr < q; q_itr++) {
        int n;
        cin >> n;

        cout << result[n] << "\n";
    }

    return 0;
}
