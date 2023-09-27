#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
  ll n, m, p;
  cin >> n >> m >> p;
  vector<ll> a(n), b(m);
  for (ll &i : a)
    cin >> i;
  for (ll &i : b)
    cin >> i;
  sort(b.begin(), b.end());
  vector<ll> b_sum(m + 1);
  for (ll i = 0; i < m; i++)
    b_sum[i + 1] = b_sum[i] + b[i];
  ll ans = 0;
  for (ll i : a)
  {
    int lb = lower_bound(b.begin(), b.end(), p - i) - b.begin();
    ans += (ll)i * lb;
    ans += b_sum[lb];
    ans += (ll)p * (m - lb);
  }
  cout << ans << endl;
}
