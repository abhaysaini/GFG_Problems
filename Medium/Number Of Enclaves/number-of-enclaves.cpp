//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
private:
    void dfs(vector<vector<int>> &vis,vector<vector<int>> grid , int row, int col){
        
        
        int delRow [] = {-1,0,1,0};
        int delCol [] = {0,1,0,-1};
        
        int n = grid.size();
        int m = grid[0].size();
        
        vis[row][col]=1;
        
        for(int i =0;i<4;i++){
            int nrow = row + delRow[i];
            int ncol = col + delCol[i];
            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && !vis[nrow][ncol] && grid[nrow][ncol] == 1){
                dfs(vis,grid,nrow,ncol);
            }
        }
        
    }
  public:
    int numberOfEnclaves(vector<vector<int>> &grid) {
        
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>>vis(n,vector<int> (m,0));
        queue<pair<int,int>> q;
        for(int i =0;i<n;i++){
            for(int j =0;j<m;j++){
                if( i==0 || j==0 || i == n-1 || j == m-1 ){
                    if(grid[i][j] == 1){
                        q.push({i,j});
                    }
                }
            }
        }
        
        int delRow [] = {-1,0,1,0};
        int delCol [] = {0,1,0,-1};
        
        while(!q.empty()){
            
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            vis[row][col]=1;
            
            for(int i =0;i<4;i++){
                int nrow = row + delRow[i];
                int ncol = col + delCol[i];
                if(nrow>-0 && nrow<n && ncol>-0 && ncol <m && !vis[nrow][ncol]&&grid[nrow][ncol]==1){
                    q.push({nrow,ncol});
                }
            }
            
        }
        
    //     vector<vector<int>> vis(n,vector<int>(m,0));
        
    //     for(int i =0;i<m;i++){
    //       if(!vis[0][i] && grid[0][i]==1){
    //           dfs(vis,grid,0,i);
    //       }
           
    //       if(!vis[n-1][i] && grid[n-1][i]==1){
    //           dfs(vis,grid,n-1,i);
    //       }
    //   }
       
    //   for(int i =0;i<n;i++){
    //       if(!vis[i][0] && grid[i][0]==1){
    //           dfs(vis,grid,i,0);
    //       }
           
    //       if(!vis[i][m-1] && grid[i][m-1]==1){
    //           dfs(vis,grid,i,m-1);
    //       }
    //   }
        
        int count = 0;
        for(int i =0;i<n;i++){
            for(int j =0;j<m;j++){
                if(!vis[i][j] && grid[i][j]==1){
                    count++;
                }
            }
        }
        
        return count;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        cout << obj.numberOfEnclaves(grid) << endl;
    }
}
// } Driver Code Ends