class Solution {
public:
    int minReorder(int n, vector<vector<int>>& connections) {
        vector<bool> visited(n, false);//[1,1,1,1,0]
        visited[0] = true;
        int const connection_size = connections.size();
        size_t start = 0;
        int reverse = 0;//1
        int visit = 1;//4
        for(;visit != n;)
        {
            bool start_move = false;
            int move_to = connection_size-1;
            for(int i = start; i < connection_size; ++i)
            {
                int from = connections[i][0];
                int to = connections[i][1];
                if(!visited[from] && visited[to])
                {
                    visited[from] = true;
                    ++visit;
                    if(visit == n)
                        break;
                }
                else if(visited[from] && !visited[to])
                {
                    visited[to] = true;
                    ++visit;
                    ++reverse;
                    if(visit == n)
                        break;
                }
                else if(!visited[from] && !visited[to] && move_to > i)
                {
                    swap(connections[i], connections[move_to--]);
                    if(start_move)
                    {
                        start_move = false;
                        start = i;
                    }
                }
            }
        }
        return reverse;
    }
};
