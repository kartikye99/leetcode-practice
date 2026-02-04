class Solution {
public:
    bool ndays(vector<int>& weights, int days, int mid){
        int d = 1;
        int sum = 0;
        for(int i = 0;i<weights.size();i++){
            if(sum+weights[i]>mid){
                d++;
                sum = weights[i];
            }
            else{
                sum+=weights[i];
            }
        }
        return d<=days;
    }

    int shipWithinDays(vector<int>& weights, int days) {
        int low =  *max_element(weights.begin(), weights.end());
        int high = accumulate(weights.begin(), weights.end(), 0);
        int ans=0;
        while(low<=high){
            int mid = (low+high)/2;
            if(ndays(weights,days,mid)){
                ans = mid;
                high = mid-1;
            }
            else{
                low = mid+1;
                // high = mid;
            }
        }
        return ans;
    }
};