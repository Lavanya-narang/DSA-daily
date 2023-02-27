class Solution {
public:
 Node* constructquad(vector<vector<int>>& grid,int rowstart,int rowend,int colstart,int colend)
 {
     if(rowstart>rowend || colstart>colend)
     {
         return NULL;
     }
     bool isleaf=true;
     int val=grid[rowstart][colstart];
     for(int i=rowstart;i<=rowend;i++)
     {
         for(int j=colstart;j<=colend;j++)
         {
             if(grid[i][j]!=val)
             {
                 isleaf=false;
                 break;
             }
         }
         if(!isleaf)
         {
             break;
         }
     }
     if(isleaf)
     {
         return new Node(val,true);
     }
 
     int rowmid=(rowstart+rowend)/2;
     int colmid=(colstart+colend)/2;
     Node* topleft=constructquad(grid,rowstart,rowmid,colstart,colmid);
     Node* topright=constructquad(grid,rowstart,rowmid,colmid+1,colend);
     Node* bottomleft=constructquad(grid,rowmid+1,rowend,colstart,colmid);
      Node* bottomright=constructquad(grid,rowmid+1,rowend,colmid+1,colend);
      return new Node(false,false,topleft,topright,bottomleft,bottomright);
 }
    Node* construct(vector<vector<int>>& grid) {
        int n=grid.size();
        return constructquad(grid,0,n-1,0,n-1);
    }
};
