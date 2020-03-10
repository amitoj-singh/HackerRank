#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition (vector<int>&arr, int low, int high) {
    int p_index = low, pivot = arr[high];
    for(int i = low; i < high; i++) {
        if (arr[i] < pivot) {
            swap(&arr[i], &arr[p_index]);
            p_index++;
        }
    }
    swap(&arr[p_index], &arr[high]);
    return p_index;
}

void quicksort(vector<int>&arr, int low, int high) {
    if (low <= high) {
        int p_index = partition(arr, low, high);
        quicksort(arr, low, p_index-1);
        quicksort(arr, p_index+1, high);
    }
}

// Complete the minimumAbsoluteDifference function below.
int minimumAbsoluteDifference(vector<int> arr) {
    int n = arr.size(), absMinDiff = INT_MAX, absDiff;
    
    quicksort(arr, 0, n-1); // one can also use sort() method here
  
    for (int i = 0; i < n-1; i++) {
        absDiff = abs(arr[i]-arr[i+1]);
        if (absDiff < absMinDiff)
            absMinDiff = absDiff;
  
    }
    return absMinDiff;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string arr_temp_temp;
    getline(cin, arr_temp_temp);

    vector<string> arr_temp = split_string(arr_temp_temp);

    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        int arr_item = stoi(arr_temp[i]);

        arr[i] = arr_item;
    }

    int result = minimumAbsoluteDifference(arr);

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
