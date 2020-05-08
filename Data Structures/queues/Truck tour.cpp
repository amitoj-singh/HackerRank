#include <bits/stdc++.h>

using namespace std;

// 1. Visit every pump starting from 0.    
// 2. keep track of total petrol at that pump. 
// 3. If total petrol is less than 0 then
//      update total petrol to 0 and you have to start your journey from next pump.
int truckTour(vector<vector<int>> petrolpumps) {
    int n = petrolpumps.size(), start = 0, totalPetrol = 0;

    for (int i = 0; i < n; i++) {
        totalPetrol += petrolpumps[i][0] - petrolpumps[i][1];
        if (totalPetrol < 0) {
            start = i + 1;
            totalPetrol = 0;
        }
    }
    return start;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    vector<vector<int>> petrolpumps(n);
    for (int petrolpumps_row_itr = 0; petrolpumps_row_itr < n; petrolpumps_row_itr++) {
        petrolpumps[petrolpumps_row_itr].resize(2);

        for (int petrolpumps_column_itr = 0; petrolpumps_column_itr < 2; petrolpumps_column_itr++) {
            cin >> petrolpumps[petrolpumps_row_itr][petrolpumps_column_itr];
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    int result = truckTour(petrolpumps);

    fout << result << "\n";

    fout.close();

    return 0;
}
