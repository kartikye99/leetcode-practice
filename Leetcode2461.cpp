class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        long long sum = 0;
        int l = 0;
        long long maxsum = 0;
        unordered_map<int , int>freq;
        for(int i = 0;i<nums.size();i++){
            sum+=nums[i];
            freq[nums[i]]++;

            if(i-l+1>k){
                freq[nums[l]]--;
                sum-=nums[l];

                if(freq[nums[l]]==0){
                    freq.erase(nums[l]);
                }
                    l++;
            }

            if(i-l+1 == k && freq.size() == k ){
                maxsum = max(maxsum,sum);
            }
        }
        return maxsum;
    }
};