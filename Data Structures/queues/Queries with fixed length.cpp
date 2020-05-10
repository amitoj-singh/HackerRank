#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Complete the solve function below.
vector<int> solve(vector<int> arr, vector<int> queries) {
    // int num_queries = queries.size();
    // int n = arr.size();
    // vector<int> result;
    // for (int q = 0; q < num_queries; q++) {
    //     int d = queries[q];
    //     int min = INT_MAX;
    //     for (int i = 0; i <= n-d; i++) {
    //         int max = -1;
    //         for (int j = i; j < i+d; j++) {
    //             if (max < arr[j])
    //                 max = arr[j];
    //         }
    //         if (min > max) 
    //             min = max;
    //     }
    //     result.push_back(min);
    // }
    // return result;

    int num_queries = queries.size();
    int n = arr.size();
    vector<int> result;
    for (int q = 0; q < num_queries; q++) {
        int d = queries[q];
        vector<int> queue;
        int min = INT_MAX;
        int max = -1;
        for (int i = 0; i < d; i++) {
            int current = arr[i];
            queue.push_back(current);
            if (max < current) 
                max = current;
        }
        if (max < min)
            min = max;


        int x = 0;
        for (int i = 1; i <= n-d; i++) {
            int current = arr[i+d-1];
            queue.push_back(current);
            if (current > max)
                max = current;
            
            if (queue[x++] == max) {
                max = *max_element(queue.begin()+x, queue.end());                
            }

            if (max < min)
                min = max;
        }
        result.push_back(min);
    }
    return result;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string nq_temp;
    getline(cin, nq_temp);

    vector<string> nq = split_string(nq_temp);

    int n = stoi(nq[0]);

    int q = stoi(nq[1]);

    string arr_temp_temp;
    getline(cin, arr_temp_temp);

    vector<string> arr_temp = split_string(arr_temp_temp);

    vector<int> arr(n);

    for (int arr_itr = 0; arr_itr < n; arr_itr++) {
        int arr_item = stoi(arr_temp[arr_itr]);

        arr[arr_itr] = arr_item;
    }

    vector<int> queries(q);

    for (int queries_itr = 0; queries_itr < q; queries_itr++) {
        int queries_item;
        cin >> queries_item;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        queries[queries_itr] = queries_item;
    }

    vector<int> result = solve(arr, queries);

    for (int result_itr = 0; result_itr < result.size(); result_itr++) {
        fout << result[result_itr];

        if (result_itr != result.size() - 1) {
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
