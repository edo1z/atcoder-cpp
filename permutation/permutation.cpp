#include <bits/stdc++.h>

using namespace std;

int main()
{
  vector<int> cells(3);
  iota(cells.begin(), cells.end(), 0);
  do
  {
    for (auto &&c : cells)
    {
      cout << c;
    }
    cout << endl;
  } while (ranges::next_permutation(cells).found);
}
