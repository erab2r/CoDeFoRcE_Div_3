#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tc;
    cin >> tc;
    while(tc--) {
        int n, e;
        cin >> n >> e;
        string L, tmp;
        cin >> L >> tmp;
        int aanss = INT_MAX;
        for(int st = 0; st < n; st++) {
            if(L[st] != tmp[0]) 
                continue; 
            vector<int> fqqq;
            int i = st, j = 0;
            while(i < n && j < e) {
                if(L[i] == tmp[j]) {
                    fqqq.push_back(i);
                    j++;
                }
                i++;
            }
            if(j != e) 
                continue;
            int cnt = 0;
            if(fqqq[0] > 0) 
                cnt++;
            for(int k = 0; k + 1 < e; k++) {
                if(fqqq[k+1] > fqqq[k] + 1) 
                    cnt++;
            }
            if(fqqq[e-1] < n - 1) 
                cnt++;
            aanss = min(aanss, cnt);
        }

        cout << (aanss == INT_MAX ? -1 : aanss) << "\n";
    }

    return 0;
}
