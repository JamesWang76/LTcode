#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;
struct Sqr{
    int x;
    int y;
    int level=1;
    Sqr(int x, int y, int level): x(x), y(y), level(level){}
};

/**
 * Find the max square size (Largest Square) in a rectangle which width and height are not necessarily the same.
 * 
 * - Dp-like way
 *      - Start the step from the lower-right to the upper-left
 *      - 1. Check whether there exists some xy-coordinate in the queue
 *          - If it exists, using findNewSquare() to check whether it's possible to become bigger than itself.
 *      - 2. Push the point into queue if it equals to 1
 * 
 * ====== Too slow, the following is the better dp way =====
 * 
 * - Map the left rectange to the right
 *      - Start from the upper left corner to the lower right
 *      - Increment itself if (upper left)==(the up)==(the left)
 *      
 *      1,1,1,1      [1], 1 , 1 , 1
 *      1,1,1,0  =>   1 ,[2], 2 , 0
 *      1,1,1,0       1 , 2 ,[3], 0
 * 
 * - Very similar to the Longers Common Substring (LCS) algorithm
 *      - LCS finds the substring which consists of the SEPARATE char inside the string 
 *      - However, LS (Largest square) could be replaced to find the maximun CONTINUOUS substring 
 */  





int maximalSquare(vector<vector<char>>& matrix);
void printArr(vector<vector<char>>& matrix);
bool findNewSquare(Sqr& sqr, vector<vector<char>>& matrix);

int main(){
    vector<vector<char>> matrix;
    vector<char> x;
    int R=2, C=3;
    char data[2][3] = {{'1', '1', '1'}, {'1', '1', '1'}};
    for (int i = 0; i < R; i++) {
        for(int j=0;j<C;j++){
            x.push_back(data[i][j]);
        }
        matrix.push_back(x);
        x.clear();
    }
    cout<<maximalSquare(matrix);
}

void printArr(vector<vector<char>>& matrix){
    for(int i=0;i<matrix.size();i++){
        for(int j=0;j<matrix[i].size();j++){
            cout<<matrix[i][j]<<" ";
        }cout<<"\n";
    }
}

bool findNewSquare(Sqr& sqr, vector<vector<char>>& matrix){
    if(sqr.x-1 < 0 || sqr.y-1 < 0)return false;
    else{
        bool checkAllIsOne = true;
        for(int c=0;c<sqr.level+1;c++){
            if(matrix[sqr.y-1][sqr.x-1+c] != '1'){
                checkAllIsOne = false;
                break;
            }
        }
        if(checkAllIsOne){
            for(int r=0;r<sqr.level+1;r++){
                if(matrix[sqr.y-1+r][sqr.x-1] != '1'){
                    checkAllIsOne = false;
                    break;
                }
            }
        }
        return checkAllIsOne;
    }
}


int maximalSquare(vector<vector<char>>& matrix) {
    int i, j, MaxSize=0, MaxSquareSize;
    vector<Sqr> squareXY;
    MaxSquareSize = min(matrix.size(), matrix[0].size());
    for(i=matrix.size()-1;i>=0;i--){
        for(j=matrix[i].size()-1;j>=0;j--){
            int currCheckedSize = squareXY.size();
            while(currCheckedSize>0){
                Sqr sqrToBeChecked = squareXY[0];
                if(findNewSquare(sqrToBeChecked, matrix)){
                    Sqr sqrHasBeenChecked = Sqr(sqrToBeChecked.x-1, sqrToBeChecked.y-1, sqrToBeChecked.level+1);
                    MaxSize = (sqrHasBeenChecked.level > MaxSize)? sqrHasBeenChecked.level:MaxSize;
                    squareXY.push_back(sqrHasBeenChecked);
                }
                if(MaxSize == MaxSquareSize){return MaxSize*MaxSize;};
                squareXY.erase(squareXY.begin());
                currCheckedSize--;
            }
            if(matrix[i][j] == '1'){
                Sqr newPoint = Sqr(j, i, 1);
                MaxSize = (1 > MaxSize)? 1:MaxSize;
                squareXY.push_back(newPoint);
            }
        }
    }
    // cout<<MaxSize<<"---\n";
    return MaxSize*MaxSize;
}