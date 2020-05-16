#include <bits/stdc++.h>
#include <queue>

using namespace std;

/*
 * Complete the runningMedian function below.
 */
vector<double> runningMedian(vector<int> a) {
    /*
     * Algorithm: https://www.hackerrank.com/challenges/find-the-running-median/forum/comments/311919
     */
    vector<double> result;
    priority_queue<int> maxHeap;
    priority_queue<int, vector<int>, greater<int>> minHeap;
    int n = a.size();

    double median = 0;
    
    for(int i = 0; i < n; i++) {
        if (a[i] < median)
            maxHeap.push(a[i]);
        else
            minHeap.push(a[i]);

        if (minHeap.size() > maxHeap.size()+1) {
            maxHeap.push(minHeap.top());
            minHeap.pop();
        } 
        else if (maxHeap.size() > minHeap.size()+1) {
            minHeap.push(maxHeap.top());
            maxHeap.pop();
        }

        if (minHeap.size() == maxHeap.size())
            median = (minHeap.top()+maxHeap.top())/2.0;
        else if (minHeap.size() > maxHeap.size())
            median = double(minHeap.top());
        else
            median = double(maxHeap.top());

        result.push_back(median);
    }

    return result;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int a_count;
    cin >> a_count;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    vector<int> a(a_count);

    for (int a_itr = 0; a_itr < a_count; a_itr++) {
        int a_item;
        cin >> a_item;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        a[a_itr] = a_item;
    }

    vector<double> result = runningMedian(a);

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
