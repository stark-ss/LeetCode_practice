class Solution {
public:
    int characterReplacement(string s, int k) {
        int n=s.size();
        if(n==1) return 1;
        unordered_map<char,int> r;
        int c=0,l=0,m=0;
     
        for(int i=0;i<n;i++){
           r[s[i]]++;
           m=max(m,r[s[i]]);
           if((i-l+1)-m>k){
            r[s[l]]--;
            l++;
           }
           c=max(c,i+1-l);

        }
        return c;
    }
};