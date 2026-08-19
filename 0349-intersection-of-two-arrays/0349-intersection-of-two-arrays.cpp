class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> mp;

        vector<int> ans;
        for(int x: nums1){
            mp.insert(x);
        }

        for(int x: nums2){
            if(mp.find(x) != mp.end()){
                ans.push_back(x);
                mp.erase(x);
            }
        }
        return ans;
    }
};