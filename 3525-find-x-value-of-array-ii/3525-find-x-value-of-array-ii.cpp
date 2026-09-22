class Solution {
public:
    struct Node {
        int prod;
        int cnt[5][5];
    };

    int n, K;
    vector<Node> seg;

    Node mergeNode(const Node &a, const Node &b) {
        Node res{};

        res.prod = (a.prod * b.prod) % K;

        for (int s = 0; s < K; s++) {
            for (int r = 0; r < K; r++) {
                res.cnt[s][r] = a.cnt[s][r];

                int mid = (s * a.prod) % K;

                res.cnt[s][r] += b.cnt[mid][r];
            }
        }

        return res;
    }

    void makeLeaf(int idx, int val) {
        seg[idx] = Node{};

        int rem = val % K;
        seg[idx].prod = rem;

        for (int s = 0; s < K; s++) {
            int r = (s * rem) % K;
            seg[idx].cnt[s][r] = 1;
        }
    }

    void build(int idx, int l, int r, vector<int>& nums) {
        if (l == r) {
            makeLeaf(idx, nums[l]);
            return;
        }

        int mid = (l + r) / 2;

        build(idx * 2, l, mid, nums);
        build(idx * 2 + 1, mid + 1, r, nums);

        seg[idx] = mergeNode(seg[idx * 2], seg[idx * 2 + 1]);
    }

    void update(int idx, int l, int r, int pos, int val) {
        if (l == r) {
            makeLeaf(idx, val);
            return;
        }

        int mid = (l + r) / 2;

        if (pos <= mid) {
            update(idx * 2, l, mid, pos, val);
        } else {
            update(idx * 2 + 1, mid + 1, r, pos, val);
        }

        seg[idx] = mergeNode(seg[idx * 2], seg[idx * 2 + 1]);
    }

    Node query(int idx, int l, int r, int ql, int qr) {
        if (ql <= l && r <= qr) {
            return seg[idx];
        }

        int mid = (l + r) / 2;

        if (qr <= mid) {
            return query(idx * 2, l, mid, ql, qr);
        }

        if (ql > mid) {
            return query(idx * 2 + 1, mid + 1, r, ql, qr);
        }

        Node left = query(idx * 2, l, mid, ql, qr);
        Node right = query(idx * 2 + 1, mid + 1, r, ql, qr);

        return mergeNode(left, right);
    }

    vector<int> resultArray(vector<int>& nums, int k,
                            vector<vector<int>>& queries) {

        n = nums.size();
        K = k;

        seg.resize(4 * n);

        build(1, 0, n - 1, nums);

        vector<int> ans;

        for (auto &q : queries) {
            int index = q[0];
            int value = q[1];
            int start = q[2];
            int x = q[3];

            nums[index] = value;

            update(1, 0, n - 1, index, value);

            Node res = query(1, 0, n - 1, start, n - 1);

            ans.push_back(res.cnt[1 % K][x]);
        }

        return ans;
    }
};