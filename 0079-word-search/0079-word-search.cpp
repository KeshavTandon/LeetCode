class Solution {
public:
    bool findNext(int i,int j,int count,vector<vector<char>>&board,string word){
      if (word.length()==count){
        return true;
      }  
      if (i<0|| i>=board.size() || j<0 || j>=board[0].size()||board[i][j]!=word[count]|| board[i][j] ==' '){
        return false;
      }
      char temp=board[i][j];
      board[i][j]=' ';
      bool ans=findNext(i-1,j,count+1,board,word)||findNext(i+1,j,count+1,board,word)||findNext(i,j-1,count+1,board,word)||findNext(i,j+1,count+1,board,word);
        board[i][j]=temp;
        return ans;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int row=board.size();
        int col=board[0].size();
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(board[i][j]==word[0] && findNext(i,j,0,board,word)){
                    return true;
                }
            }
        }
        return false;
    }
};