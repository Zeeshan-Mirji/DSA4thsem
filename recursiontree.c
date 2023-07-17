#include<stdio.h>
void recursion(int n);

int main()
{
    int n;
    scanf("%d",&n);
    recursion(n);

}
void recursion(int n)
{
    int i;
    if(n>0)
    {
       printf("%d",n);
       recursion(n-1);
       recursion(n-1);
    }
}
