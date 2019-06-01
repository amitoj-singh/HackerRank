#include <bits/stdc++.h>

using namespace std;

// Complete the factorial function below.
int factorial(int n) {
  int result = 1;
  if (n >= 1) {
    return result = n * factorial(n - 1);
  } else
    return result;
}

int main() {
  ofstream fout(getenv("OUTPUT_PATH"));

  int n;
  cin >> n;
  cin.ignore(numeric_limits<streamsize>::max(), '\n');

  int result = factorial(n);

  fout << result << "\n";

  fout.close();

  return 0;
}
