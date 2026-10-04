class Solution {
public:
    string removeKdigits(string num, int k) {
        int n=num.size();
        string res="";
        for(int i=0;i<n;i++){
            int cur=num[i];
            if(!res.empty() && k>0 && cur<res.back()){
                while(!res.empty() && k>0 && cur<res.back()){
                   k--;
                   res.pop_back();
                }
            }
            if(res.empty() && cur=='0')
            continue;
            res.push_back(num[i]);
        }
        while(!res.empty() && k>0){
            res.pop_back();
            k--;
        }
      return (res.empty())?"0":res;
    }
};