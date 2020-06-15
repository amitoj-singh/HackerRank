#include <bits/stdc++.h>

using namespace std;

// Complete the organizingContainers function below.
string organizingContainers(vector<vector<int>> container) {
    vector<int> box, ball;

    int n = container.size();

    for (int i = 0; i < n; i++) {
        int boxSum = 0;
        int ballSum = 0;
        for (int j = 0; j < n; j++) {
            boxSum += container[i][j];
            ballSum += container[j][i];
        }
        box.push_back(boxSum);
        ball.push_back(ballSum);
    }

    sort(box.begin(), box.end());
    sort(ball.begin(), ball.end());

    for (int i = 0; i < n; i++) {
        if (box[i] != ball[i])
            return "Impossible";
    }

    return "Possible";


}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int q;
    cin >> q;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int q_itr = 0; q_itr < q; q_itr++) {
        int n;
        cin >> n;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        vector<vector<int>> container(n);
        for (int i = 0; i < n; i++) {
            container[i].resize(n);

            for (int j = 0; j < n; j++) {
                cin >> container[i][j];
            }

            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        string result = organizingContainers(container);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}
