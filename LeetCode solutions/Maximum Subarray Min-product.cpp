class Solution {
public:
    int maxSumMinProduct(vector<int>& nums) {
        
        long long int n=nums.size(),ans=-1;
        int mod = 1e9+7;
        vector<long long int> v(n),l(n),r(n);
        stack<int> s;
        for(int i=0;i<n;i++)
        {
            v[i]=nums[i];
            l[i]=-1;
            r[i]=n-1;
        }
        
        for(int i=0;i<n;i++)
        {
            while(!s.empty() && nums[s.top()]>=nums[i])
            {
                int x=s.top();
                s.pop();
                r[x]=i-1;
            }
            if(!s.empty()) 
            {
                l[i]=s.top();
            }
            s.push(i);
        }    
        
        for(int i=1;i<n;i++) v[i] = (v[i]+v[i-1]);
        
        
        for(int i=0;i<n;i++)
        {
            long long int x=0;
            x+= v[r[i]];
            if(l[i]>=0) x-= v[l[i]];
            x=(x*nums[i]);
            ans = max(ans,x);
        }
        
        return ans%mod;
    }
};