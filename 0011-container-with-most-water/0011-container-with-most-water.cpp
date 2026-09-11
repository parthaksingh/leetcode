class Solution {
public:
    int maxArea(vector<int>& hei) {
        int n = hei.size();
        int l = 0, r = n - 1, ans = 0;

        while(l < r){
            int w = r - l;
            int high = min(hei[l], hei[r]);

            int area = w*high;
            ans = max(ans, area);

            if(hei[l] < hei[r]){
                l++;
            }else{
                r--;
            }
        }
        return ans;
    }
};