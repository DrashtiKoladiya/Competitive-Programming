int Solution::books(vector<int> &A, int B) {
    long long int l,r,n,ans;
    l=*max_element(A.begin(),A.end());
    ans=l;
    n=A.size();
    r=0;
    for(int i=0;i<n;i++)
    {
        r+= A[i];
    }
    
    if(n<B) return -1;
    
    while(l<=r)
    {
        long long int mid=l+(r-l)/2,student=1,cnt=0,mx=0;

        for(int i=0;i<n;i++)
        {
            if(cnt+A[i]>mid)
            {
                mx=max(mx,cnt);
                student++;
                cnt=A[i];
            }
            else cnt+= A[i];
        }
        mx=max(mx,cnt);
        
        if(student==B)
        {
            ans=mx;
            r=mid-1;
        }
        else if(student>B) l=mid+1;
        else r=mid-1; 
    }

    return ans;
}
