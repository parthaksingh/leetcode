class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int minEl = *min_element(nums1.begin(), nums1.end());

        if(minEl % 2 != 0){
            return true;
        }

        for(int &num : nums1){
            if(num % 2 == 1){
                return false;
            }
        }
        return true;
    }
};