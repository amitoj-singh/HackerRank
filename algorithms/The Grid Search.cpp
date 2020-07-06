#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Complete the gridSearch function below.
string gridSearch(vector<string> G, vector<string> P) {
    int R = G.size(); // rows in grid
    int C = G[0].length(); // columns in grid
    int r = P.size(); // rows in pattern
    int c = P[0].length(); //columns in pattern

    // cout << "R = " << R << " C = " << C << " r = " << r << " c = " << c << endl;

    string result = "";

    for (int i = 0; i <= R-r; i++) {
        for (int j = 0; j <= C-c; j++) {
            if (G[i][j] == P[0][0]) {
                int x, y, m, n;
                for (x = 0, m = i; m < i+r && x < r; m++, x++) {
                    for (y = 0, n = j; j < j+c && y < c; n++, y++) {
                        if (G[m][n] != P[x][y]) { // if the characters in the grid are unequal then exit out of both loops
                            m = i+r;
                            n = j+c;
                            x = r;
                            y = c;
                        }
                    }
                }
                if ((m == (i+r)) && (n == (j+c)) && (x == r) && (y == c)) { // we found pattern in the grid if this condition meets
                    result = "YES";
                }
            }
        }
    }
    if (result.empty())
        result = "NO";
    return result;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int t;
    cin >> t;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int t_itr = 0; t_itr < t; t_itr++) {
        string RC_temp;
        getline(cin, RC_temp);

        vector<string> RC = split_string(RC_temp);

        int R = stoi(RC[0]);

        int C = stoi(RC[1]);

        vector<string> G(R);

        for (int i = 0; i < R; i++) {
            string G_item;
            getline(cin, G_item);

            G[i] = G_item;
        }

        string rc_temp;
        getline(cin, rc_temp);

        vector<string> rc = split_string(rc_temp);

        int r = stoi(rc[0]);

        int c = stoi(rc[1]);

        vector<string> P(r);

        for (int i = 0; i < r; i++) {
            string P_item;
            getline(cin, P_item);

            P[i] = P_item;
        }

        string result = gridSearch(G, P);

        fout << result << "\n";
    }

    fout.close();

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
