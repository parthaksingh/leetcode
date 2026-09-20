class Solution {
public:
    int reverseDegree(string s) {
        int n = s.size();
        int result = 0;
        for(int i = 0; i < n; i++){
            result += ('z' - s[i] + 1) * (i+ 1);
        }
        return result;
    }
};