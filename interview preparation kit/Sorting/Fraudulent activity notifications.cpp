#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

int getTwoTimesMedian(vector<int> &arr, vector<int> &aux, int d) {
    
    vector<int>countFreq(aux);

    for (int i = 1; i < countFreq.size(); i++) {
        countFreq[i] += countFreq[i-1];
    }

    int twiceMedian;
    int a = 0;
    int b = 0;

    if (d%2 == 0) {
        int first = d/2;
        int second = first + 1;
        for (int i = 0; i < countFreq.size(); i++) {
            if(first <= countFreq[i]) {
                a = i;
                break;
            }
        }
        for (int i = 0; i < countFreq.size(); i++) {
            if (second <= countFreq[i]) {
                b = i;
                break;
            }
        }
    }
    else {
        int first = d/2 + 1;
        for (int i = 0; i < countFreq.size(); i++) {
            if (first <= countFreq[i]) {
                a = 2*i;
                break;
            }
        }
    }

    twiceMedian = a+b;

    return twiceMedian;
}

// Complete the activityNotifications function below.
int activityNotifications(vector<int> expenditure, int d) {
    int size = expenditure.size(), notifications = 0, two_times_median;

    vector<int>aux(201, 0);

    for (int i = 0; i < d; i++)
        aux[expenditure[i]]++;

    for (int today_spend_index = d; today_spend_index < size; today_spend_index++) {
        
        two_times_median = getTwoTimesMedian(expenditure, aux, d);
        if (expenditure[today_spend_index] >= two_times_median)
            notifications++;

        //update aux vector
        aux[expenditure[today_spend_index]]++;
        aux[expenditure[today_spend_index-d]]--;
    }
    return notifications;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string nd_temp;
    getline(cin, nd_temp);

    vector<string> nd = split_string(nd_temp);

    int n = stoi(nd[0]);

    int d = stoi(nd[1]);

    string expenditure_temp_temp;
    getline(cin, expenditure_temp_temp);

    vector<string> expenditure_temp = split_string(expenditure_temp_temp);

    vector<int> expenditure(n);

    for (int i = 0; i < n; i++) {
        int expenditure_item = stoi(expenditure_temp[i]);

        expenditure[i] = expenditure_item;
    }

    int result = activityNotifications(expenditure, d);

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
