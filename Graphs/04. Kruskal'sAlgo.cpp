#include <bits/stdc++.h>
#define I INT_MAX
using namespace std;

void Union(int s[], int u, int v){
    if(s[u] < s[v]){
        s[u] += s[v];
        s[v] = u;
    }
    else{
        s[v] += s[u];
        s[u] = v;
    }
}

int find(int s[], int u){
    while(s[u] > 0)
        u = s[u];
    return u;
}

void KruskalAlgo(int edges[][9], int set[], int included[], int ans[][7], int n, int e){
    int i=0, u, v, k, min;
    while(i < n-1){
        min = I;
        for(int j=0; j<e; j++){
            if(!included[j] && edges[2][j] < min){
                min = edges[2][j];
                u = edges[0][j];
                v = edges[1][j];
                k = j;
            }
        }
        if(find(set, u) != find(set, v)){
            ans[0][i] = u;
            ans[1][i] = v;
            Union(set, find(set, u), find(set, v));
            i++;
        }
        included[k] = 1;
    }
}

int main() {
    int edges[3][9] = {{1,1,2,2,3,4,4,5,5},
                       {2,6,3,7,4,5,7,6,7},
                       {25,5,12,10,8,16,14,20,18}};
                     
    int set[8] = {-1,-1,-1,-1,-1,-1,-1,-1};
    int included[9] = {0};
    int ans[2][7];
    KruskalAlgo(edges, set, included, ans, 7, 9);
    for(int i=0; i<6; i++){
        cout<<ans[0][i]<<"-->"<<ans[1][i]<<endl;
    }
    return 0;
}
