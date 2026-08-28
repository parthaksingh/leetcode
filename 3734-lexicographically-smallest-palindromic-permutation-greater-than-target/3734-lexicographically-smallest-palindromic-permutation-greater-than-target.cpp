class Solution {
public:

    string makePalindrome(string half, char mid, bool odd) {
        string right = half;
        reverse(right.begin(), right.end());

        if (odd)
            return half + string(1, mid) + right;

        return half + right;
    }

    string nextGreater(string half, string targetHalf) {
        int m = half.size();

        int original[26] = {};

        for (char c : half)
            original[c - 'a']++;

        for (int i = m - 1; i >= 0; i--) {

            int cnt[26];

            for (int j = 0; j < 26; j++)
                cnt[j] = original[j];

            bool possible = true;

            for (int j = 0; j < i; j++) {

                int x = targetHalf[j] - 'a';

                if (cnt[x] == 0) {
                    possible = false;
                    break;
                }

                cnt[x]--;
            }

            if (!possible)
                continue;

            int current = targetHalf[i] - 'a';

            for (int c = current + 1; c < 26; c++) {

                if (cnt[c] == 0)
                    continue;

                string ans = targetHalf.substr(0, i);

                ans += char('a' + c);

                cnt[c]--;

                for (int x = 0; x < 26; x++) {
                    while (cnt[x] > 0) {
                        ans += char('a' + x);
                        cnt[x]--;
                    }
                }

                return ans;
            }
        }

        return "";
    }

    string lexPalindromicPermutation(string s, string target) {

        int n = s.size();

        int freq[26] = {};

        for (char c : s)
            freq[c - 'a']++;

        int oddCount = 0;
        char mid = '\0';

        for (int i = 0; i < 26; i++) {

            if (freq[i] % 2) {
                oddCount++;
                mid = char('a' + i);
            }
        }

        if (oddCount != n % 2)
            return "";

        string half = "";

        for (int i = 0; i < 26; i++) {

            for (int j = 0; j < freq[i] / 2; j++)
                half += char('a' + i);
        }

        int m = n / 2;

        string targetHalf = target.substr(0, m);

        int cnt[26] = {};

        for (char c : half)
            cnt[c - 'a']++;

        bool possible = true;

        for (char c : targetHalf) {

            int x = c - 'a';

            if (cnt[x] == 0) {
                possible = false;
                break;
            }

            cnt[x]--;
        }

        if (possible) {

            string candidate =
                makePalindrome(targetHalf, mid, n % 2);

            if (candidate > target)
                return candidate;
        }

        string next = nextGreater(half, targetHalf);

        if (next == "")
            return "";

        return makePalindrome(next, mid, n % 2);
    }
};