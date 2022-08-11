#include <iostream>
using namespace std;

const int mr = 100, mc = 100;
void inputBound(int (&mat)[mr][mc], int n, int m)
{

  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      cin >> mat[i][j];
    }
  }
}

int main(int argc, char** argv)
{


  int mat[mr][mc] = {0};
  int n, m;
  cin >> n >> m;

  inputBound(mat, n, m);

  // write your code here
    int count=0;
    int toe=(n*m);
    int minr=0,minc=0,maxr=n-1,maxc=m-1;
    while(count<toe)
    {
        for(int i=minr,j=minc;i<=maxr && count<toe;i++)
        {
            cout<<mat[i][minc]<<endl;
            count++;
        }
        minc++;
        for(int i=maxr,j=minc;j<=maxc && count<toe;j++)
        {
            cout<<mat[maxr][j]<<endl;
            count++;
        }
        maxr--;
        for(int i=maxr,j=maxc;i>=minr && count<toe;i--)
        {
            cout<<mat[i][maxc]<<endl;
            count++;
        }
        maxc--;
        for(int i=minr,j=maxc;j>=minc && count<toe;j--)
        {
            cout<<mat[minr][j]<<endl;
            count++;
        }
        minr++;
    }
  return 0;
}
