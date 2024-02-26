#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define pii pair<int, int>
#define rep(i, n) for (int i = 0; i < int(n); i++)
#define all(a) ((a).begin()), ((a).end())
#define rall(a) ((a).rbegin()), ((a).rend())
#define sz(a) int((a).size())
using namespace std;

mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
const int K = 53;

void solve() {
    string p, t;
    cin >> p >> t;
    int n = sz(p), m = sz(t);
    vector<int> ans;

    rep(i, m - n + 1) {
        string sub = t.substr(i, n);
        int cnt = 0;

        rep(j, n) {
            cnt += sub[j] != p[j];
        }

        if (cnt <= 1) {
            ans.push_back(i + 1);
        }
    }

    cout << sz(ans) << '\n';
    for (int x : ans) cout << x << ' ';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    //cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}
