class Solution {
public:
    int row,col,vis[55][55];
    vector<int>dx={1,-1,0,0};
	vector<int>dy={0,0,1,-1};
    bool isValid(int x, int y){
		return x>=0 and x<row and y>=0 and y<col;
	}
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int res=0,cnt=0;
        memset(vis,0,sizeof(vis));
        row=grid.size(),col=grid[0].size();
        for(int i=0; i<row; i++){
            for(int j=0; j<col; j++){
                if(grid[i][j]==1 and vis[i][j]==0){
                    vis[i][j]=1; cnt=1;
                    queue<pair<int,int>>Q;
                    Q.push({i,j});
                    while(!Q.empty()){
                        pair<int,int>u=Q.front();
                        Q.pop();
                        for(int k=0; k<4; k++){
                            int a=u.first+dx[k],b=u.second+dy[k];
                            if(isValid(a,b)==true){
                                if(vis[a][b]==0 and grid[a][b]==1){
                                    cnt++;
                                    vis[a][b]=1;
                                    Q.push({a,b});
                                }
                            }
                        }
                    }
                    res=max(res,cnt);
                }
            }
        }
        return res;
    }
};