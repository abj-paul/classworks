#include <bits/stdc++.h>
#define INF 100005
using namespace std;

int matrix[1000][1000], a[1000],store[1000][1000];

void print_mcm(int i, int j)
{

	if(i == j){
		cout << " A" << i << " ";
	}
	else{
		cout << "(";
		print_mcm(i, store[i][j]);
		print_mcm(store[i][j]+1, j);
		cout << ")";
	}
}

int luc(int p[], int i, int j)  //lookup chain
{
    
    if(matrix[i][j] < INF)
        return matrix[i][j];
    
    if(i==j)
        matrix[i][j] = 0;
    
    else
    {
        for(int k=i;k<=j-1;k++)
        {
            int q = luc(p,i,k) + luc(p,k+1,j) + (p[i-1] * p[k] * p[j]);
            if(q < matrix[i][j])
                {
                    matrix[i][j] = q;
                    store[i][j] = k;
                }
        }
    }

return matrix[i][j];
}

void mmc(int p[], int size)  //memoized matrix chain
{
    int n = size - 1;
    for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                matrix[i][j] = INT_MAX;
            }
        }

    printf("Minimum number of operations required : %d \n",luc(p,1,n));
}

int main()
{

    int n;
    
    scanf("%d",&n);

    for(int i=0;i<n;i++)
    scanf("%d",&a[i]);

    
    for(int i=1; i<=n; i++){
        for(int j=i; j<=n; j++){
            matrix[i][j] = INF;
        }
    }

    
    mmc(a,n);
    print_mcm(1,n-1);
    return 0;
}
