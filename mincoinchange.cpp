#include<iostream>
using namespace std;
#define INF 9999

int minCoin(int Val[],int n,int total)
{
    int change[total+1];
    change[0] = 0;
   int i,j;
   for(j=1;j<=total;j++) {
      int min = INF;
    
      for(i=0;i<n;i++) {
         if(j>=Val[i] && (change[j-Val[i]]+1) < min)
            min = change[j-Val[i]]+1;
      }
      
      change[j] = min;
   }
   return change[total];
}



int main()
{
    int total;
    cout<<"Enter the total amount to be given : ";
    cin>>total;

    int Val[]={1,2,5};
    int min = minCoin(Val,3,total);
    cout<<"Min Coins : "<<min<<endl;
    return 0;
}