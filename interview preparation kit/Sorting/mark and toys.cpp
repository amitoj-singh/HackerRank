#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);


// Complete the maximumToys function below.
int maximumToys(vector<int> prices, int k) {

    int price_sum = 0, toy_count = 0;
    for (int i = 0; i < prices.size()-1; i++) {
        for (int j = i+1; j < prices.size(); j++) { 
            if (prices[i] > prices[j]) {
                int temp = prices[i];
                prices[i] = prices[j];
                prices[j] = temp;
            }
        }
        if (price_sum+prices[i] < k) {
            price_sum += prices[i];
            toy_count++;
        }
        else // if the prices of toys go out of budget
            break;
    }
    return toy_count;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string nk_temp;
    getline(cin, nk_temp);

    vector<string> nk = split_string(nk_temp);

    int n = stoi(nk[0]);

    int k = stoi(nk[1]);

    string prices_temp_temp;
    getline(cin, prices_temp_temp);

    vector<string> prices_temp = split_string(prices_temp_temp);

    vector<int> prices(n);

    for (int i = 0; i < n; i++) {
        int prices_item = stoi(prices_temp[i]);

        prices[i] = prices_item;
    }

    int result = maximumToys(prices, k);

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
