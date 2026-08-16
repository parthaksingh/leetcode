class Solution {
public:
    char findTheDifference(string s, string t) {
        char ans = 0;
        for(char m : s){
            ans^=m;
        }
        for(char n : t){
            ans^=n;
        }
        return ans;
    }
};