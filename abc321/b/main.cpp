#include <bits/stdc++.h>
using namespace std;

int main()
{
  int N, X;
  cin >> N >> X;

  vector<int> a(N - 1), s;
  for (int i = 0; i < N - 1; i++)
  {
    cin >> a[i];
  }
  for (int i = 0; i <= 100; i++)
  {
    s = a;
    s.push_back(i);
    sort(s.begin(), s.end());
    int sum = 0;
    for (int j = 1; j < N - 1; j++)
    {
      sum += s[j];
    }
    if (X <= sum)
    {
      cout << i << endl;
      return 0;
    }
  }
  cout << -1 << endl;
}