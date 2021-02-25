class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int m=0;
        for(int i=0;i<32;i++)
        {
            int cnt=0;
            for(int j=0;j<nums.size();j++)
            {
                if((nums[j]>>i) & 1) cnt++;
            }
            
            if(cnt > ((nums.size())/2)) m+= (1<<i);
        }
        
        int cnt=0;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]==m) cnt++;
        }
        
        if(cnt>(nums.size()/2)) return m;
        else return -1;
    }
};