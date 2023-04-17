#include <bits/stdc++.h>
using namespace std;

struct people {
  int id;
  int sum;
};

static bool cmp (people& a, people& b) {
  if (a.sum == b.sum) return a.id < b.id;
  return a.sum > b.sum; 
}



int main() {
  int n, m, id;
  cin >> n >> m >> id;
  
  // unordered_map<int, int> hash;
  vector<people> ps(n);
  
  for (int i = 0; i < n; ++i) {
    ps[i].id = i;
    for (int j = 0; j < m; ++j) {
      int tmp;
      cin >> tmp;
      ps[i].sum += tmp;
    }
  }
  
  sort(ps.begin(), ps.end(), cmp);
  
  for (int i = 0; i < n; ++i) {
    if (ps[i].id == id - 1) cout << i+1 << endl;
  }
  
  return 0;
}