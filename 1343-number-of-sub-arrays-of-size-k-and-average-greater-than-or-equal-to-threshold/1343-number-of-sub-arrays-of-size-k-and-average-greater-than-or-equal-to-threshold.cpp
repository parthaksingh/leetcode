class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int n = arr.size();
        int sum1 = k*threshold;
        int sum = 0, count = 0, r = 0, l = 0;
        
        while(r<n){
            sum += arr[r];

            if(r - l + 1 == k){
                if(sum>=sum1){
                    count++;
                }

                sum -=arr[l];
                l++;
            }
            
            r++;
        }
        return count;
    }
};