#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxLength(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;

        for (int i = 0; i < n; i++) {
            long long prod = 1;
            long long l = 1;
            int g = 0;

            for (int j = i; j < n; j++) {
                int x = nums[j];

                prod *= x;
                g = gcd(g, x);

                l = (l / gcd((int)l, x)) * x;

                if (prod == l * g) {
                    ans = max(ans, j - i + 1);
                }

                if (prod > l * g) {
                    break;
                }
            }
        }

        return ans;
    }
};