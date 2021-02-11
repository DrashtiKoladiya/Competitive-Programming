#define ll long long int
const int mn = 1e5 + 5;
const ll mod = 1e9 + 7;
ll p[mn];

ll power(ll a, ll g) 
{ 
    ll ag = 1;
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
    for(ll i = 2; i < mn; i += 1) 
    {
        if(p[i] == 0) 
        {
            p[i] = 2;
            for(ll j = i+i; j < mn; j += i) 
            {
                if(p[j] == 0) p[j] = 1;
                ll tmp = j;
                ll cnt = 0;
                while(tmp % i == 0) 
                {
                    cnt += 1;
                    tmp /= i;
                }
                p[j] *= (cnt + 1);
            }
        }
    }
    for(ll i = 2; i < mn; i += 1) 
    {
        p[i] = (power(i, p[i]/2)%mod * (p[i]&1 ? (ll)sqrt(i) : 1)%mod)%mod;
    }
}