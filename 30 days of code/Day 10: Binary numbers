#include <bits/stdc++.h>

using namespace std;

#define maxx 1000
int a[maxx], top = -1;

void push(int remainder) {

  if (top < maxx) {
    top++;
    a[top] = remainder;
  }
}

int pop() {
  int x;
  if (top >= 0) {
    x = a[top];
    top--;
  }
  return x;
}

int main() {
  int n, remainder, x, tmpcount = 0, maxcount = 0;
  cin >> n;
  cin.ignore(numeric_limits<streamsize>::max(), '\n');

  while (n != 0) {
    remainder = n % 2;
    n = n / 2;
    push(remainder);
  }

  while (top >= 0) {
    x = pop();
    if (x == 1) {
      tmpcount++;
      if (tmpcount > maxcount) {
        maxcount = tmpcount;
      }
    } else
      tmpcount = 0;
  }
  cout << maxcount;

  return 0;
}
