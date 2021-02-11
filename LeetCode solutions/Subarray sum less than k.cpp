class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        map<int,int> m;
        m[0]=1;
        long long cnt=0,sum=0,n=nums.size();
        for(int i=0;i<n;i++)
        {
            sum+= nums[i];

            if(m.find(sum-k)!=m.end())
            {
                cnt+= m[sum-k];
            }
            m[sum]++;
        }
        
        return cnt;
    }
};