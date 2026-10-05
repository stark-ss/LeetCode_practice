class Solution {
public:
    bool isAnagram(string s, string t) {
        int n=s.size();
        int m=t.size();
        if(n!=m) return false;
        vector<int> s1(26,0);
        vector<int> t1(26,0);
        for(int i=0;i<n;i++){
            s1[s[i]-'a']+=1;
            t1[t[i]-'a']+=1;
        }
        for(int i=0;i<26;i++){
            if(s1[i]!=t1[i])
            return false;
        }
        return true;
    }
};