//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  private:
    
    void bfs(int row,int col , vector<vector<char>> grid , vector<vector<int>> & vis){
        vis[row][col]=1;
        queue<pair<int,int>>q;
        q.push({row,col});
        int n = grid.size();
        int m = grid[0].size();
        while(!q.empty()){
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            
            for(int i = -1;i<=1;i++){
                for(int j = -1;j<=1;j++){
                    int nrow = row+i;
                    int ncol = col+j;
                    if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && !vis[nrow][ncol] && grid[nrow][ncol]=='1' ){
                        vis[nrow][ncol]=1;
                        q.push({nrow,ncol});
                    }
                }
            }
        }
    }
      
  public:
    // Function to find the number of islands.
    int numIslands(vector<vector<char>>& grid) {
        int count = 0;
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>>vis (n,vector<int>(m,0));
        for(int row = 0;row<n;row++){
            for(int col = 0;col<m;col++){
                if(!vis[row][col] && grid[row][col]=='1'){
                    count++;
                    bfs(row,col,grid,vis);
                }
            }
        }
        return count;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> grid(n, vector<char>(m, '#'));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        int ans = obj.numIslands(grid);
        cout << ans << '\n';
    }
    return 0;
}
// } Driver Code Ends