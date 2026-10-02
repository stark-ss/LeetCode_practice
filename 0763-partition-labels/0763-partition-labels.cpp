class Solution {
public:
    vector<int> partitionLabels(string s) {
        int n=s.size();
        vector<int>res;
       int list[26]={0};
        int l=0,r=0;
        for(int i=0;i<n;i++){
           list[s[i]-'a']=i;
        }
        for(int i=0;i<n;i++){
          r=max(r,list[s[i]-'a']);
          if(r==i){
           res.push_back(i-l+1);
           l=i+1;
          }
        }
        return res;
    }
};