#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// height stack stores the heights of the buildings
// pos stack stores the corresponding positions of heights
stack<int> height, pos; 
int maxRect = 0;
unsigned int i = 0;
int tempPos, tempH;

void popOut() { // pops out from stacks on a given condition and calculates the area of rectangle formed
    tempH = height.top();
    height.pop();
    tempPos = pos.top();
    pos.pop();
    int tempRect = tempH * (i - tempPos);
    maxRect = max(tempRect, maxRect);
}

// Complete the largestRectangle function below.
long largestRectangle(vector<int> h) {   

    for (; i < h.size(); i++) {
        int curH = h[i];
        if (height.empty() || curH > height.top()) {
            height.push(curH);
            pos.push(i);
        } else if (curH < height.top()) {
            while (!height.empty() && curH < height.top()) {
                popOut();
            }
            height.push(curH);
            pos.push(tempPos);
        }
    }

    while (!height.empty()) {
        popOut();
    }

    return long(maxRect);
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string h_temp_temp;
    getline(cin, h_temp_temp);

    vector<string> h_temp = split_string(h_temp_temp);

    vector<int> h(n);

    for (int i = 0; i < n; i++) {
        int h_item = stoi(h_temp[i]);

        h[i] = h_item;
    }

    long result = largestRectangle(h);

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
