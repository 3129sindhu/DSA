class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n=nums.size();
        int maxi=INT_MIN;
        int prefixprod=1;
        int suffixprod=1;
for(int i =0;i<n;i++)
{
    if(prefixprod==0) prefixprod=1;
    if(suffixprod==0) suffixprod=1;
    prefixprod*=nums[i];
    suffixprod*=nums[n-i-1];
    maxi=max(maxi,max(prefixprod,suffixprod));
}
return maxi;
    }
};