class Solution {
public:
    int countPrimes(int n) {
        auto res=count(n);
        return res;
    }
    long count(int n){
        if(n<=2) return 0;
        long c=0;
        vector<bool> p(n,true);
        p[0]=p[1]=false;
        for(int i=2;i*i<n;i++){
            if(p[i]){
                for(int j=i*i;j<n;j+=i)
                p[j]=false;
            }
        }
        for(int i=0;i<n;i++){
            if(p[i])
            c++;
        }
      return c;
    }
};