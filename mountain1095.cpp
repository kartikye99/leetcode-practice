/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:
    int findInMountainArray(int target, MountainArray &mountainArr) {
        int s = 0;
        int end = mountainArr.length() - 1;
        // int n = 0;
        while(s<end){
            int mid = (s+end)/2;
            if(mountainArr.get(mid)<mountainArr.get(mid+1)){
                s = mid+1;
            }
            else{
                end = mid;
            }
        }
        int peak = s;
        s = 0 , end = peak;
        while(s<=end){
            int mid = (s+end)/2;
            if( mountainArr.get(mid)==target){
                return mid;
            }
            else if( mountainArr.get(mid)>target){
                end = mid-1;
            }
            else{
                s = mid +1;
            }
        }
        s = peak+1;
        end = mountainArr.length() - 1;
        while(s<=end){
            int mid = (s+end)/2;
            if(mountainArr.get(mid)==target){
                return mid;
            }
            else if( mountainArr.get(mid)>target){
                s = mid +1;
            }
            else{
                end = mid-1;
            }

        }
        return -1;
    }
};
