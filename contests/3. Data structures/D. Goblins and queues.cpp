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
    deque<int> dx, dy;

    while (n--) {
        char c;
        int x;
        cin >> c;
        if (c != '-') cin >> x;

        if (c == '+') {
            dx.push_back(x);
        }

        if (c == '*') {
            dx.push_front(x);
        }

        if (c == '-') {
            cout << dy.front() << '\n';
            dy.pop_front();
        }

        if (sz(dx) > sz(dy)) {
            dy.push_back(dx.front());
            dx.pop_front();
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
