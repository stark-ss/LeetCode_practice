class Solution {
public:
    string convertToTitle(int columnNumber) {
        string s="ABCDEFGHIJKLMNOPQRSTUVWXYZ";
        string res="";
        int n=columnNumber;
        while(n>0){
        n=n-1;
        int dig=(n)%26;
        res+=s[dig];
        n=n/26;
        }
        reverse(res.begin(),res.end());
        return res;
    }
};