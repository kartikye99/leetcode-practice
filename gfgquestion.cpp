class Solution {
  public:
    int maxSubarraySum(vector<int>& arr, int k) {
        // code here
        int sum = 0;
        for(int i =0; i<k;i++){
            sum+=arr[i];
        }
        int maxsum = sum;
        
        for(int i = k;i<arr.size();i++){
            sum +=arr[i];
            sum = sum - arr[abs(k-i)];
            maxsum = max(maxsum,sum);
        }
        
        return maxsum;
    }
};