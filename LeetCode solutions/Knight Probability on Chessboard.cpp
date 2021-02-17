class Solution {
public:
    pair<int,int> pos[8] = {{-2,-1},{-2,1},{2,-1},{2,1},{-1,-2},{-1,2},{1,-2},{1,2}};
    map<pair<int,pair<int,int>>,double> m;
    double go(int n,int k,int r,int c)
    {
        if(r<0 || c>=n || c<0 || r>=n) return 0;
        if(k==0) return 1;
        if(m.find({k,{r,c}})!=m.end())  return m[{k,{r,c}}];
        double ans=0;
        for(int i=0;i<8;i++)
        {
            ans+= go(n,k-1,r+pos[i].first,c+pos[i].second)/(8.0);
        }
        return m[{k,{r,c}}]=ans;
    }
    double knightProbability(int N, int K, int r, int c) {
      //pos[0]=
      return go(N,K,r,c);   
    }
};