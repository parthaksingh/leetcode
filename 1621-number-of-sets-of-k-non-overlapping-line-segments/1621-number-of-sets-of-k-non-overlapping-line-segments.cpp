class Solution {
public:
    long long power(long long a, long long b) {
        long long MOD = 1000000007;
        long long ans = 1;

        while(b > 0) {
            if(b % 2 == 1)
                ans = ans * a % MOD;

            a = a * a % MOD;
            b /= 2;
        }

        return ans;
    }

    int numberOfSets(int n, int k) {
        long long MOD = 1000000007;

        long long ans = 1;

        for(int i = 1; i <= 2 * k; i++) {
            ans = ans * (n + k - i) % MOD;
            ans = ans * power(i, MOD - 2) % MOD;
        }

        return ans;
    }
};