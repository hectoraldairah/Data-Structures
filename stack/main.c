#include <stdio.h>
#include <stdlib.h>
#include <stackset.h>
int main()
{
   char* string;
   string = malloc(1000);
   scanf("%s", string);
   isBalanced(string);
    return 0;
}