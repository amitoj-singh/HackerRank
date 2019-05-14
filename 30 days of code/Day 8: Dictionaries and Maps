#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <map>
#include <vector>
using namespace std;

int main() {
  /* Enter your code here. Read input from STDIN. Print output to STDOUT */
  int n;
  cin >> n;
  map<string, string> namenumber;
  for (int i = 0; i < n; i++) {
    string name;
    string phone;
    cin >> name;
    cin >> phone;
    namenumber[name] = phone;
  }

  map<string, string>::iterator it;
  string query;
  while (cin >> query) {
    it = namenumber.find(query);

    if (it != namenumber.end())
      cout << it->first << "=" << it->second << endl;
    else
      cout << "Not found" << endl;
  }
  return 0;
}
