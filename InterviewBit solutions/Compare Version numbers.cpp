int Solution::compareVersion(string a, string b) {
  string s1,s2;
  int n,m,i=0,j=0;
  n=a.size(),m=b.size();
  while(i<n && j<m)
  {
    s1="";
    s2="";
    int f1=0,f2=0;
    while(i<n && a[i]!='.')
    {
        if(f1 || a[i]!='0')
        {
            f1=1;
            s1+= a[i];
        }
        i++;
    }
    while(j<m && b[j]!='.')
    {
        if(f2 || b[j]!='0')
        {
            f2=1;
            s2+= b[j];
        }
        j++;
    }
    
    if(s1.size()>s2.size()) return 1;
    else if(s1.size()<s2.size()) return -1;
    if(s1>s2) return 1;
    else if(s1<s2) return -1;
    i++,j++;
  }
  
  while(i<n)
  {
      if(a[i]!='0' && a[i]!='.') return 1;
      i++;
  }
  
  while(j<m)
  {
      if(b[j]!='0' && b[j]!='.') return -1;
      j++;
  }
  
  return 0;
  
}
