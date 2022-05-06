class Solution {
public:
    bool exist,vis[20][20];
    int row,col;
    vector<int>res;
    vector<vector<int>>Mat;

    bool isValid(int x,int y){
        return x>=0 and x<row and y>=0 and y<col;
    }

    void Right(int idx){
        for(int i=idx; i<(col-idx); i++){
            if(isValid(idx,i)==true){
            	if(vis[idx][i]==false){
	                exist=true;
	                vis[idx][i]=true;
	                res.push_back(Mat[idx][i]);
	            }
            }
        }
    }

    void Down(int idx){
        for(int i=idx+1; i<(row-idx); i++){
            if(isValid(i,col-idx-1)==true){
                if(vis[i][col-idx-1]==false){
	                exist=true;
	                vis[i][col-idx-1]=true;
	                res.push_back(Mat[i][col-idx-1]);
	            }
            }
        }
    }

    void Left(int idx){
        for(int i=col-idx-1; i>=idx; i--){
            if(isValid(row-idx-1,i)==true){
                if(vis[row-idx-1][i]==false){
	                exist=true;
	                vis[row-idx-1][i]=true;
	                res.push_back(Mat[row-idx-1][i]);
	            }
            }
        }
    }

    void Up(int idx){
        for(int i=row-idx-1; i>idx; i--){
        	if(isValid(i,idx)==true){
        		if(vis[i][idx]==false){
	                exist=true;
	                vis[i][idx]=true;
	                res.push_back(Mat[i][idx]);
	            }
        	}
        }
    }
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        Mat.resize(15);
        row=matrix.size();
        col=matrix[0].size();
        for(int i=0; i<row; i++){
        	for(int j=0; j<col; j++){
        		Mat[i].push_back(matrix[i][j]);
        	}
        	for(int j=0; j<5; j++){
        		Mat[i].push_back(0);
        	}
        }
        memset(vis, false, sizeof(vis));
        int i=0;
        while(1){
			exist=false;
			Right(i);
			Down(i);
			Left(i);
			Up(i);
			if(exist==false){
				break;
			}
			i++;
		}
        return res;
    }
};
