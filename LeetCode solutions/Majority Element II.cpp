class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n1=INT_MAX,n2=INT_MAX,c1=0,c2=0;
        vector<int> ans;
        
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]==n1) c1++;
            else if(nums[i]==n2) c2++;
            else if(!c1)
            {
                n1=nums[i];
                c1=1;
            }
            else if(!c2)
            {
                n2=nums[i];
                c2=1;
            }
            else
            {
                c1--;
                c2--;
            }
        }
        
        int cnt1=0,cnt2=0;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]==n1) cnt1++;
            if(nums[i]==n2) cnt2++;
        }
        
        if(cnt1 > (nums.size()/3)) ans.push_back(n1);
        if(cnt2 > (nums.size()/3)) ans.push_back(n2);
        
        return ans;
    }
};