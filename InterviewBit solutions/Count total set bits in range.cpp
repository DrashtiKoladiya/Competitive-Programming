int Solution::solve(int A) {
    /*
    if(A==0) return 0;
    long long int ans=0,i=0;
    while(pow(2,i)<=A) i++;
    i--;
    ans = i*(pow(2,i)/2) + (A-pow(2,i)+1) + solve(A-pow(2,i));
    ans = ans%1000000007;
    return ans;
    */
    long long int n=A;
    long long int ans=0;
    while(n)
    {
        long long int i=0;
        while(pow(2,i)<=n) i++;
        i--;
        ans = (ans + (i*(long long int)pow(2,i)/2)%1000000007)%1000000007;
        ans = (ans + (n-(long long int)pow(2,i)+1)%1000000007)%1000000007;
        n-= pow(2,i);
        
    }
    return ans;
}
