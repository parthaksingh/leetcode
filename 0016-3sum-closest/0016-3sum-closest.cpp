class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int closestsum = 100000;
        for(int i = 0; i < n-2; i++){
            int j = i + 1;
            int k = n - 1;
            while(j < k){
                int sum = nums[i] + nums[j] + nums[k];

                if(abs(target - sum) < abs(target - closestsum)){
                    closestsum = sum;
                }
                if(sum < target){
                    j++;
                }else{
                    k--;
                }
            }
        }
        return closestsum;
    }
};