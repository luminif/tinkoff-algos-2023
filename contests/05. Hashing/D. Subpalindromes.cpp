#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define ff first
#define ss second
#define rep(i, n) for (int i = 0; i < int(n); i++)
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define make_unique(a) sort(all(a)); (a).resize(unique(all(a)) - (a).begin())
#define sz(a) int((a).size())
using namespace std;

void solve() {
    string s;
    cin >> s;

    for (int i = 0; i <= sz(s); i += 2) {
        s.insert(i, 1, '#');
    }

    int n = sz(s);
    int l = 0, r = 0;
    vector<int> a(n, 1);

    rep(i, n) {
        if (i < r) {
            a[i] = min(a[l + r - i], r - i + 1);
        }

        while (i + a[i] < n && i >= a[i] && s[i + a[i]] == s[i - a[i]]) {
            ++a[i];
        }

        if (i + a[i] - 1 > r) {
            l = i - a[i] + 1;
            r = i + a[i] - 1;
        }
    }

    ll ans = 0;
    for (int x : a) ans += x / 2;
    cout << ans;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    //cin >> t;

    while (t--) {
        solve();
    }

    //cerr << "runtime: " << clock() / 1000.0 << '\n';
    return 0;
}