#include <iostream>
#include <queue>

using namespace std;

long long K;

int main()
{
  cin >> K;

  queue<long long> q;

  for (int i = 1; i <= 9; i++)
  {
    q.push(i);
  }

  while (!q.empty())
  {
    long long num = q.front();
    q.pop();
    K--;

    if (K == 0)
    {
      cout << num << endl;
      return 0;
    }

    int lastDigit = num % 10;
    for (int i = 0; i < lastDigit; i++)
    {
      q.push(num * 10 + i);
    }
  }

  return 0;
}

