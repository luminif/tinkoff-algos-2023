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

mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
const int MOD = int(1e9);

class Treap {
    struct Node {
        int key, priority;
        ll sum;
        Node *l = 0, *r = 0;
        Node(int _key) {key = _key, priority = rnd(), sum = _key * 1LL;}
    };

    Node *root = 0;
    using Pair = pair<Node*, Node*>;

    Node* merge(Node *l, Node *r) {
        if (!l) return r;
        if (!r) return l;

        if (l->priority > r->priority) {
            l->r = merge(l->r, r);
            upd(l);
            return l;
        } else {
            r->l = merge(l, r->l);
            upd(r);
            return r;
        }
    }

    void split(Node *node, int key, Node *&l, Node *&r) {
        if (!node) {
            l = 0;
            r = 0;
            return;
        }

        if (node->key < key) {
            split(node->r, key, node->r, r);
            l = node;
            upd(l);
        } else {
            split(node->l, key, l, node->l);
            r = node;
            upd(r);
        }
    }

    int min(Node *node) {
        if (!node) return -1;

        while (node->l) {
            node = node->l;
        }

        return node->key;
    }

    ll get(Node *&node) {
        if (!node) return 0;
        return node->sum;
    }

    void upd(Node *&node) {
        if (!node) return;
        node->sum = get(node->l) + get(node->r) + node->key;
    }

    public:
        void add(int key) {
            Node *l, *r;
            split(root, key, l, r);
            root = merge(merge(l, new Node(key)), r);
        }

        ll sum(int l, int r) {
            Node *lt, *node, *rt;
            split(root, l, lt, rt);
            split(rt, r + 1, node, rt);
            ll res = get(node);
            root = merge(merge(lt, node), rt);
            return res;
        }
};

void solve() {
    int n;
    cin >> n;
    Treap a;
    ll y = 0;
    map<ll, bool> used;

    while (n--) {
        string type;
        cin >> type;

        if (type == "+") {
            ll x;
            cin >> x;
            x = (x + y) % MOD;
            if (!used[x]) a.add(x);
            used[x] = true;
            y = 0;
        } else {
            int l, r;
            cin >> l >> r;
            y = a.sum(l, r);
            cout << y << '\n';
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
