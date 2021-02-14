class Solution {
public:
    int findBestValue(vector<int>& arr, int target) {
        long long int ans=INT_MAX,l,r,n,val=INT_MAX;
        n=arr.size();
        l=0;
        r=*max_element(arr.begin(),arr.end());
        while(l<=r)
        {
            long long int mid=l+(r-l)/2,sum=0;
            for(int i=0;i<n;i++)
            {
                sum+= min(mid,(long long int)arr[i]);
            }
            if(abs(sum-target)<=val)
            {
                if(abs(sum-target)==val)
                {
                    ans=min(ans,mid);
                }
                else
                {
                    val=abs(sum-target);
                    ans=mid;
                }
            }
            if(sum>target) 
            {
                r=mid-1;
            }
            else 
            {
                l=mid+1;
            }
        }
        
        return ans;
    }
};