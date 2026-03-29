class Solution {
public:
    int fs(vector<int> &arr, int low, int high){
        int i = low;
        int j = high;
        int pivot = arr[low];
        while(i<j){
            while(arr[i]<=pivot && i <= high){
                i++;
            }
            while(arr[j]> pivot && j >= low){
                j--;
            }
            if(i<j){
                swap(arr[i],arr[j]);
            }
        }
        swap(arr[low],arr[j]);
        return j;
    }

    void qs(vector<int> &arr, int low, int high){
        if(low<high){
        int pindex = fs(arr,low,high);
        qs(arr, low , pindex-1);
        qs(arr, pindex+1, high);
        }
    }
    vector<int> quickSort(vector<int>& nums) {
        int n = nums.size();
        qs(nums, 0 , n-1);
        return nums;
    }
};
