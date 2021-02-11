class Solution {
public:
    int search(vector<int>& a, int b) {
        
        int l,r,n,idx=-1;
        n=a.size();
        l=0,r=n-1;
        while(l<=r)
        {
            int mid=l+(r-l)/2;
            if(a[mid]==b) return mid;
            else if(a[l]>a[mid])
            {
                if(b>=a[mid+1] && b<=a[r])
                {
                    l=mid+1;
                }
                else
                {
                    r=mid-1;
                }
            }
            else
            {
                if(b>=a[l] && b<a[mid])
                {
                    r=mid-1;
                }
                else
                {
                    l=mid+1;
                }
            }
        }
        return -1;
    }
};