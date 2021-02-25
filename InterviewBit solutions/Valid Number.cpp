int Solution::isNumber(const string s) 
{
    int e=0,e1=0,f1=0;
    int n=s.size(),i=0,j=n-1;
    
    if(s[n-1]=='.') return 0;
    
    while(i<n && s[i]==' ') i++;
    if(i==n) return 0;
    while(j>=i && s[j]==' ') j--;
    
    if(s[0]=='-' && ((s[1]>='0' && s[1]<='9')) || s[1]=='e') i++;
    
    while(i<=j && s[i]!='.')
    {
        if(s[i]>='0' && s[i]<='9') i++;
        else if(i+1<n && s[i]=='e' && s[i+1]!='.' && !e) i++,e=1;
        else if(i+1<n && s[i]=='-' && s[i-1]=='e' && (s[i+1]>='0' && s[i+1]<='9')) i++;
        else return 0;
    }
    i++;
    if(e && i<n) return 0;
    
    while(i<=j)
    {
        if(s[i]>='0' && s[i]<='9') i++;
        else if((i!=(n-1)) && f1 && s[i]=='e' && !e1 && !e) i++,e1=1;
        else if(i+1<n && s[i]=='-' && s[i-1]=='e' && (s[i+1]>='0' && s[i+1]<='9')) i++;
        else return 0;
        if(!f1) f1=1;
    }
    return 1;
    
}
