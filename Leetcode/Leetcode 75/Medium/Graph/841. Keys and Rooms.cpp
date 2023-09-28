class Solution {
public:

    void DFS(vector<vector<int>>& rooms, int sc, vector<bool> &visited){

        visited[sc] = true;

        for(int x: rooms[sc]){

            if(visited[x] == false){
                DFS(rooms,x,visited);
            }
        }
    }

    bool canVisitAllRooms(vector<vector<int>>& rooms) {

        vector<bool> visited(rooms.size(),false);

        DFS(rooms,0,visited);

        for(int i=0; i<visited.size(); i++){

            if(visited[i] == false){
                return false;
            }
        }

        return true;
        
    }
};
