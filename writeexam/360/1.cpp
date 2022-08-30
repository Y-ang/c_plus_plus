#include <bits/stdc++.h>
using namespace std;

static bool cmp(int a, int b) {
  return a > b;
}

int main() {
  int n, target;
  cin >> n >> target;
  vector<int> values(n);
  for (int i = 0; i < n; ++i) {
    cin >> values[i];
  }
  sort(values.begin(), values.end(), cmp);
  int res = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = i + 1; j < n; ++j) {
      if (values[i] * values[j] >= target) {
        res++;
      } else {
        break;
      }
    }
  }
  
  cout << res * 2 << endl;
  
  return 0;
}

#include <bits/stdc++.h>
using namespace std;

static bool cmp(int a, int b) {
  return a > b;
}

int main() {
  int n, target;
  cin >> n >> target;
  vector<int> values(n);
  for (int i = 0; i < n; ++i) {
    cin >> values[i];
  }
  sort(values.begin(), values.end(), cmp);
  int res = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = i + 1; j < n; ++j) {
      if (values[i] * values[j] >= target && values[i] == values[j]) {
        res++;
      }  else if (values[i] * values[j] >= target && values[i] != values[j]) {
        res += 2;
      }
    }
  }
  
  cout << res << endl;
  
  return 0;

#include <bits/stdc++.h>
using namespace std;

static bool cmp(int a, int b) {
  return a > b;
}

int main() {
  int n, target;
  cin >> n >> target;
  vector<int> values(n);
  for (int i = 0; i < n; ++i) {
    cin >> values[i];
  }
  sort(values.begin(), values.end(), cmp);
  int res = 0;
  int left = 0;
  int right = n - 1;
  while (left < right) {
    if (values[left] * values[right] >= target) {
      res += right - left;
      left++;
    } else {
      right--;
    }
  }
  
  cout << res * 2 << endl;
  
  return 0;
}