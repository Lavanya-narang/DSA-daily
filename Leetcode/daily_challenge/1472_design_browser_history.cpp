class BrowserHistory {
public:
stack<string>curr;
stack<string>forw;
    BrowserHistory(string homepage) 
    {
        curr.push(homepage);
    }
    
    void visit(string url) 
    {
        while(!forw.empty())
        {
            forw.pop();
        }
        curr.push(url);
    }
    
    string back(int steps) 
    {
        string res="";
        while(steps-- && curr.size()>1)
        {
            forw.push(curr.top());
            curr.pop();
        }
        res=curr.top();
        return res;
    }
    
    string forward(int steps) 
    {
        string res="";
        while(steps-- && !forw.empty())
        {
            curr.push(forw.top());
            forw.pop();
        }
        res=curr.top();
        return res;
    }
};
