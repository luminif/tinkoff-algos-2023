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

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int &x : a) cin >> x;
    vector<ll> dp(n);
    dp[0] = a[0];
    if (n > 1) dp[1] = a[1];

    for (int i = 2; i < n; i++) {
        dp[i] = min(dp[i - 1], dp[i - 2]) + a[i];
    }

    cout << dp.back();
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
