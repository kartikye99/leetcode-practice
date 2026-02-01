class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
       int pro = 1;
       int l = 0;
       int count = 0;
       for(int i = 0;i<nums.size();i++){
        pro*=nums[i];

        while(pro>=k){
            pro/=nums[l];
            l++;
        }
        count+=(i-l+1);
       } 
       return count;
    }
};