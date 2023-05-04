class Solution 
{
public:
    void ban(string senate,vector<bool>&banned,char toban,int start)
    {
      while(true)
      {
        if(senate[start]==toban && !banned[start])
        {
          banned[start]=true;
          break;
        }
        start=(start+1)%senate.size();
      }
    }
    string predictPartyVictory(string senate) 
    {
        int n=senate.size();
        vector<bool>banned(n,false);//to check if the senate[i] is already banned or not
        int rc=0,dc=0;
        for(int i=0;i<n;i++)
        {
          if(senate[i]=='R')
          {
            rc++;
          }
          else
          {
            dc++;
          }
        }
        int i=0;
        while(rc>0 && dc>0)
        {
          if(!banned[i])
          {
            if(senate[i]=='R')
            {
              ban(senate,banned,'D',(i+1)%n);
              dc--;
            }
            else
            {
              ban(senate,banned,'R',(i+1)%n);
              rc--;
            }
          }
          i=(i+1)%n;
        }
        return rc==0?"Dire":"Radiant";
    }
};

//o(n) solution
class Solution 
{
public:
    string predictPartyVictory(string senate) 
    {
        int n=senate.size();
        queue<int>rq,dq;
        for(int i=0;i<senate.size();i++)
        {
            senate[i]=='R'?rq.push(i):dq.push(i);
        }
        int a,b;
        while(!rq.empty() && !dq.empty())
        {
            a=rq.front(),b=dq.front();
            rq.pop();
            dq.pop();
            if(a<b)
            {
                rq.push(a+n);
            }
            else
            {
                dq.push(b+n);
            }
        }
        if(rq.size()>dq.size())
        {
            return "Radiant";
        }
        else
        {
            return "Dire";
        }
    }
};
