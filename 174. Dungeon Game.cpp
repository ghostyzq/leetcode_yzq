class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        //const vector<vector<int>>& sb {{ 0,0}};
        const int length = dungeon.size();
        const int width = dungeon[0].size();
        vector<vector<int>> hp(length+1,vector<int>(width+1,INT_MAX));
        hp[length][width-1] = hp[length-1][width] = 1;
        for (int x=length-1;x>=0;--x)
            for (int y=width-1;y>=0;--y)
                hp[x][y] = max(1,min(hp[x+1][y],hp[x][y+1])-dungeon[x][y]);
        return hp[0][0];


    }
};