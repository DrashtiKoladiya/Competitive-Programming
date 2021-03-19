class Solution {
public:
    int maxProfit(vector<int>& prices) 
    {
        int n=prices.size();
        long long int dp[n][3][2];
        
        for(int k=0;k<3;k++)
        {
            for(int i=0;i<n;i++)
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
        
        return dp[n-1][2][0];
    }
};