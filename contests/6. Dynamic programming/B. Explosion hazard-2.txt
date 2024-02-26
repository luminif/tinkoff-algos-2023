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
    int n;
    cin >> n;
    vector<array<ll, 3>> dp(n);
    rep(i, 3) dp[0][i] = 1;

    for (int i = 1; i < n; i++) {
        dp[i][0] = dp[i - 1][1] + dp[i - 1][2];
        dp[i][1] = dp[i - 1][0] + dp[i - 1][1] + dp[i - 1][2];
        dp[i][2] = dp[i - 1][0] + dp[i - 1][1] + dp[i - 1][2];
    }

    ll ans = 0;
    rep(i, 3) ans += dp.back()[i];
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
