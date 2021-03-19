class Solution {
public:
    vector<int> dp;
    int go(int curr,vector<int>& prices,int n)
    {
        if(curr>=n)
        {
            return 0;
        }
        if(dp[curr]!=-1)
        {
            return dp[curr];
        }
        
        int ans=0;
        for(int i=curr+1;i<n;i++)
        {
            if(prices[i]>prices[curr])
            {
                ans=max(ans,go(i+2,prices,n)+prices[i]-prices[curr]);
            }
        }
        
        ans=max(ans,go(curr+1,prices,n));
        return dp[curr]=ans;
    }
    
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        dp.resize(n+1,-1);
        int ans = go(0,prices,n);
        return ans;
    }
};



//////////////////////////////////////////////////////////////////////////////////

class Solution {
public:
    
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        
        int noStock1,noStock2,currHold1,currHold2,sold1,sold2;
        noStock1=0,currHold1=-prices[0],sold1=0;
        
        for(int i=0;i<n;i++)
        {
            noStock2 = max(noStock1,sold1);
            currHold2 = max(currHold1,noStock1-prices[i]);
            sold2 = currHold1+prices[i];
            
            noStock1=noStock2;
            currHold1=currHold2;
            sold1=sold2;
        }
        
        return max(noStock1,sold1);
    }
};