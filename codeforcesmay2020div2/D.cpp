int dfs(map<int,vector<int>> edge, int start, vector<int> &visited){
    
    if(visited[start] == 1)
        return 1;
    else{
        int ans = 0;
        visited[start] = 1;
        vector<int> neigh = edge[start];
        for(int i = 0; i < neigh.size(); i++){
            ans |= dfs(edge, neigh[i], visited);
            if(ans)
                return 1;
        }
        visited[start] = 0;
    }
    return ans;
}
int Solution::solve(int A, vector<vector<int> > &B) {
    map<int,vector<int>> edge;
    for(int i = 0; i < B.size(); i++)
    {
        edge[B[i][0]].push_back(B[i][1]);
    }
    int ans = 0;
    for(int i = 1; i <= A; i++){
        vector<int> visited(A+1, 0);
        if(dfs(edge, i, &visited))
            return 1;
    }
    return 0;
}
