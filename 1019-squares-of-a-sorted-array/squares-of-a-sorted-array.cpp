class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        //either extra space or sort
        int n=nums.size();
        vector<int> ans(n);
        int i=0,j=n-1;
        int pos=n-1;
        while(i<=j)
        {
            int left=(nums[i])*(nums[i]);
            int right=nums[j]*nums[j];
            if(left>right)
                {
                    ans[pos]=left;
                    i++;
                }
                else
                {
                    ans[pos]=right;
                    j--;
                }
                pos--;

        }
        return ans;
    }
};