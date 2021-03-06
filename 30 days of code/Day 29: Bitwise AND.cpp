#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

int main()
{
    int t;
    cin >> t;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int t_itr = 0; t_itr < t; t_itr++) {
        string nk_temp;
        getline(cin, nk_temp);

        vector<string> nk = split_string(nk_temp);

        int n = stoi(nk[0]);

        int k = stoi(nk[1]);

        // Unoptimized initial solution
        // vector<int> set;
        // vector<int> res;
        // vector<int> fin;
        // for (int  i = 1; i <= n; i++) 
        //     set.push_back(i);
        // for (int i = 0; i < set.size(); i++) {
        //     int a = i;
        //     for (int j = a+1; j < set.size(); j++) {
        //         int b = j;
        //         res.push_back(a&b);
        //     }
        // }
        // int size = res.size();
        // for (int i = 0; i < size; i++) {
        //     if (res[i] < k)
        //         fin.push_back(res[i]);
        //     size = res.size();
        // }

        // sort(fin.begin(), fin.end());
        // cout << fin.back() << endl;

        // Optimized solution by observing a pattern in the solution obtained
        if ((k|k-1) > n && k%2 == 0){ 
            cout << k-2 << endl;
        }
        else { // if ( (k|k-1) <= n || k%2 !=0 )
            cout << k-1 << endl;
        }
    }
    return 0;
}

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}
