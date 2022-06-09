class Solution {
public:
    //solve function
    bool solve(vector<vector<char>>& board,int i,int j,int k, string& word){
        //if not safe
        
        if(i<0 || i>=board.size()){
            return false;
        }
        if(j<0 || j>=board[0].size()){
            return false;
        }
        //if the place is already visited
        
        if(board[i][j]=='*'){
            return false;
        }
        //if the word is not matched
        
        if(board[i][j]!=word[k]){
            return false;
        }
        
        //Base Case is when the string is matched
        if(k>=word.length()-1){
            return true;
        }
        char ch=board[i][j];
        
        //mark visited
        board[i][j]='*';
        
        //traverse through left, right, up, down
        bool left=solve(board,i,j-1,k+1,word);
        bool right=solve(board,i,j+1,k+1,word);
        bool up=solve(board,i-1,j,k+1,word);
        bool down=solve(board,i+1,j,k+1,word);
        
        //back-track
        board[i][j]=ch;
        return left || right || up || down;
        
        
    }
    bool exist(vector<vector<char>>& board, string word) {
        int rows = board.size();
        int column = board[0].size();
         
        //We will call from each cell
        for(int i=0;i<rows;i++){
            for(int j=0;j<column;j++){
                if(solve(board,i,j,0,word)){
                    return true;
                }
            }
        }
        return false;
        
    }
};