#include<bits/stdc++.h>
using namespace std;
//#include <boost/multiprecision/cpp_int.hpp> 
//using boost::multiprecision::cpp_int; 
#define ll long long int

/*
// Dp solution 
ll catalan(ll n)
{
    ll catalan[n+1]={0};
    catalan[0]=catalan[1]=1;
    for(ll i=2;i<=n;i++)
    {
        catalan[i]=0;
        for(ll j=0;j<i;j++)
        {
            catalan[i]+= catalan[j]*catalan[i-j-1];
        }
    }
    return catalan[n];
}
*/


//using binomial cofficient
ll binomial(ll n,ll k)
{
    ll ans=1;
    if(k>n-k) k=n-k;

    for(ll i=0;i<k;++i)
    {
        ans*= (n-i);
        ans/= (i+1);
    }

    return ans;
}

ll catalan(ll n)
{
    ll c=binomial(2*n,n);
    return c/(n+1);
}

// we can also use above libarary in the case when our number might become too large to fit into long int

