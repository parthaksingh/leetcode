class Solution {
public:

    string makePalindrome(string half, char mid, bool odd) {
        string right = half;
        reverse(right.begin(), right.end());

        if (odd)
            return half + string(1, mid) + right;

        return half + right;
    }

    // Find the smallest permutation of "half"
    // that is strictly greater than "targetHalf"
    string nextGreater(string half, string targetHalf) {

        int m = half.size();

        int original[26] = {};

        for (char c : half)
            original[c - 'a']++;

        // Try changing targetHalf[i]
        // starting from the RIGHT side.
        for (int i = m - 1; i >= 0; i--) {

            int cnt[26];

            for (int j = 0; j < 26; j++)
                cnt[j] = original[j];

            // Use targetHalf[0 ... i-1]
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

            // At position i, choose the smallest
            // character greater than targetHalf[i]
            int current = targetHalf[i] - 'a';

            for (int c = current + 1; c < 26; c++) {

                if (cnt[c] == 0)
                    continue;

                string ans = targetHalf.substr(0, i);

                ans += char('a' + c);

                cnt[c]--;

                // Fill the rest with smallest characters
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

        // -------------------------------
        // Check whether palindrome possible
        // -------------------------------

        int oddCount = 0;
        char mid = '\0';

        for (int i = 0; i < 26; i++) {

            if (freq[i] % 2) {
                oddCount++;
                mid = char('a' + i);
            }
        }

        // Even length -> 0 odd characters
        // Odd length  -> 1 odd character
        if (oddCount != n % 2)
            return "";

        // -------------------------------
        // Build left half
        // -------------------------------

        string half = "";

        for (int i = 0; i < 26; i++) {

            for (int j = 0; j < freq[i] / 2; j++)
                half += char('a' + i);
        }

        int m = n / 2;

        string targetHalf = target.substr(0, m);

        // -------------------------------
        // Can targetHalf itself be formed?
        // -------------------------------

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

        // -------------------------------
        // Case 1:
        // targetHalf is possible
        // -------------------------------

        if (possible) {

            string candidate =
                makePalindrome(targetHalf, mid, n % 2);

            // It must be STRICTLY greater
            if (candidate > target)
                return candidate;
        }

        // -------------------------------
        // Case 2:
        // Find next greater half
        // -------------------------------

        string next = nextGreater(half, targetHalf);

        if (next == "")
            return "";

        return makePalindrome(next, mid, n % 2);
    }
};