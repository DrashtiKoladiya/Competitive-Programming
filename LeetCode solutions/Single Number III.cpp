class Solution {
public:
    vector<int> singleNumber(vector<int>& a) {
        
        int total=0,num1=0,num2=0,last_set_bit=0,n=a.size();
        vector<int> ans;
        
        for(int i=0;i<n;i++)
        {
            total^= a[i];
        }
        
        int tmp=total,pos=0;
        while(tmp)
        {
            if(tmp&1)
            {
                break;
            }
            tmp>>= 1;
            pos++;
        }
        last_set_bit = (1<<pos);
        for(int i=0;i<n;i++)
        {
            if(a[i]&(last_set_bit))
            {
                num1^= a[i];
            }
        }
        
        num2 = total^num1;
        
        ans.push_back(num1);
        ans.push_back(num2);
        return ans;
    }
};