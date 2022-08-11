#include <iostream>
using namespace std;


const int mr = 100, mc = 100;

int** input(int** mat, int n, int m)
{
  mat = new int* [n];
  for (int i = 0; i < n; i++)
  {
    int* arr = new int[m];
    for (int j = 0; j < m; j++)
    {
      cin >> arr[j];
    }
    mat[i] = arr;
  }
  return mat;
}


int main(int argc, char** argv)
{
  int n, m;
  cin >> n >> m;
  int** mat = input(mat, n, m);

  // write your code here
    int i=0,j=0,count=0,dir=0;
    int total=n*m;
    while(count<total)
    {
        dir=(dir+mat[i][j])%4;
        if(dir==0)
        {
            j++;
            if(j==m)
            {
                j--;
                break;
            }
        }
        else if(dir==1)
        {
            i++;
            if(i==n)
            {
                i--;
                break;
            }
        }
        else if(dir==2)
        {
            j--;
            if(j==-1)
            {
                j++;
                break;
            }
        }
        else
        {
            i--;
            if(i==-1)
            {
                i++;
                break;
            }
        }
    }
    cout<<i<<endl<<j;
  return 0;
}
