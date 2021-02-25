int Solution::singleNumber(const vector<int> &A) {
    int one=0,two=0;
    //one keep track of the number which appers one time in the array
    //two keeps tracks of the number which appers only twices in array
    for(int i=0;i<A.size();i++)
    {
        one = (one ^ A[i]) & (~two);
        two = (two ^ A[i]) & (~one);
    }
    return one;
}
