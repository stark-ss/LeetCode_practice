class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int n=s.size();
        int m=p.size();
        array<int,26> tem={0};
        array<int,26> t;
        vector<int> res;
        for(int i=0;i<m;i++)
        tem[p[i]-'a']+=1;
        t=tem;
        int l=0;
        for(int i=0;i<n;i++){

          t[s[i]-'a']-=1;

         if(tem[s[i]-'a']==0){
          l=i+1;
          t=tem;
          continue;
          }

          if(i-l+1>m){
          t[s[l]-'a']+=1;
          l++;  
          }

          if(i-l+1==m){
            bool check=false;
            for(int j=0;j<26;j++){
                if(t[j]!=0){
                check=true; 
                break; 
                    }
            }
            if(!check) res.push_back(l);
          }
        }

     return res;
    }
};