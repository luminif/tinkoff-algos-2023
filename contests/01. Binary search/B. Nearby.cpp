#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define ff first
#define ss second
#define rep(i, n) for (int i = 0; i < int(n); i++)
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define make_unique(a) sort(all(a)); (a).resize(unique(all(a)) - (a).begin())
using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int &x : a) cin >> x;

    while (k--) {
        int x;
        cin >> x;
        ll l = -1, r = n;

        while (r - l > 1) {
            ll m = (r + l) / 2;

            if (a[m] <= x) {
                l = m;
            } else {
                r = m;
            }
        }

        if (l < 0) {
            cout << a[r] << '\n';
        } else if (abs(a[l] - x) <= abs(a[r] - x)) {
            cout << a[l] << '\n';
        } else {
            cout << a[r] << '\n';
        }
    }
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
