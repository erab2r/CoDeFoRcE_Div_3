#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tc;
    cin >> tc;
    while (tc--) {
        int e;
        cin >> e;
        vector<int> vecc(e + 1, 0);
        for (int i = 0; i < e; i++) {
            int a;
            cin >> a;
            vecc[a]++;
        }
        int rslts = 0;
        int prf_sm = INT_MAX;
        for (int i = 1; i <= e; i++) {
            prf_sm = min(prf_sm, vecc[i]);
            rslts += prf_sm;
        }
        cout << rslts << '\n';
    }
    return 0;
}
