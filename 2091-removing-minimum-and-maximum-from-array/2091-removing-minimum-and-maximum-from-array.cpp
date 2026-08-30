class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size();
        int minIndex = 0;
        int maxIndex = 0;

        for(int i = 1; i < n; i++){
            if(nums[i] < nums[minIndex]){
                minIndex = i;
            }
            if(nums[i] > nums[maxIndex]){
                maxIndex = i;
            }
        }
        int a = max(minIndex, maxIndex) + 1;
        int b = n - min(minIndex, maxIndex);
        int c = min(minIndex, maxIndex) + 1+n - max(maxIndex, minIndex);

        return min({a, b, c});
    }
};