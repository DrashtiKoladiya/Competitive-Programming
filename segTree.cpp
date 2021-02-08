//Segment tree for MAX-MIN range Query


#include <bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define zad tree<int, nuint_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>
using namespace std;

#define in1(x) scanf("%lld",&x)
#define in2(x,y) scanf("%lld%lld",&x,&y)
#define in3(x,y,z) scanf("%lld%lld%lld",&x,&y,&z)
#define out(x) printf("%lld",x)
#define outspace(x) printf("%lld ",x)
#define outln(x) printf("%lld\n",x)

#define int long long
#define ld long double
#define pb push_back
#define p push
#define mkp make_pair
#define ff first
#define Pint pair<int,int>
#define PSS pair<string,string>
#define ss second
#define precision(x,d) cout<<fixed<<setprecision(d)<<x
#define minQueue priority_queue<Pint,vector<Pint>,greater<Pint> >
#define maxQueue priority_queue<int,vector<int>,less<int> >
#define aint(x) x.begin(),x.end()
#define F(i,a,b) for(int i=a;i<b;i++)
#define RF(i,a,b) for(int i=a;i>b;i--)
#define mset(a,b) memset((a),(b),sizeof((a)))
#define IOS ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);srand(time(NULL));
#define MOD 1000000007
#define RMOD 998244353
#define INF 10000000000000000
#define MINF LONG_LONG_MIN
#define MAXF LONG_LONG_MAX
const int N=1000002;
#define OuterLoop int t;scanf("%lld",&t);while(t--)
#define lcm(a,b) a*b/(__gcd(a,b))

struct SegTree{

    //int t[80009]={0},t1[80009]={0},s[80009]={0};
    int nn;
    vector<int> t,t1,s;
    void init(int n)
    {
        nn=n;
        t = vector<int>(4*nn+5);
        t1=vector<int>(4*nn+5);
        s=vector<int>(n+5);
    }

    //Building Segement tree for MAX-MIN range query
    void build(int v,int tl,int tr)
    {
        if(tl==tr) t[v]=t1[v]=s[tl];
        else
        {
            int tm=tl+(tr-tl)/2;
            build(2*v,tl,tm);
            build(2*v+1,tm+1,tr);
            t[v]=min(t[2*v],t[2*v+1]);
            t1[v]=max(t1[2*v],t1[2*v+1]);
        }   
    }

    //Range minimum Query
    int RMQ(int v,int tl,int tr,int l,int r)
    {
        if(l>r) return MOD;
        if(l==tl && r==tr) return t[v];
        else
        {
            int tm=tl+(tr-tl)/2;
            return min(RMQ(2*v,tl,tm,l,min(r,tm)),RMQ(2*v+1,tm+1,tr,max(tm+1,l),r));
        }
    }

    //Range Maximum Query
    int RMXQ(int v,int tl,int tr,int l,int r)
    {
        if(l>r) return -MOD;
        if(l==tl && r==tr) return t1[v];
        else
        {
            int tm=tl+(tr-tl)/2;
            return max(RMXQ(2*v,tl,tm,l,min(r,tm)),RMXQ(2*v+1,tm+1,tr,max(tm+1,l),r));
        }
    }
};

int32_t main()
{
    return 0;
}