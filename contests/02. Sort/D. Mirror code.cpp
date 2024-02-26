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
    string s, ans;
    cin >> n >> s;
    sort(all(s));

    if (set<char>(all(s)).size() == n) {
        cout << s[0];
        return;
    }

    map<char, int> freq;
    for (char &c : s) freq[c]++;
    int mx = 0;
    char mid;

    for (auto &[c, cnt] : freq) {
        ans += string(cnt / 2, c);

        if (cnt & 1 && cnt > mx) {
            mx = cnt;
            mid = c;
        }
    }

    ans += (mx == 0 ? string(rall(ans)) : mid + string(rall(ans)));
    cout << ans;
    assert(ans == string(rall(ans)));
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