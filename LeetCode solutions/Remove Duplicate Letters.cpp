class Solution {
public:
    string removeDuplicateLetters(string s) {
        
        stack<int> s1;
        vector<int> fre(26,0),exits(26,0);
        
        for(int i=0;i<s.size();i++) fre[s[i]-'a']++;
        
        for(int i=0;i<s.size();i++)
        {
            fre[s[i]-'a']--;
            if(exits[s[i]-'a']) continue;
            while(!s1.empty() && s[s1.top()]>s[i] && fre[s[s1.top()]-'a']>=1)
            {
                exits[s[s1.top()]-'a']=0;
                s1.pop();
            }
            
            exits[s[i]-'a']=1;
            s1.push(i);
        }
        
        string ans="";
        
        while(!s1.empty())
        {
            ans=s[s1.top()]+ans;
            s1.pop();
        }
        
        return ans;
        
    }
};