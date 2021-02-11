#define int long long int
const int mn = 1e5 + 5;
const int mod = 1e9 + 7;
int p[mn];

int power(int a, int g) 
{ 
    int ag = 1;
    while(g)
    {
        if(g&1) ag = (ag%mod * a%mod)%mod;
        a = (a%mod * a%mod)%mod; 
        g >>= 1;
    } 
    return ag;
}

void product_of_divisors() {
    p[0] = 0; 
    p[1] = 1;
    
    //given t test cases if once the function is called then there is no need of
    //again precomuting product of divisors for each element
    if(p[2]!=0) return;
    for(int i = 2; i < mn; i += 1) 
    {
        if(p[i] == 0) 
        {
            p[i] = 2;
            for(int j = i+i; j < mn; j += i) 
            {
                if(p[j] == 0) p[j] = 1;
                int tmp = j;
                int cnt = 0;
                while(tmp % i == 0) 
                {
                    cnt += 1;
                    tmp /= i;
                }
                p[j] *= (cnt + 1);
            }
        }
    }
    for(int i = 2; i < mn; i += 1) 
    {
        p[i] = (power(i, p[i]/2)%mod * (p[i]&1 ? (int)sqrt(i) : 1)%mod)%mod;
    }
}
vector<int32_t> Solution::solve(vector<int32_t> &a, vector<int32_t> &B) {
     
    //for precomuting product of divisors for each elment 
    product_of_divisors();
    
    int n=a.size();
    vector<int> left(n,1),right(n,1),total(n),prefix(n);
    vector<int32_t> ans(B.size());
    
    //Range from i to it's left where a[i] is the greatest
    for(int i=1;i<n;i++)
    {
        int last=i-1;
        while(last>=0 && a[i]>a[last])
        {
            left[i]+= left[last];
            last-= left[last];
        }
    }
    
    //Range from i to it's right where a[i] is the greatest
    for(int i=n-2;i>=0;i--)
    {
        int last=i+1;
        while(last<n && a[i]>=a[last])
        {
            right[i]+= right[last];
            last+= right[last];
        }
    }
    
    //total number of subarrays in which a[i] is the greates is denoted by total[i].
    for(int i=0;i<n;i++) total[i]=left[i]*right[i];
    
    //storing the frequency of each number with it's product of divisors and sorting into desending order
    vector<pair<int32_t,int>> fre(n);
    for(int i=0;i<n;i++)
    {
        fre[i] = {p[a[i]],total[i]};
    }
    sort(fre.begin(),fre.end(),greater<pair<int,int>>());
    
    //prefix sum for finding kth element
    prefix[0]=fre[0].second;
    for(int i=1;i<n;i++)
    {
        prefix[i]=prefix[i-1]+fre[i].second;
    }
    
    //finding kth element for each query using binary search
    for(int i=0;i<B.size();i++)
    {
        int idx=lower_bound(prefix.begin(),prefix.end(),B[i])-prefix.begin();
        ans[i]=fre[idx].first;
    }
    return ans;
    
}
