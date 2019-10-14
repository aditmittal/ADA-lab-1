#include<iostream>
#define ROW 50
#define COL 50
using namespace std;
    int M[ROW][COL],n1,n2;
    bool visited[ROW][COL];

        void getdet(){
        cout<<"enter rows and columns:\n";
        cin>>n1>>n2;
        for (int i=0;i<n1;i++){
            for(int j=0;j<n2;j++){
            visited[i][j]=false;
        }
        }
        cout<<"enter the input matrix of graph\n";
        for(int i=0;i<n1;i++){
            for(int j=0;j<n2;j++){
                cin>>M[i][j];
            }}
       }
       int isSafe(int M[][COL],int row,int col,bool visited[][COL]){
           return ((row>=0)&&(row<n1)&&(col>=0)&&(col<n2)&&(M[row][col]&& !visited[row][col]));
       }
       void DFS(int M[][COL],int row,int col,bool visited[][COL]){
           static int rowNbr[]={-1,-1,-1,0,0,1,1,1};
           static int colNbr[]={-1,0,1,-1,1,-1,0,1};
           visited[row][col]=true;
           for(int k=0;k<8;k++){
            if(isSafe(M,row+rowNbr[k],col+colNbr[k],visited)){
                DFS(M,row+rowNbr[k],col+colNbr[k],visited);
            }
           }
       }
       int countIslands(int M[][COL]){
           int count=0;
           for(int i=0;i<n1;++i){
            for(int j=0;j<n2;++j){
                if(M[i][j] && !visited[i][j]){
                DFS(M,i,j,visited);
                ++count;
                }
            }
           }
           return count;

       }


int main(){

getdet();
int n=countIslands(M);
cout<<n<<" islands are present\n";
return 0;
}

