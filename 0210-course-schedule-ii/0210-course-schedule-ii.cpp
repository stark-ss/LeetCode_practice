class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        int n=prerequisites.size();
        vector<vector<int>> node(numCourses);
        queue<int> q;
      
        vector<int> pre(numCourses);
        for(auto& i:prerequisites){
            pre[i[0]]++;  
            node[i[1]].push_back(i[0]);
        } 
        
        for(int i=0;i<numCourses;i++){
            if(pre[i]==0){
            q.push(i);
           
            }
        }
        vector<int> res;
        while(!q.empty()){
            int start=q.front();
            q.pop();
            res.push_back(start);
            for(auto& i:node[start]){
                pre[i]--;
               if(pre[i]==0) q.push(i);
            }
        }
        if(res.size()==numCourses)
        return res;
        else return {};
       
    }
};