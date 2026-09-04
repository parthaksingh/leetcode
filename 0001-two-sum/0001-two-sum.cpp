class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        vector<pair<int, int>> v1;
        int left = 0, right = n - 1;

        for(int i = 0; i < n; i++){
            v1.push_back({nums[i], i});
        }

        sort(v1.begin(), v1.end());

        while(left < right){
            int sum = v1[left].first + v1[right].first;

            if(sum == target){
                return {v1[left].second, v1[right].second};
            }else if(sum > target){
                right--;
            }else{
                left++;
            }
        }
        return {};

    }
};