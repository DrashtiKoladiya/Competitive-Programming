class Solution {
public:
    int minOperations(vector<int>& a, int x) {
        int n=a.size(),ans=INT_MAX,f=0;
        vector<long long int> prefix(n+1,0),suffix(n+1,0);
        
        prefix[0]=0,suffix[0]=0;
        for(int i=0;i<n;i++)
        {
            prefix[i+1] = prefix[i]+a[i];
            suffix[i+1]= suffix[i]+a[n-i-1];
        }
        
        for(int i=0;i<=n;i++)
        {
            int idx=lower_bound(suffix.begin(),suffix.begin()+(n-i),x-prefix[i])-suffix.begin();
            if(suffix[idx]==x-prefix[i])
            {
                f=1;
                ans=min(ans,idx+i);
            }
        }
        if(!f) return -1;
        return ans;
    }
};