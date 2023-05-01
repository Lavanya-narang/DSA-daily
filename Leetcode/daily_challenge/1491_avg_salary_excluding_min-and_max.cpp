class Solution {
public:
    double average(vector<int>& salary) 
    {
        // double sum=0;
        // double mn=INT_MAX,mx=INT_MIN;
        // for(int i=0;i<salary.size();i++)
        // {
        //     sum+=salary[i];
        //     if(salary[i]<mn)
        //     {
        //         mn=salary[i];
        //     }
        //     if(salary[i]>mx)
        //     {
        //         mx=salary[i];
        //     }
        // }
        // sum=sum-mn;
        // sum=sum-mx;
        // double avg=sum/(salary.size()-2);
        // return avg;


        double sum=0,avg=0;
        sort(salary.begin(),salary.end());
         for(int i=1;i<salary.size()-1;i++)
        {
            sum+=salary[i];
        }
        avg=sum/(salary.size()-2);
        return avg;
    }
};
