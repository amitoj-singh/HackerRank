#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// class list {
//     public:
//         stack<int> s;
// };

// Complete the poisonousPlants function below.
int poisonousPlants(vector<int> p) {
    /*Below approach is enefficient and fails on 5 test cases*/
    // bool flag = true;
    // int days = -1;
    // while (flag) {
    //     flag = false;
    //     days++;
    //     for (int i = p.size()-1; i > 0; i--) {
    //         if (p[i] > p[i-1]) {
    //             p.erase(p.begin()+i);
    //             flag = true;
    //         }
    //     }
    // }
    // return days;

    int size = p.size();

    vector<vector<int>> s (size, vector<int> (size));
    int num_stacks = 0;
    for (unsigned int i = 0; i < p.size(); i++) {
        s[num_stacks].push_back(p[i]);
        if (i < p.size()-1 && p[i] < p[i+1]) {
            num_stacks++;
        }
    }

    // return 0;

    int days = 0;
    while (s.size() != 1) {
        for (unsigned int i = 1; i < s.size(); i++) {
            s[i].erase(s[i].begin());
            if (s[i-1].end() >= s[i].begin()) {
                s[i-1].insert(s[i-1].end(), s[i].begin(), s[i].end());
                s.erase(s.begin()+i);
                i--;
            }
        }
        days++;
    }
    return days;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string p_temp_temp;
    getline(cin, p_temp_temp);

    vector<string> p_temp = split_string(p_temp_temp);

    vector<int> p(n);

    for (int i = 0; i < n; i++) {
        int p_item = stoi(p_temp[i]);

        p[i] = p_item;
    }

    int result = poisonousPlants(p);

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
