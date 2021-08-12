string Solution::solve(string A) {
    queue<char> q;
    vector<int> a(26,0);
    string B="";
    
    int n=A.size();
    for(int i=0;i<n;i++)
    {
        a[A[i]-'a']++;
        q.push(A[i]);
        
        while(!q.empty() && a[q.front()-'a']>1)
        {
            q.pop();
        }
        
        if(!q.empty()) B+= q.front();
        else B+= "#";
    }
    
    return B;
}
