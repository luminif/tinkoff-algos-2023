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
    int n, m;
    cin >> n >> m;
    vector<vector<ll>> dp(n, vector<ll>(m, -1));
    dp[0][0] = 1;

    //https://ru.algorithmica.org/cs/general-dynamic/memoization/

    function<ll(int, int)> f = [&](int i, int j) {
        if (i < 0 || j < 0 || i >= n || j >= m) return 0LL;
        if (dp[i][j] == -1) {
            dp[i][j] = f(i - 1, j - 2) + f(i - 2, j - 1) + f(i + 1, j - 2) + f(i - 2, j + 1);
        }

        return dp[i][j];
    };

    f(n - 1, m - 1);
    cout << dp.back().back();
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
