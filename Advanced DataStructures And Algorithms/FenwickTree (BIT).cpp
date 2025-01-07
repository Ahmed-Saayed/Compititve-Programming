struct FenwickTree {		// Range Summation
    vector<ll> bit;
    int n;
    FenwickTree(){};
    FenwickTree(int n) {
        this->n = n;
        bit.assign(n, 0);
    }

    ll sum(int r) {
        ll ret = 0;
        for (; r >= 0; r = (r & (r + 1)) - 1)
            ret += bit[r];
        return ret;
    }

    ll sum(int l, int r) {
        if(l>r)return 0;
        return sum(r) - sum(l - 1);
    }

    void add(int idx, int delta) {
        for (; idx < n; idx = idx | (idx + 1))
            bit[idx] += delta;
    }
};