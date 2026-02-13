class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int , int> mp;
        for(int v : nums){
            mp[v]++;
        }
        for(auto vg : mp){
            if(vg.second == 1){
                return vg.first;
            }
        }
        return 0;
    }
};