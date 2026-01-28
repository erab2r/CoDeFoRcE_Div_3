#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tc;
    cin >> tc;
    while (tc--) {
        int n;
        cin >> n;
        vector<long long> arry(n);
        for (int i = 0; i < n; i++) 
            cin >> arry[i];

        vector<long long> frqq(n);
        for (int j = 0; j < n; j++) 
            cin >> frqq[j];
        bool anss = true;
        for (int i = 0; i < n; i++) {
            if (arry[i] > frqq[i]) {
                anss = false;
                break;
            }
            if (i > 0 && frqq[i] > frqq[i - 1] && arry[i] == arry[i - 1]) {
                anss = false;
                break;
            }
        }
        if (anss) {
            cout << "Yes\n";
        } else {
            cout << "No\n";
        }
    }
    return 0;
}
