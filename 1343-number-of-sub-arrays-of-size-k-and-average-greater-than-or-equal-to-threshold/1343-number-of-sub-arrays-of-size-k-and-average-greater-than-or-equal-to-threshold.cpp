class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int n = arr.size();
        int sum1 = k*threshold;
        int sum = 0, count = 0;
        
        for(int i = 0; i < k; i++){
            sum+=arr[i];
        }
        if(sum>=sum1){
            count++;
        }

        for(int i = k; i < n; i++){
            sum+=arr[i];
            sum-=arr[i - k];

            if(sum>=sum1){
                count++;
            }
        }

        return count;
    }
};