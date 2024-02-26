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
const int MOD = int(1e9) + 7;
const int K = 31;

void solve() {
    string s;
    cin >> s;
    int n = sz(s);
    vector<ull> p(n + 1), h(n + 1);
    p[0] = 1;

    rep(i, n) {
        p[i + 1] = p[i] * K;
        h[i + 1] = h[i] + p[i] * s[i];
    }

    auto get = [&](int l, int r) -> ull {
        return (h[r + 1] - h[l]) * p[n - l];
    };

    int m;
    cin >> m;

    while (m--) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        a--, b--, c--, d--;
        cout << (get(a, b) == get(c, d) ? "Yes" : "No") << '\n';
        //cout << get(a, b) << ' ' << get(c, d) << '\n';
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
