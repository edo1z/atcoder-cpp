#include <bits/stdc++.h>
using namespace std;

int main()
{
  vector<int> cells(9);
  for (auto &&c : cells)
  {
    cin >> c;
  }
  vector<int> order(9);
  iota(order.begin(), order.end(), 0);
  vector<tuple<int, int, int>> row{
      {0, 1, 2},
      {3, 4, 5},
      {6, 7, 8},
      {0, 3, 6},
      {1, 4, 7},
      {2, 5, 8},
      {0, 4, 8},
      {2, 4, 6}};

  int not_disappoint = 0, all = 0;
  do
  {
    ++all;
    bool is_disappoint = false;
    for (auto &&[a, b, c] : row)
    {
      if (cells[a] == cells[b] && order[a] < order[c] && order[b] < order[c])
      {
        is_disappoint = true;
      }
      else if (cells[a] == cells[c] && order[a] < order[b] && order[c] < order[b])
      {
        is_disappoint = true;
      }
      else if (cells[b] == cells[c] && order[b] < order[a] && order[c] < order[a])
      {
        is_disappoint = true;
      }
    }
    if (!is_disappoint)
    {
      ++not_disappoint;
    }
  } while (ranges::next_permutation(order).found);

  cout << setprecision(10) << (double)not_disappoint / all << endl;
}
