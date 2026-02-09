#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
template <typename T> using pbds = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
using ll = long long;
#define sz(yo) (int)yo.size()
 
void solve() {
   ll n;
   cin >> n;
   string s;
   cin >> s;
 
   if (n == 1) {
      cout << 1 << '\n';
      return;
   }
 
   ll st = -1, ed = -1, tot = count(s.begin(), s.end(), '1');
   for (ll i = 0;i < n;i++) {
      if (s[i] == '1') {
         st = i;
         break;
      }
   }
   for (ll i = n - 1;i >= 0;i--) {
      if (s[i] == '1') {
         ed = i;
         break;
      }
   }
 
   if (st == -1 && ed == -1) {
      ll res = 0, idx = 2;
      while (idx <= n) {
         res++;
         if ((idx + 3) > n) {
            break;
         }
         idx += 3;
      }
      if ((n - idx) >= 2) {
         res++;
      }
      cout << res << '\n';
   }
   else {
      ll cnt = 0, ans = 0;
      for (ll i = st;i <= ed;i++) {
         if (s[i] == '1') {
            ans += (cnt / 3);
            cnt = 0;
         }
         else {
            cnt++;
         }
      }
      if (st != -1) {
         ans += (st / 3);
         if ((st - ((st / 3) * 3)) >= 2) {
            ans++;
         }
      }
      if (ed != -1) {
         ll x = (n - ed - 1);
         ans += (x / 3);
         if ((x - ((x / 3) * 3)) >= 2) {
            ans++;
         }
      }
      cout << ans + tot << '\n';
   }
}
 
int main() {
   ios::sync_with_stdio(false);
   cin.tie(nullptr);
   int t;
   t = 1;
   cin >> t;
   for (int cs = 1; cs <= t; cs++) {
      // cout << "Case " << cs << ": ";
      solve();
   }
   return 0;
}