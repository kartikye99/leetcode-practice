class Solution {
public:
    int findmax(vector<int> &v){
        int maxi = INT_MIN;
        for(int i = 0; i < v.size(); i++){
            maxi = max(maxi, v[i]);
        }
        return maxi;
    }

    long long calculateHour(vector<int>& v, int k){
        long long totalH = 0;
        for(int i = 0; i < v.size(); i++){
            totalH += (v[i] + k - 1) / k; // ✅ optimized
        }
        return totalH;
    }

    int minEatingSpeed(vector<int>& v, int h) {
        int low = 1;
        int high = findmax(v);

        while(low <= high){
            int mid = (low + high) / 2;

            long long totalH = calculateHour(v, mid);

            if(totalH <= h){
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return low;
    }
};