// O(NLogN) Approach


class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        
        int n=matrix.size();
        int l,r,ans=matrix[n-1][n-1];
        
        l=matrix[0][0], r=matrix[n-1][n-1];
        while(l<=r)
        {
            int mid = l + (r-l)/2;
            int count=0;
            
            for(int i=0;i<n;i++)
            {
                count+= upper_bound(matrix[i].begin(),matrix[i].end(),mid) - matrix[i].begin();
            }
            
            if(count < k)
            {
                l=mid+1;
            }
            else
            {
                ans=mid;
                r = mid-1;
            }
        }
        
        return ans;
        
    }
};

// O(KLogN) Approach


class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        
        int n=matrix.size();
        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>> q;
        
        for(int i=0;i<n;i++)
        {
            q.push({matrix[i][0],i,0});
        }
        
        while(--k)
        {
            vector<int> tmp=q.top();
            q.pop();
            
            if(tmp[2]+1<n)
            {
                q.push({matrix[tmp[1]][tmp[2]+1],tmp[1],tmp[2]+1});
            }
        }
        
        int ans=q.top()[0];
        return ans;
        
    }
};