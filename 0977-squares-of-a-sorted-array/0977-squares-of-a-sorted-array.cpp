class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {

        map<int, int>mp;
        for(int x: nums){
            mp[x*x]++;
        }
        vector<int> ans;

        for(auto it : mp){
            while(it.second--){
                ans.push_back(it.first);
            }
        }
        return ans;
    }
};