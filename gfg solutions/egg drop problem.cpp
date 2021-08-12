class Solution {
public:
    vector<vector<int>> dp;
    int go(int e,int f)
    {
        if(e==0) return INT_MAX;
        if(f==0) return 0;
        if(e==1) return f;
        
        if(dp[f][e]!=-1) return dp[f][e];
        
        int ans=INT_MAX;
        for(int i=1;i<=f;i++)
        {
            ans = min(ans,max(go(e-1,i-1),go(e,f-i))+1);
        }
        
        return dp[f][e]=ans;
    }

    int twoEggDrop(int n) {
        dp=vector<vector<int>>(n+1,vector<int>(3,-1));
        return go(2,n);
    }
};