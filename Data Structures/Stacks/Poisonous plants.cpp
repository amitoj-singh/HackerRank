/********************* Attempt 1 *********************/

// #include <bits/stdc++.h>

// using namespace std;

// vector<string> split_string(string);

// // Complete the poisonousPlants function below.
// int poisonousPlants(vector<int> p) {
//     bool flag = true;
//     int days = -1;
//     while (flag) {
//         flag = false;
//         days++;
//         for (int i = p.size()-1; i > 0; i--) {
//             if (p[i] > p[i-1]) {
//                 p.erase(p.begin()+i);
//                 flag = true;
//             }
//         }
//     }
//     return days;
// }

// int main()
// {
//     ofstream fout(getenv("OUTPUT_PATH"));

//     int n;
//     cin >> n;
//     cin.ignore(numeric_limits<streamsize>::max(), '\n');

//     string p_temp_temp;
//     getline(cin, p_temp_temp);

//     vector<string> p_temp = split_string(p_temp_temp);

//     vector<int> p(n);

//     for (int i = 0; i < n; i++) {
//         int p_item = stoi(p_temp[i]);

//         p[i] = p_item;
//     }

//     int result = poisonousPlants(p);

//     fout << result << "\n";

//     fout.close();

//     return 0;
// }

// vector<string> split_string(string input_string) {
//     string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
//         return x == y and x == ' ';
//     });

//     input_string.erase(new_end, input_string.end());

//     while (input_string[input_string.length() - 1] == ' ') {
//         input_string.pop_back();
//     }

//     vector<string> splits;
//     char delimiter = ' ';

//     size_t i = 0;
//     size_t pos = input_string.find(delimiter);

//     while (pos != string::npos) {
//         splits.push_back(input_string.substr(i, pos - i));

//         i = pos + 1;
//         pos = input_string.find(delimiter, i);
//     }

//     splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

//     return splits;
// }




/********************* Attempt 2 *********************/

// #include<bits/stdc++.h>

// using namespace std;

// int main() {
    // int n;
    // cin >> n;

    // vector<vector<int>> sl;
    // vector<int> temp;
    // int x, days = 0;
    // cin >> x;
    // unsigned i;
    // temp.push_back(x);
    // for (i = 1; i < n; i++) {
    //     int prev = x;
    //     cin >> x;
    //     if (prev < x) {
    //         sl.push_back(temp);
    //         temp.clear();
    //     }
    //     temp.push_back(x);
    // }
    // sl.push_back(temp);

    // while (sl.size() > 1) {
    //     days++;
    //     for (i = 1; i < sl.size(); i++) {
    //         sl[i].erase(sl[i].begin());
    //         if (sl[i].empty()) {
    //             sl.erase(sl.begin()+i);
    //             i--;
    //         } else if (sl[i-1].back() >= sl[i].front()) {
    //             sl[i-1].insert(sl[i-1].end(), sl[i].begin(), sl[i].end());
    //             sl.erase(sl.begin()+i);
    //             i--;
    //         }
    //     }
    // }

    // cout << days;
    // return 0;
// }




/********************* Attempt 3 *********************/

// #include<bits/stdc++.h>

// using namespace std;

// class Plant {
//     public:    
//         int val;
//         Plant *next;

//         Plant(int val) {
//             this->val = val;
//         }
// };

// class Ret {
//     public:
//         Plant *base;
//         Plant *top;

//         Ret(Plant *base, Plant *top) {
//             this->base = base;
//             this->top = top;
//         }
// };

// // insert at top of the plant
// Ret* insertTop(Plant *base, Plant *top, int val) {
//     Plant *newPlant = new Plant(val);
//     if (top == NULL) {
//         return new Ret(newPlant, newPlant);
//     } else {
//         top->next = newPlant;
//         return new Ret(base, newPlant);
//     }
// }

// // remove base element
// Plant* removeBase(Plant *base) {
//     Plant *temp = base;
//     base = base->next;
//     delete temp;
//     return base;
// }

// // merge two lists
// Plant* merge(Plant *top1, Plant *base, Plant *top2) {
//     top1->next = base;
//     top1 = top2;
//     return top1;
// }

// int main() {
//     int n;
//     cin >> n;
//     int x, days = 0;
//     cin >> x;
//     vector<pair<Plant*, Plant*>> sl;

//     Ret *temp = insertTop(NULL, NULL, x);

//     pair<Plant*, Plant*> pr;
//     pr.first = temp->base;
//     pr.second = temp->top;

//     sl.push_back(pr);

//     for (int i = 1; i < n; i++) {
//         int prev = x;
//         cin >> x;
//         if (prev < x) {
//             pr.first = NULL;
//             pr.second = NULL;
//             sl.push_back(pr);
//         }
//         pr = sl.back();
//         temp = insertTop(pr.first, pr.second, x);
//         pr.first = temp->base;
//         pr.second = temp->top;
//         sl[sl.size()-1] = pr;
//     }

//     while (sl.size() > 1) {
//         days++;
//         for (int i = 1; i < sl.size(); i++) {
//             Plant *base = removeBase(sl[i].first);
//             sl[i].first = base;
//             if (sl[i].first == NULL) {
//                 sl.erase(sl.begin()+i);
//                 i--;
//             } else if (sl[i-1].second->val >= sl[i].first->val) {
//                 Plant *top = merge(sl[i-1].second, sl[i].first, sl[i].second);
//                 sl[i-1].second = top;
//                 sl.erase(sl.begin()+i);
//                 i--;
//             }
//         }
//     }

//     cout << days;

//     return 0;
// }




/********************* Attempt 4 *********************/
// solution from:
// https://www.hackerrank.com/challenges/poisonous-plants/forum/comments/420881

#include<bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    stack<int> st;
    vector<int> p(n, 0), days (n, 0);
    int maxDays = 0;
    for (int i = 0; i < n; i++) {
        cin >> p[i];
        days[i] = 1;

        while (!st.empty() && p[i] <= p[st.top()]) {
            days[i] = max(days[i], days[st.top()]+1);
            st.pop();
        }

        if (st.empty()) {
            days[i] = -1;
        }

        st.push(i);

        maxDays = max(days[i], maxDays);
    }

    cout << maxDays;

    return 0;
}
