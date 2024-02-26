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
    getline(cin, s);

    auto f = [&](int x, int y, char op) -> int {
        if (op == '+') return x + y;
        if (op == '-') return x - y;
        if (op == '*') return x * y;
    };

    stack<int> st;

    for (char c : s) {
        if (isblank(c)) continue;

        if (!isdigit(c)) {
            int a = st.top();
            st.pop();
            int b = st.top();
            st.pop();
            st.push(f(b, a, c));
        } else {
            st.push(c - '0');
        }
    }

    cout << st.top();
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    //cin >> t;

    while (t--) {
        solve();
    }

    cerr << "runtime: " << clock() / 1000.0 << '\n';
    return 0;
}
