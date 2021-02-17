int Solution::solve(vector<int> &A, int B, int C) {
    vector<int> v;
    int c=C,ans=0,n=A.size();
    while(c)
    {
        v.push_back(c%10);
        c/= 10;
    }
    reverse(v.begin(),v.end());
    int nv=v.size(),f=0;
    if(B>nv) return 0;
    if(B<nv)
    {
        if(B==1) return n;
        else
        {
            int cnt=0;
            for(int i=0;i<n;i++) if(A[i]) cnt++;
            return cnt*pow(n,B-1);;
        }
    }
    for(int i=0;i<v.size();i++)
    {
        f=0;
        for(int j=0;j<n;j++)
        {
            if(A[j]==v[i]) f=1;
            if(A[j]<v[i] && A[j]) ans+= pow(n,nv-1-i);
            if(A[j]<v[i] && !A[j] && (nv==1 || i!=0)) ans+= pow(n,nv-1-i);
        }
        if(f==0) break;
    }
    //cout<<"\n";
    return ans;
    
}
int Solution::solve(vector<int> &A, int B, int C) {
    vector<int> v;
    int c=C,ans=0,n=A.size();
    while(c)
    {
        v.push_back(c%10);
        c/= 10;
    }
    reverse(v.begin(),v.end());
    int nv=v.size(),f=0;
    if(B>nv) return 0;
    if(B<nv)
    {
        if(B==1) return n;
        else
        {
            int cnt=0;
            for(int i=0;i<n;i++) if(A[i]) cnt++;
            return cnt*pow(n,B-1);;
        }
    }
    for(int i=0;i<v.size();i++)
    {
        f=0;
        for(int j=0;j<n;j++)
        {
            if(A[j]==v[i]) f=1;
            if(A[j]<v[i] && A[j]) ans+= pow(n,nv-1-i);
            if(A[j]<v[i] && !A[j] && (nv==1 || i!=0)) ans+= pow(n,nv-1-i);
        }
        if(f==0) break;
    }
    //cout<<"\n";
    return ans;
    
}
