class Solution {
public:
    int numberOfBeams(vector<string>& bank) 
    {
        int pOnes=0; int res=0;
        
        for(string s: bank){
            int count=0;
            for(char ch: s){ // for a single row
                if(ch=='1'){
                    count++;
                }
            }
           if(count>0){
                res+=(count*pOnes);
                pOnes=count;  // due to this we are able to eliminate usage of extra space
            }
        }
        return res;
    }
};
