#include <bits/stdc++.h>
using namespace std;

bool isPalindrome(const string &s)
{
  int l = 0, r = s.size() - 1;
  while (l < r)
  {
    if (s[l] != s[r])
      return false;
    l++;
    r--;
  }
  return true;
}

int main()
{
  string S;
  cin >> S;

  for (int len = S.size(); len >= 1; len--)
  {
    for (int i = 0; i + len - 1 < S.size(); i++)
    {
      if (isPalindrome(S.substr(i, len)))
      {
        cout << len << endl;
        return 0;
      }
    }
  }

  return 0;
}
