class Solution {
public:
    double myPow(double x, int n) {
        long long exp=n;
        double base=x;
        if(exp<0){
            exp=-(exp);
        }
        double res=1;
        while(exp>0){
            if(exp%2==1) res=res*base;
            base=base*base;
            exp>>=1;
        }
        if(n<0) return 1.0/res;
        return res;
    }
};