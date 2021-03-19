//pattern search algo

int Solution::strStr(const string b, const string a) 
{
    int n,m,x,y;
    n=a.size();
    m=b.size();
    
    if(m==0 || n==0) return -1;
    long long int p=256,total=1,bb=0,aa=0,M=308457624821;
    
    for(int i=1;i<n;i++)
    {
        total = (total*p)%M;
    }
    for(int i=0;i<n;i++)
    {
        aa = ((aa*p)%M + a[i])%M;
        bb = ((bb*p)%M + b[i])%M;
    }
    
    for(int i=0;i<=(m-n);i++)
    {
        if(aa==bb)
        {
            return i;
        }
        bb = (((p*((bb-((b[i]*total)%M))+M)%M))%M + b[i+n])%M;
    }
    
    return -1;
}
