class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& a) {
        vector<vector<int>> v;
        int n=a.size();
        sort(a.begin(),a.end());
        for(int i=0;i<n-2;i++)
        {
            if(i==0 || (a[i]!=a[i-1]))
            {
                int l=i+1,r=n-1,need=-a[i];
                while(l<r)
                {
                    if(a[l]+a[r]==need)
                    {
                        vector<int> tmp;
                        tmp.push_back(a[i]);
                        tmp.push_back(a[l]);
                        tmp.push_back(a[r]);
                        v.push_back(tmp);
                        while(l<r && a[l]==a[l+1]) l++;
                        while(r>l && a[r]==a[r-1]) r--;
                        l++;
                        r--;
                    }
                    else if(a[l]+a[r]>need) r--;
                    else l++;
                }
                
            }
        }
        return v;
    }
};