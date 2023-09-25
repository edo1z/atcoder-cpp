#include <bits/stdc++.h>
using namespace std;

int main()
{
  int N;
  cin >> N;

  string ans = "";
  for (int i = 0; i <= N; i++)
  {
    bool found = false;
    for (int j = 1; j <= 9; j++)
    {
      if (N % j == 0 && i % (N / j) == 0)
      {
        ans += to_string(j);
        found = true;
        break;
      }
    }
    if (!found)
    {
      ans += "-";
    }
  }
  cout << ans << endl;

  return 0;
}
