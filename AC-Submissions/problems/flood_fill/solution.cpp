class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
    	vector<int>dx={1,-1,0,0};
		vector<int>dy={0,0,1,-1};
        int row=image.size(),col=image[0].size();
        bool vis[row][col];
        memset(vis,0,sizeof(vis));
        queue<pair<int,int>>Q;
        Q.push({sr,sc});
        vis[sr][sc]=1;
        int prevColor=image[sr][sc];
        image[sr][sc]=newColor;
        while(!Q.empty()){
        	pair<int,int>u=Q.front();
        	Q.pop();
        	for(int i=0; i<4; i++){
        		int x=u.first+dx[i],y=u.second+dy[i];
        		if(x>=0 and x<row and y>=0 and y<col){
        			if(image[x][y]==prevColor and vis[x][y]==0){
                        vis[x][y]=1;
        				image[x][y]=newColor;
        				Q.push({x,y});
        			}
        		}
        	}
        }
        return image;
    }
};