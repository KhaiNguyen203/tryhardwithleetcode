class Solution {
public:
    int dfs(int u, int v, int track){
        for(int i=0; i<u; i++){
            for(int j=0; j<v; j++){
                if(a[i][j] == word[track]){
                    track++;
                    if(a[i-1][j] == word[track]){
                        dfs(i-1, j, track);
                    }
                    else if(a[i][j+1] == word[track]){
                        dfs(i, j+1, track);
                    }
                    else if(a[i+1][j] == word[track]){
                        dfs(i+1, j track);
                    }
                    else if(a[i][j-1] == word[track]){
                        dfs(i, j-1, track);
                    }
                    else{
                        track--;
                        return 0;
                    }
                }
            }
        }
        if(track == word.size()){
            return 1;
        }
    }
    bool exist(vector<vector<char>>& board, string word) {
        
    }
};