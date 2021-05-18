class Solution {
public:
    int maxValue(int n, int k, int maxSum) {
        maxSum-= n;
        int ans=0,l=0,r=maxSum,xx=n-k-1;
        long long int cnt=0;
        
        while(l<=r)
        {
            long long int mid=l+(r-l)/2;
            cnt = mid + (mid*(mid-1));
            cnt-= (mid>k?((mid-1-k)*(mid-k)/2):0);
            cnt-= ((mid>xx?((mid-1-xx)*(mid-xx)/2):0));
            if(cnt<= maxSum)
            {
                ans=mid;
                
                l=mid+1;
            }
            else r=mid-1;
            
        }
        
        return ans+1;
        
    }
};