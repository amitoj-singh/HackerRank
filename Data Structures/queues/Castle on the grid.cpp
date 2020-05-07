    #include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Complete the minimumMoves function below.
int minimumMoves(vector<string> grid, int x1, int y1, int x2, int y2) {
    vector<int> g[10002];
    int n = grid.size();
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (grid[i][j] == '.') {
                int cur = i*n+j;
                for (int k =  i-1; k >= 0; k--) {
                    if (grid[k][j] == '.') {
                        int now = k*n+j;
                        g[cur].push_back(now);
                    }
                    else 
                        break;
                }
                for (int k =  i+1; k < n; k++) {
                    if (grid[k][j] == '.') {
                        int now = k*n+j;
                        g[cur].push_back(now);
                    }
                    else 
                        break;
                }
                for (int k = j-1; k >= 0; k--) {
                    if (grid[i][k] == '.') {
                        int now = i*n+k;
                        g[cur].push_back(now);
                    }
                    else
                        break;
                }
                for (int k = j+1; k < n; k++) {
                    if (grid[i][k] == '.') {
                        int now = i*n+k;
                        g[cur].push_back(now);
                    }
                    else
                        break;
                }
            }
        }
    }
    int start_pos = x1*n + y1;
    int done[10001] = {0}, dis[10001] = {0};
    queue<int> q;
    q.push(start_pos);
    done[start_pos] = 1;
    while (!q.empty()) {
        int now = q.front();
        q.pop();
        for (unsigned int i= 0; i < g[now].size(); i++) {
            int nxt = g[now][i];
            if (!done[nxt]) {
                done[nxt] = 1;
                dis[nxt] = dis[now]+1;
                q.push(nxt);
            }
        }
    }
    return dis[x2*n + y2];
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    vector<string> grid(n);

    for (int i = 0; i < n; i++) {
        string grid_item;
        getline(cin, grid_item);

        grid[i] = grid_item;
    }

    string startXStartY_temp;
    getline(cin, startXStartY_temp);

    vector<string> startXStartY = split_string(startXStartY_temp);

    int startX = stoi(startXStartY[0]);

    int startY = stoi(startXStartY[1]);

    int goalX = stoi(startXStartY[2]);

    int goalY = stoi(startXStartY[3]);

    int result = minimumMoves(grid, startX, startY, goalX, goalY);

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
