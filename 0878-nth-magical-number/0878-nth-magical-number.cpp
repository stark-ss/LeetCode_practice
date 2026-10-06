class Solution {
public:
    int nthMagicalNumber(int n, int a, int b) {
        long long lcm=(a/gcd(a,b))*b;
        long long mod=1000000007; 
        long long low=min(a,b);
        long long up=(n%mod)*min(a,b);
        while(low<up){
            long long mid=low+(up-low)/2;
            long long count=(mid/a)+(mid/b)-(mid/lcm);
            if(count<n)
            low=mid+1;
            else
            up=mid;
        }
        return low%mod;

    }
};