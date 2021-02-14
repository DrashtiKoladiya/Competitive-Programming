class Solution {
public:
    int dp[201][201];
    int dpp(int s,int e)
    {
        if(s==e) return 0;
        if(s+1==e) return min(s,e);
        if(dp[s][e]!=-1) return dp[s][e];
        dp[s][e]=INT_MAX;
        for(int i=s+1;i<e;i++)
        {
            dp[s][e] = min(dp[s][e],max(dpp(s,i-1),dpp(i+1,e))+i);
        }
        return dp[s][e];
    }
    int getMoneyAmount(int n) {
        memset(dp,-1,sizeof(dp));
        return dpp(1,n);
    }
};