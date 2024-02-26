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
const int MOD = int(1e9);

class Treap {
    struct Node {
        int key, priority, count;
        ll sum;
        Node *l = 0, *r = 0;
        Node(int _key) {key = _key, priority = rnd(), count = 1, sum = _key * 1LL;}
    };

    Node *root = 0;
    using Pair = pair<Node*, Node*>;

    Node* merge(Node *l, Node *r) {
        if (!l) return r;
        if (!r) return l;

        if (l->priority > r->priority) {
            l->r = merge(l->r, r);
            upd_count(l);
            upd_sum(l);
            return l;
        } else {
            r->l = merge(l, r->l);
            upd_count(r);
            upd_sum(r);
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
            upd_count(l);
            upd_sum(l);
        } else {
            split(node->l, key, l, node->l);
            r = node;
            upd_count(r);
            upd_sum(r);
        }
    }

    int min(Node *node) {
        if (!node) return -1;

        while (node->l) {
            node = node->l;
        }

        return node->key;
    }

    int find_kth(Node *node, int ind) {
        if (get_count(node->l) > ind)
            return find_kth(node->l, ind);
        if (get_count(node->l) == ind)
            return node->key;
        return find_kth(node->r, ind - get_count(node->l) - 1);
    }

    ll get_sum(Node *&node) {
        if (!node) return 0;
        return node->sum;
    }

    void upd_sum(Node *&node) {
        if (!node) return;
        node->sum = get_sum(node->l) + get_sum(node->r) + node->key;
    }

    int get_count(Node *&node) {
        if (!node) return 0;
        return node->count;
    }

    void upd_count(Node *&node) {
        if (!node) return;
        node->count = get_count(node->l) + get_count(node->r) + 1;
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
            ll res = get_sum(node);
            root = merge(merge(lt, node), rt);
            return res;
        }

        void erase(int key) {
            Node *lt, *node, *rt;
            split(root, key, lt, rt);
            split(rt, key + 1, node, rt);
            root = merge(lt, rt);
        }

        int size() {
            upd_count(root);
            return get_count(root);
        }

        int at(int ind) {
            return find_kth(root, ind);
        }
};

void solve() {
    int n;
    cin >> n;
    Treap a;

    while (n--) {
        string type;
        int x;
        cin >> type >> x;

        if (type == "+1" || type == "1") {
            a.add(x);
        } else if (type == "0") {
            cout << a.at(a.size() - x) << '\n';
        } else {
            a.erase(x);
        }
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
