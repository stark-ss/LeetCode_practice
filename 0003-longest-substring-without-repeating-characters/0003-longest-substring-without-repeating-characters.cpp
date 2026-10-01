class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int> res;
        int n=s.size();
        if(!n) return 0;
        else if(n==1) return 1;
        int c=1,l=0;
        res[s[0]]=0;
        for(int i=1;i<n;i++){
         if(res.find(s[i])!=res.end() && res[s[i]]>=l){
          l = res[s[i]] + 1;
         }
          res[s[i]]=i;
          int cc=i-l+1;
          c=max(c,cc);
        }
        return c;
    }
};