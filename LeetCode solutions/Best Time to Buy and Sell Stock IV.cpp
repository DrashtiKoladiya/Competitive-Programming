class Solution {
public:
    int maxProfit(int num,vector<int>& prices) 
    {
        int n=prices.size();
        if(num>=(n/2))
        {
            long long int dp0=0,dp0_prev=0,dp1=INT_MIN,dp1_prev=INT_MIN;
            for(int i=0;i<n;i++)
            {
                dp0 = max(dp0_prev , dp1_prev+prices[i]);
                dp1 = max(dp1_prev , dp0_prev-prices[i]);
                
                dp0_prev = dp0;
                dp1_prev = dp1;
            }
            return dp0;
        }
        
        // when num<=(n/2)
        long long int dp[n][num+1][2];
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<=num;j++)
            {
                dp[i][j][0]=0;
                dp[i][j][1]=INT_MIN;
            }
        }
        
        for(int i=0;i<n;i++)
        {
                for(int k=0;k<=num;k++)
                {
                    if(k==0)
                    {
                        dp[i][k][0]=0;
                        dp[i][k][1]=INT_MIN;
                    }
                    else if(i==0)
                    {
                        dp[i][k][0]=0;
                        dp[i][k][1]=-prices[i];
                    }
                    else
                    {
                        dp[i][k][0] = max(dp[i-1][k][0],dp[i-1][k][1]+prices[i]);
                        dp[i][k][1] = max(dp[i-1][k][1],dp[i-1][k-1][0]-prices[i]);
                    }
                }
        }
        
        return dp[n-1][num][0];
    }
};