class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
       unordered_map<string,vector<string>> list;
        int n=strs.size();
         for(const auto& i : strs){
            string s=i;
            sort(s.begin(),s.end());
            list[s].push_back(i);
         }
         vector<vector<string>> res;
         for(const auto& i:list){
            res.push_back(i.second);
         }
         return res;
         
    }
};