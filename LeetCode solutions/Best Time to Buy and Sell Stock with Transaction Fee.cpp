class Solution {
public:
    
    int maxProfit(vector<int>& prices, int f) {
        int n=prices.size();
        long int dp0=0,dp0_prev=0,dp1=INT_MIN,dp1_prev=INT_MIN;
        for(int i=0;i<n;i++)
        {
            dp0 = max(dp0_prev,dp1_prev+prices[i]-f);
            dp1 = max(dp1_prev,dp0_prev-prices[i]);
            
            dp0_prev = dp0;
            dp1_prev = dp1;
        }
        
        return dp0;
    }
};