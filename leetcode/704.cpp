class Solution {
public:
    int search(vector<int>& nums, int target) {
        int low = 0;
        int high = nums.size()-1;
        int mid;
        while(low <= high){
            mid = low + (high - low)/2;
            if(target == nums[mid]){
                return mid;
            }
            if(target > nums[mid]){
                low = mid + 1;
            }
            else{
                high = mid -1;
            }
        }
        return -1; 
    }
};