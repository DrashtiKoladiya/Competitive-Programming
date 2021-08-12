class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        map<string,int> m;
        map<int,vector<string>> m1;
        
        //comparator lambda function
        auto comp = [](pair<int,string> a, pair<int,string> b) {
            if(a.first != b.first)
            {
                return a.first > b.first;
            }
            
            return a.second < b.second;
        };
        
        priority_queue<pair<int,string>,vector<pair<int,string>>,decltype(comp)> q(comp);
        vector<string> ans;
        
        for(auto &word:words)
        {
            m[word]++;
        }
        
        int k1=k;
        auto it=m.begin();
        for(;k1-- && it!=m.end();it++)
        {
            q.push({it->second,it->first});
        }
        
        for( ;it!=m.end();it++)
        {
            if(q.top().first < it->second)
            {
                q.pop();
                q.push({it->second,it->first});
            }
            else if(q.top().first == it->second && q.top().second>it->first)
            {
                q.pop();
                q.push({it->second,it->first});
            }
        }
        
    
        while(!q.empty())
        {
            ans.push_back(q.top().second);
            q.pop();
        }
        reverse(ans.begin(),ans.end());
        
        return ans;
    }
};