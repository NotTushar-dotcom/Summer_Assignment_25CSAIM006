// Write a program to Write function for Fibonacci.

#include <stdio.h>

int fib(int n)
{
   if (n == 0)
   {
      return 0;
   }
   else if (n == 1)
   {
      return 1;
   }

   return fib(n - 1) + fib(n - 2);
}

int main(void)
{
   int num;

   printf("enter num: ");
   if (scanf("%d", &num) != 1 || num < 0)
   {
      printf("Invalid input.\n");
      return 1;
   }

   printf("fibonacci series: ");
   for (int i = 0; i <= num; i++)
   {
      printf("%d", fib(i));
      if (i < num)
      {
         printf(" ");
      }
   }
   printf("\n");

   return 0;
}