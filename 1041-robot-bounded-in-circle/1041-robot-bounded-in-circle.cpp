class Solution {
public:
    bool isRobotBounded(string instructions) {
        int n=instructions.size();
        int a=0,b=0;
        int x=0,y=1;
        int i=0;
        while(i<n){
           if(instructions[i]=='G'){
            a+=x;
            b+=y;
           }
           else if(instructions[i]=='L'){

            int t=x;
            x=-y;
            y=t;
  
           }
           else if(instructions[i]=='R'){
         
            int t=x;
            x=y;
            y=-t;
           }
          i++;
        }
        if((a==0 && b==0) ||(x!=0 || y!=1))
        return true;
        else return false;
    }
};