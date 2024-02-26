#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define pii pair<int, int>
#define rep(i, n) for (int i = 0; i < int(n); i++)
#define all(a) ((a).begin()), ((a).end())
#define rall(a) ((a).rbegin()), ((a).rend())
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    int j = n - 1;
    cout << 1 << ' ';

    rep(i, n) {
        int p;
        cin >> p, p--;
        a[p] = 1;
        while (j >= 0 && a[j] == 1) --j;
        cout << (i + 1) - (n - j - 2) << ' ';
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
