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
    int n;
    cin >> n;
    int l = 1, r = n;

    while (l != r) {
        int m = (l + r + 1) / 2;
        cout << m << '\n';
        fflush(stdout);

        string type;
        cin >> type;

        if (type == "<") {
            r = m - 1;
        } else {
            l = m;
        }
    }

    cout << "! " << l;
    fflush(stdout);
}

signed main() {
    //ios_base::sync_with_stdio(false);
    //cin.tie(nullptr);
    int t = 1;
    //cin >> t;

    while (t--) {
        solve();
    }

    //cerr << "runtime: " << clock() / 1000.0 << '\n';
    return 0;
}
