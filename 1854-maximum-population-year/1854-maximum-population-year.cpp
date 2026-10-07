class Solution {
public:
    int maximumPopulation(vector<vector<int>>& logs) {
        int high=1949;
        int low=2051;
        int n=logs.size();
        for(auto& i: logs){
            high=max(high,i[1]);
            low=min(low,i[0]);
        }
        vector<int> pop(high-low+1,0);
        for(int i=0;i<n;i++){
            pop[logs[i][0]-low]+=1;
            pop[logs[i][1]-low]-=1;
        }
        int year=low;
        int popu=1;
        for(int i=1;i<high-low+1;i++){
            pop[i]+=pop[i-1];
            if(pop[i]>popu){
            popu=pop[i];    
            year=low+i;
            }
        }
        return year;
    }
};