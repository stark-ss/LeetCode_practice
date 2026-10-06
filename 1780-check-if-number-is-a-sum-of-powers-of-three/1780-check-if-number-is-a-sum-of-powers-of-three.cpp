class Solution {
public:
    bool checkPowersOfThree(int n) {
        while(n>0){
            int d=n%3;
            if(d!=1 && d!=0)
            return false;
            n=n/3;
        }
        return true;
    }
};