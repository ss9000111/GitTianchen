#include <stdio.h>

int factorial ( int num )
{
	int i,result=1;
	for (i =1;i<=num;i++)
{
result = result *i;
}
   	 return result; //code modified segment fault corrected
}

int main(void)
{
    int no,ans;
    printf("Enter the number \n");
    scanf( "%d", &no );
    ans = factorial( no );
    printf("The factorial is %d ", ans );
    return 0;
}
