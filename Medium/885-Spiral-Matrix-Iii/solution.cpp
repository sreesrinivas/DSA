class Solution {
public:
    vector<vector<int>> spiralMatrixIII(int rows, int cols, int rStart, int cStart) {
        vector<vector<int>> ans;
        int srow=rStart,erow=rStart,scol=cStart,ecol=cStart;
       int  count=0;
        while(count!=rows*cols){
            for(int i=scol; i<=ecol; i++){
                if(srow>=0 && srow<rows && i>=0 && i<cols){
                    ans.push_back({srow,i});
                    count++;
                }
            }
            ecol++;
            for(int i=srow; i<=erow; i++){
                if(i>=0 &&i<rows && ecol<cols && ecol>=0){
                    ans.push_back({i,ecol});
                    count++;
                }
            }
            erow++;

            for(int i=ecol; i>=scol; i--){
                if(erow>=0 &&erow<rows && i>=0 &&i<cols ){
                    ans.push_back({erow,i});
                    count++;
                }
            }
            scol--;

            for(int i=erow; i>=srow; i--){
                if(i>=0 && i<rows &&  scol>=0&& scol<cols){
                    ans.push_back({i,scol});
                    count++;
                }
            }
            srow--;
        }
        return ans;
    }
};
