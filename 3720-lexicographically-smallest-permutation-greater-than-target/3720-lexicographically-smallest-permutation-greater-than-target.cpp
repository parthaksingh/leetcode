class Solution {
public:
    string lexGreaterPermutation(string s, string target) {
        int freq[26] = {};

        for (char c : s) {
            freq[c - 'a']++;
        }

        for (int i = 0; i < target.size(); i++) {
            int x = target[i] - 'a';

            if (freq[x] > 0) {
                freq[x]--;
                continue;
            }

            for (int j = x + 1; j < 26; j++) {
                if (freq[j] > 0) {
                    string ans = target.substr(0, i);

                    ans += char('a' + j);
                    freq[j]--;

                    for (int k = 0; k < 26; k++) {
                        while (freq[k] > 0) {
                            ans += char('a' + k);
                            freq[k]--;
                        }
                    }

                    return ans;
                }
            }

            for (int p = i - 1; p >= 0; p--) {
                int prev = target[p] - 'a';

                freq[prev]++;

                for (int j = prev + 1; j < 26; j++) {
                    if (freq[j] > 0) {
                        string ans = target.substr(0, p);

                        ans += char('a' + j);
                        freq[j]--;

                        for (int k = 0; k < 26; k++) {
                            while (freq[k] > 0) {
                                ans += char('a' + k);
                                freq[k]--;
                            }
                        }

                        return ans;
                    }
                }
            }

            return "";
        }

        for (int p = target.size() - 1; p >= 0; p--) {
            int prev = target[p] - 'a';

            freq[prev]++;

            for (int j = prev + 1; j < 26; j++) {
                if (freq[j] > 0) {
                    string ans = target.substr(0, p);

                    ans += char('a' + j);
                    freq[j]--;

                    for (int k = 0; k < 26; k++) {
                        while (freq[k] > 0) {
                            ans += char('a' + k);
                            freq[k]--;
                        }
                    }

                    return ans;
                }
            }
        }

        return "";
    }
};
