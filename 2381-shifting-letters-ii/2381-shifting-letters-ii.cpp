class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        int n=s.size();
        vector<int> pos(n,0);
        for(auto& i:shifts){
            if(i[2]==0){
                pos[i[0]]-=1;
                if(i[1]+1<n)
                pos[i[1]+1]+=1;
            }
            else{
                 pos[i[0]]+=1;
                if(i[1]+1<n)
                pos[i[1]+1]-=1;
            }
        }
       
        for(int i=1;i<n;i++){
            pos[i]+=pos[i-1];
        }
        for(int i=0;i<n;i++){
            int c=s[i]-'a';
            int shift=((c+pos[i])%26+26)%26;
            s[i]='a' +shift;
        }
       
        return s;
    }
};