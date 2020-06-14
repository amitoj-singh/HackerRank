#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Complete the queensAttack function below.
int queensAttack(int n, int k, int r_q, int c_q, vector<vector<int>> obstacles) {
    int top = n - r_q;
    int right = n - c_q;
    int bottom = r_q - 1;
    int left = c_q - 1;
    int d1 = min(left, top);
    int d2 = min(top,  right);
    int d3 = min(right, bottom);
    int d4 = min(bottom, left);
    int steps;

    for (int i = 0; i < k; i++) {
        int r_o = obstacles[i][0];
        int c_o = obstacles[i][1];

        if (r_o < r_q) { // obstacle may lie in d4, bottom or d3
            if (c_o < c_q && abs(r_q - r_o) == abs(c_q - c_o)) { // obstacle in d4
                steps = abs(r_q - r_o) - 1;
                if (steps < d4)
                    d4 = steps;
            }
            else if (c_o == c_q) { // obstacle is in bottom
                steps = abs(r_q - r_o) - 1;
                if (steps < bottom)
                    bottom = steps;
            }
            else if (c_o > c_q && abs(r_q - r_o) == abs(c_q - c_o)) { // obstacle in d3
                steps = abs(r_q - r_o) - 1;
                if (steps < d3)
                    d3 = steps;
            }
        }
        else if (r_o == r_q) { // obstacle is in left or right
            if (c_o < c_q) { // obstacle in left
                steps = abs(c_q - c_o) - 1;
                if (steps < left)
                    left = steps;
            }
            else { // obstacle in right
                steps = abs(c_o - c_q) - 1;
                if (steps < right)
                    right = steps;
            }
        }
        else { // if (r_o > r_q) // obstacle may lie in d1, top or d2
            if (c_o < c_q && abs(r_q - r_o) == abs(c_q - c_o)) { // obstacle in d1
                steps = abs(r_q - r_o) - 1;
                if (steps < d1)
                    d1 = steps;
            }
            else if (c_o == c_q) { // obstacle in top
                steps = abs(r_o - r_q) - 1;
                if (steps < top)
                    top = steps;
            }
            else if (c_o > c_q && abs(r_q - r_o) == abs(c_q - c_o)) { // obstacle in d2
                steps = abs(r_q - r_o) - 1;
                if (steps < d2)
                    d2 = steps;
            }
        }
    }
    int availableMoves = top + right + bottom + left + d1 + d2 + d3 + d4;
    return availableMoves;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string nk_temp;
    getline(cin, nk_temp);

    vector<string> nk = split_string(nk_temp);

    int n = stoi(nk[0]);

    int k = stoi(nk[1]);

    string r_qC_q_temp;
    getline(cin, r_qC_q_temp);

    vector<string> r_qC_q = split_string(r_qC_q_temp);

    int r_q = stoi(r_qC_q[0]);

    int c_q = stoi(r_qC_q[1]);

    vector<vector<int>> obstacles(k);
    for (int i = 0; i < k; i++) {
        obstacles[i].resize(2);

        for (int j = 0; j < 2; j++) {
            cin >> obstacles[i][j];
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    int result = queensAttack(n, k, r_q, c_q, obstacles);

    fout << result << "\n";

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
