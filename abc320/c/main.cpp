#include <bits/stdc++.h>
using namespace std;

int main()
{
  int M;
  cin >> M;
  vector<string> S(3);
  for (int i = 0; i < 3; i++)
  {
    cin >> S[i];
  }

  int ans = INT_MAX;
  bool found = false;

  for (int i = 0; i < M; i++)
  {
    for (int j = 0; j < M; j++)
    {
      for (int k = 0; k < M; k++)
      {
        if (S[0][i] == S[1][j] && S[1][j] == S[2][k])
        {
          found = true;
          int a = i;
          int b = j;
          int c = k;
          int max_time = INT_MAX;
          if (a == b && b == c)
          {
            max_time = a + M * 2;
          }
          else if (a == b || a == c)
          {
            max_time = a + M;
          }
          else if (b == c)
          {
            max_time = b + M;
          }
          else
          {
            max_time = max({a, b, c});
          }
          ans = min(ans, max_time);
        }
      }
    }
  }

  if (found)
  {
    cout << ans << endl;
  }
  else
  {
    cout << -1 << endl;
  }

  return 0;
}
