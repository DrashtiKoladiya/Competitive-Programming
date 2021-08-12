typedef vector<long long> vll;
#define fr(i,s,e) for(int i=s;i<e;i++)
#define rf(i,s,e) for(int i=s-1;i>=e;i--)
#define ll long long int 

ll NN=1005,MOD=1000000007,ans=-1;
vll fact(NN),invfact(NN),dp(NN,-1);

ll NcR(ll n,ll r)
{	
    if(n<0 || r<0 || r>n) return 0;
    return (fact[n]*((invfact[n-r]*invfact[r])%MOD))%MOD;
}

void EE(ll a,ll b,ll &x,ll &y)
{	if(b==0)
    {
        x=1,y=0; return;
    }		
    EE(b,a%b,x,y);
    ll temp=x; x=y; y=temp-(a/b)*y;
}
ll inverse(ll a,ll mod)
{	
    ll x,y;
    EE(a,mod,x,y);
    return (x+mod)%mod;
}
void build()
{
    ans=1;
    fact[0]=1;
    fr(i,1,NN) fact[i]=(fact[i-1]*i)%MOD;
    invfact[NN-1]=inverse(fact[NN-1],MOD); 
    rf(i,NN-1,0) invfact[i]=(invfact[i+1]*(i+1))%MOD;
}

ll getLeft(ll n)
{
    if (n == 1)
        return 0;
  
    ll h = log2(n);
    ll numh = (1 << h);
    ll last = n - ((1 << h) - 1);
    if (last >= (numh / 2))
        return (1 << h) - 1;
    else
        return (1 << h) - 1 - ((numh / 2) - last);
}

ll go(ll n)
{
    if(n<=1) return 1;
    ll ans=dp[n];
    if(ans!=-1)
    {
        return ans;
    }
    
    ll l=getLeft(n);
    ans = (((NcR(n-1,l)*go(l))%MOD)*go(n-1-l))%MOD;
    
    return dp[n]=ans;
}

int Solution::solve(int n) 
{
    if(ans==-1) build();
    return go(n);
}
