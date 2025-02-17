#include <bits/stdc++.h>
using namespace std;

void BFS(int G[][7], int start, int n){      // Time - O(n^2) | Space - O(n)
    queue<int> q;
    bool visited[n] = {0};
    q.push(start);
    visited[start] = true;
    cout<<start<<" ";
    
    while(!q.empty()){
        int i = q.front();
        q.pop();
        
        for(int j=1; j<n; j++){
            if(G[i][j] == 1 && visited[j] == 0){
                cout<<j<<" ";
                visited[j] = true;
                q.push(j);
            }
        }
    }
}

int main() {
    int G[7][7] = {{0,0,0,0,0,0,0},
                   {0,0,1,1,0,0,0},
                   {0,1,0,0,1,0,0},
                   {0,1,0,0,1,0,0},
                   {0,0,1,1,0,1,1},
                   {0,0,0,0,1,0,0},
                   {0,0,0,0,1,0,0}};
    BFS(G, 4, 7);
    return 0;
}
