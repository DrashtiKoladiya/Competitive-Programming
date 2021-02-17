#define M 1000003
vector<long long int> f(55,0);

long long int calculate(long long int n)
{
    if(n<=1) return 1;
    else
    {
        return f[n] = (n*calculate(n-1))%M;
    }
}

int Solution::findRank(string s1) {
    string s=s1;
    sort(s.begin(),s.end());
    long long int ans=0;
    long long int n=s.size();
    vector<int> vis(n,0);
    
    f[0]=1;
    f[1]=2;
    calculate(n-1);
    
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(vis[j]) continue;
            if(s[j]!=s1[i])
            {
                ans = (ans+f[n-1-i])%M;
            }
            else
            {
                vis[j]=1;
                break;
            }
        }
        cout<<ans<<"\n";
    }
    
    return ans+1;
}
