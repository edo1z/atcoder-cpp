#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
  vector<int> b = {1, 2, 3, 4, 5, 5, 6, 8, 12, 100};
  // 指定した値以上の最小値のイテレータを返す
  int lb = lower_bound(b.begin(), b.end(), 5) - b.begin();
  cout << lb << endl;
  lb = lower_bound(b.begin(), b.end(), 1) - b.begin();
  cout << lb << endl;
  lb = lower_bound(b.begin(), b.end(), 15) - b.begin();
  cout << lb << endl;
}