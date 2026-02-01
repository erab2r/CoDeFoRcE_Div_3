#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tc;
    cin >> tc;
    while (tc--) {
        int e, h;
        cin >> e >> h;
        string L, tmp;
        cin >> L >> tmp;
        int rslt = INT_MAX;
        for (int z = 0; z < e; z++) {
            if (L[z] != tmp[0]) 
                continue;
            int i = z;
            int j = 0;
            vector<int> frqs;
            while (i < e && j < h) {
                if (L[i] == tmp[j]) {
                    frqs.push_back(i);
                    j++;
                }
                i++;
            }
            if (j != h) 
                continue;
            int cnt = 0;
            if (frqs[0] > 0) 
                cnt++;
            for (int k = 0; k + 1 < h; k++) {
                cnt += (frqs[k + 1] > frqs[k] + 1 ? 1 : 0);
            }
            rslt = min(rslt, cnt + (frqs[h - 1] < e - 1 ? 1 : 0));
        }
       cout << (rslt == INT_MAX ? -1 : rslt) << '\n';
    }
}
