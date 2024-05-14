//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

class Matrix {
  public:
    template <class T>
    static void input(vector<vector<T>> &A, int n, int m) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                scanf("%d ", &A[i][j]);
            }
        }
    }

    template <class T>
    static void print(vector<vector<T>> &A) {
        for (int i = 0; i < A.size(); i++) {
            for (int j = 0; j < A[i].size(); j++) {
                cout << A[i][j] << " ";
            }
            cout << endl;
        }
    }
};


// } Driver Code Ends

class Solution {
  public:
    int MinimumEffort(int rows, int columns, vector<vector<int>> &heights) {
        // code here
        queue<pair<int,pair<int,int>>> q;
        vector<vector<int>> vis(rows,vector<int> (columns,INT_MAX));
        q.push({0,{0,0}});
        int x[]={-1,0,1,0};
        int y[]={0,1,0,-1};
        while(q.size()){
            auto temp = q.front();
            q.pop();
            int i=temp.second.first;
            int j=temp.second.second;
            int dis=temp.first;
            for(int k=0;k<4;k++){
                int newi=i+x[k];
                int newj=j+y[k];
                if(newi>=0 and newj>=0 and newi<rows and newj<columns){
                    int newd = max(dis,abs(heights[i][j]-heights[newi][newj]));
                    if(newd<vis[newi][newj]){
                        vis[newi][newj]=newd;
                        q.push({newd,{newi,newj}});
                    }
                }
            }
        }
        return vis[rows-1][columns-1]!=INT_MAX?vis[rows-1][columns-1]:0;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {

        int rows;
        scanf("%d", &rows);

        int columns;
        scanf("%d", &columns);

        vector<vector<int>> heights(rows, vector<int>(columns));
        Matrix::input(heights, rows, columns);

        Solution obj;
        int res = obj.MinimumEffort(rows, columns, heights);

        cout << res << endl;
    }
}

// } Driver Code Ends