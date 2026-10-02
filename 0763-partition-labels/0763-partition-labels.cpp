class Solution {
public:
    vector<int> partitionLabels(string s) {
        int n=s.size();
        vector<int>res;
        unordered_map<char,pair<int,int>> list;
        int l=0,r=0;
        for(int i=0;i<n;i++){
            if(list.find(s[i])==list.end())
            list[s[i]]={i,i};
            else
            list[s[i]].second=i;
        }
        for(int i=0;i<n;i++){
          r=max(r,list[s[i]].second);
          if(r==i){
           res.push_back(i-l+1);
           l=i+1;
          }
        }
        return res;
    }
};