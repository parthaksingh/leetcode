class Solution {
public:
    int maxVowels(string s, int k) {
        int l = 0, r = 0, count = 0, maxcount = 0;

        while(r < s.size()){
            if(s[r] == 'a' || s[r] == 'e' || s[r] == 'i' || s[r] == 'o' || s[r] == 'u'){
                count++;
            }
            if(r - l + 1 == k){
                maxcount = max(count, maxcount);
            if(s[l] == 'a' || s[l] == 'e' || s[l] == 'i' || s[l] == 'o' || s[l] == 'u'){
                count--;
            }
            l++;
            }
            r++;
        }
        return maxcount;
    }
};