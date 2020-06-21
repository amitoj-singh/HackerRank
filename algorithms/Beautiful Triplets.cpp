#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

bool binarySearch(vector<int> arr, int start, int end, int x) {
    if (start > end)
        return false;
    int mid = (start + end) / 2;
    if (arr[mid] == x)
        return true;
    else if (arr[mid] < x)
        return binarySearch(arr, mid+1, end, x);
    else
        return binarySearch(arr, start, mid-1, x);
}

// Complete the beautifulTriplets function below.
int beautifulTriplets(int d, vector<int> arr) {
    int n = arr.size();
    int count = 0;
    map<int, int> myMap;
    map<int, int>::iterator itr;
    for (int i = 0; i < n; i++) {
        myMap[arr[i]]++;
        if (myMap[arr[i]-d] > 0 && myMap[arr[i]-2*d] > 0)
            count++;
    }

    return count;

}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string nd_temp;
    getline(cin, nd_temp);

    vector<string> nd = split_string(nd_temp);

    int n = stoi(nd[0]);

    int d = stoi(nd[1]);

    string arr_temp_temp;
    getline(cin, arr_temp_temp);

    vector<string> arr_temp = split_string(arr_temp_temp);

    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        int arr_item = stoi(arr_temp[i]);

        arr[i] = arr_item;
    }

    int result = beautifulTriplets(d, arr);

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
