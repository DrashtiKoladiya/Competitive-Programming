class Solution {
public:
    map<string,int> m0,m1;
    
    int makeZero(string s1)
    {  
        int ss=s1.size(),ans=0;
        if(ss<=0) return 0;
        if(ss==1)
        {
            if(s1[0]=='0') return 0;
            else return 1;
        }
        
        if(m0.find(s1)!=m0.end())
        {
            return m0[s1];
        }
        
        if(s1[0]=='0')
        {
            ans = makeZero(s1.substr(1,ss-1));
        }
        else
        {
            std::string t(ss-2,'0');
            t="1"+t;
            ans = makePattern(s1.substr(1,ss-1)) + 1 + makeZero(t);
        }
        
        
        return m0[s1]=ans;
    }
    int makePattern(string s1)
    {
        int ss=s1.size(),ans=0;
        if(ss<=0) return 0;
        if(ss==1)
        {
            if(s1[0]=='1') return 0;
            else return 1;
        }
        
        if(m1.find(s1)!=m1.end())
        {
            return m1[s1];
        }
        
        if(s1[0]=='1')
        {
            ans = makeZero(s1.substr(1,ss-1));
        }
        else
        {
            std::string t(ss-2,'0');
            t="1"+t;
            ans = makePattern(s1.substr(1,ss-1)) + 1 + makeZero(t);
        }
        
        return m1[s1]=ans;
    }
    
    int minimumOneBitOperations(int n) 
    {
        string s="";
        int x=n,ss,cnt=0;
        while(x)
        {
            cnt++;
            if(x&1)
            {
                s="1"+s;
            }
            else
            {
                s="0"+s;
            }
            x>>= 1;
        }
        ss=s.size();
    
        int ans=makeZero(s);
        return ans;
    }
};