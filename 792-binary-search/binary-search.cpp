class Solution {
public:
    int binary_s(vector<int> & nums, int target,int low, int high)
    {
        if(low>high)return -1;
        int mid=low+(high-low)/2;
            if(nums[mid]==target)
            {
                return mid;
            }
            else if(nums[mid]< target)
            {
                return binary_s(nums,target,mid+1,high);
            }
            else
            {
                return binary_s(nums,target,low,mid-1);
            }
        }
    
    int search(vector<int>& nums, int target) {
        int n=nums.size();
        int low=0,high=n-1;
        return binary_s(nums,target,low,high);
        
        
    }
};