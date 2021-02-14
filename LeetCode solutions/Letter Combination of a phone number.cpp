class Solution {
public:
    vector<string> go(int src,int n,string s,vector<string> s1)
    {
        vector<string> v;
        if(src>=n)
        {
            v.push_back("");
            return v;
        }
        vector<string> nwe = go(src+1,n,s,s1);
        for(int i=0;i<s1[s[src]-'2'].size();i++)
        {
            for(auto ss:nwe)
            {
                v.push_back(s1[s[src]-'2'][i]+ss);
            }
        }
        
        return v;
        
    }
    vector<string> letterCombinations(string s) {
        vector<string> v;
        if(s.size()==0) return v;
        vector<string> s1(8);
        s1[0]="abc";
        s1[1]="def";
        s1[2]="ghi";
        s1[3]="jkl";
        s1[4]="mno";
        s1[5]="pqrs";
        s1[6]="tuv";
        s1[7]="wxyz";
        return go(0,s.size(),s,s1);
    }
};