class Solution {
public:
    bool canMeasureWater(int x, int y, int target) {
        if(x+y<target) return false;
        int gc=gcd(x,y);
        if(target%gc==0) return true;
        else return false;

    }
};