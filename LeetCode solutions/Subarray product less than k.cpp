class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        long long int i=0,j=0,product=1,cnt=0,n=nums.size();
        for(int j=0;j<n;j++)
        {
            product*= nums[j];
            while(product>=k && i<=j)
            {
                product/= nums[i];
                i++;
            }
            cnt+= (j-i+1);
        }
        return cnt;
    }
};