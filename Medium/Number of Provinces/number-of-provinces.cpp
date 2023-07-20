//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
  
    void dfs(vector<int> adjL[] ,int vis[],int node){
        vis[node]=1;
        for(auto it: adjL[node]){
            if(!vis[it]){
                dfs(adjL,vis,it);
            }
        }
    }
  
    int numProvinces(vector<vector<int>> adj, int V) {
        vector<int> adjL[V];
        for(int i =0;i<V;i++){
            for(int j = 0;j<V;j++){
                if(adj[i][j]==1 && i!=j){
                    adjL[i].push_back(j);
                    adjL[j].push_back(i);
                }
            }
        }
        
        int count = 0;
        int vis[V] = {0};
        for(int i =0;i<V;i++){
            if(!vis[i]){
                count++;
                dfs(adjL,vis,i);
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
        int V,x;
        cin>>V;
        
        vector<vector<int>> adj;
        
        for(int i=0; i<V; i++)
        {
            vector<int> temp;
            for(int j=0; j<V; j++)
            {
                cin>>x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }
        

        Solution ob;
        cout << ob.numProvinces(adj,V) << endl;
    }
    return 0;
}
// } Driver Code Ends