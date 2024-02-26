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
const int K = 31;

void solve() {
    string s, t;
    cin >> s >> t;
    int n = sz(s), k = sz(t);
    vector<ull> p(n + 1), hs(n + 1);
    p[0] = 1;
    ull ht = 0;

    rep(i, n) {
        p[i + 1] = p[i] * K;
        hs[i + 1] = hs[i] + p[i] * s[i];
    }

    rep(i, k) {
        ht += p[i] * t[i];
    }

    rep(i, n - k + 1) {
        if (hs[i + k] - hs[i] == ht * p[i]) {
            cout << i << ' ';
        }
    }
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
