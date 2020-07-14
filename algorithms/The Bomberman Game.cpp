#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// makes a grid for next second
void nextSecondGrid(vector<vector<int>> &gridArr, int sec) {
    int r = gridArr.size(), c = gridArr[0].size();

    if (sec%2 == 0) {
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                if (gridArr[i][j] == 2)
                    gridArr[i][j] = 1;
                else
                    gridArr[i][j] = 3;
            }
        }
    } 
    else {
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                if (gridArr[i][j] == 3)
                    gridArr[i][j] = 2;
                else if (gridArr[i][j] == 1) {
                    gridArr[i][j] = 0;
                    if (i+1 < r && gridArr[i+1][j] > 1)
                        gridArr[i+1][j] = 0;
                    if (i-1 >= 0 && gridArr[i-1][j] > 1)
                        gridArr[i-1][j] = 0;
                    if (j+1 < c && gridArr[i][j+1] > 1)
                        gridArr[i][j+1] = 0;
                    if (j-1 >= 0 && gridArr[i][j-1] > 1)
                        gridArr[i][j-1] = 0;
                }
            }
        }
    }
}

// changes intermediate grid to resultant string's grid
vector<string> intToStr(vector<vector<int>> gridArr) {
    int r = gridArr.size(), c = gridArr[0].size();
    vector<string> result;

    for (int i = 0; i < r; i++) {
        string s = "";
        for (int j = 0; j < c; j++) {
            if (gridArr[i][j] == 2)
                s += 'O';
            else
                s += '.';
        }
        result.push_back(s);
    }

    return result;
}

// Complete the bomberMan function below.
vector<string> bomberMan(int n, vector<string> grid) {

    vector<string> result;
    int r = grid.size(), c = grid[0].size();

    cout << r << " " << c << endl;

    if (n == 1)
        return grid;

    if (n%2 == 0) {
        string s(c, 'O');
        for (int i = 0; i < r; i++) {
            result.push_back(s);
        }
        return result;
    }

    vector<vector<int>> gridArr (r, vector<int>(c));

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (grid[i][j] == '.')
                gridArr[i][j] = 3;
            else
                gridArr[i][j] = 1;
        }
    }

    if (!((n+1)%4)) {
        nextSecondGrid(gridArr, n);
        return intToStr(gridArr);
    }

    for (int i = 1; i <= 3; i++)
        nextSecondGrid(gridArr, i);
    
    return intToStr(gridArr);
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string rcn_temp;
    getline(cin, rcn_temp);

    vector<string> rcn = split_string(rcn_temp);

    int r = stoi(rcn[0]);

    int c = stoi(rcn[1]);

    int n = stoi(rcn[2]);

    vector<string> grid(r);

    for (int i = 0; i < r; i++) {
        string grid_item;
        getline(cin, grid_item);

        grid[i] = grid_item;
    }

    vector<string> result = bomberMan(n, grid);

    for (int i = 0; i < result.size(); i++) {
        fout << result[i];

        if (i != result.size() - 1) {
            fout << "\n";
        }
    }

    fout << "\n";

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
