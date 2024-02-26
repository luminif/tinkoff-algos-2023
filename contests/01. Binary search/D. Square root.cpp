#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define ff first
#define ss second
#define rep(i, n) for (int i = 0; i < int(n); i++)
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define make_unique(a) sort(all(a)); (a).resize(unique(all((a))) - (a).begin())
using namespace std;

const double EPS = 1e-6;

void solve() {
    double c;
    cin >> c;

    auto f = [&](double x) -> double {
        return x * x + sqrt(x + 1);
    };

    double l = -1, r = c;

    while (r - l > EPS) {
        double m = (r + l) / 2;

        if (f(m) > c) {
            r = m;
        } else {
            l = m;
        }
    }

    cout << fixed << setprecision(6) << r << '\n';
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
