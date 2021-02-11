class Solution {
public:
    int divide(int dividend, int divisor) {
        long long int n,m,f=0,curr=0,q=0;
        n=dividend,m=divisor;
        if((n<0 || m<0) && !(n<0 && m<0)) f=1;
        n=abs(n);
        m=abs(m);
        for(long i=31;i>=0;i--)
        {
            if((curr+(m<<i))<=n)
            {
                curr+= (m<<i);
                q = q|(1LL<<i);
            }
        }
        if(f) q=-q;
        if(q<INT_MIN || q>INT_MAX) return INT_MAX;
        return q;
    }
};