class Solution {
public:
 int find(int c,vector<int>& alpha){
    if(alpha[c]==c) return c;
    return alpha[c]=find(alpha[c],alpha);
 }

    bool equationsPossible(vector<string>& equations) {
        int n=equations.size();
        vector<int> alpha(26);
        for(int i=0;i<26;i++){
            alpha[i]=i;
        }
        for(auto& i:equations){
          if(i[1]=='='){
            int a=find(i[0]-'a',alpha);
            int b=find(i[3]-'a',alpha);
            alpha[b]=a;
          }
        }
        for(auto& i:equations){
            if(i[1]=='!'){
            int a=find(i[0]-'a',alpha);
            int b=find(i[3]-'a',alpha);
            if(a==b) return false; 
            }
        }
        return true;
    }
};