class Solution {
public:
      const int mod=1e9+7;
     long long exponential(long long exp,long long base){
          long long res=1;
        while(exp>0){
            if(exp%2==1)
            res=(res*base)%mod;
            base=(base*base)%mod;
            exp>>=1;
        }
        return res;
     }
    int countGoodNumbers(long long n) {
        long long odd=(n)/2;
        long long even=(n)-odd;
        long long evencom=(exponential(even,5))%mod;
        long long oddcom=(exponential(odd,4))%mod;
        long long res=oddcom*evencom%mod;
        return res;
    }
};