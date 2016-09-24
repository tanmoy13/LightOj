#include<bits/stdc++.h>

using namespace std;

void towers(int n,char from,char to,char aux)
{
    if(n==1)
    {
        printf("Move disk 1 from peg %c to peg %c\n",from,to);
        return;
    }
    towers(n-1,from,aux,to);
    printf("Move disk %d from peg %c to peg %c\n",n,from,to);
    towers(n-1,aux,to,from);
}

int main()
{
    int n;
    printf("Enter the number of disks : ");
    scanf("%d",&n);
    printf("The Tower of Hanoi involves the moves :\n\n");
    towers(n,'A','C','B');
    return 0;
}
