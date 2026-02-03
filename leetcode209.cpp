class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int sum = 0;
        int ans = INT_MAX;
        int l =0;
        for(int i = 0;i<nums.size();i++){
         sum+=nums[i];
        }
        ans = sum;
        while(sum>target){
            ans= min(ans,sum);  
            sum-=nums[l];
            l++;
        }
        return ans==INT_MAX?0:ans;
    }
};