#include <stdio.h>
#include <stdarg.h>

double average(double v1 , double v2, ...);      /* Function prototype */

void main()
{
   double Val1 = 10.5, Val2 = 2.5;
   int num1 = 6, num2 = 5;
   long num3 = 12, num4 = 20;

   printf("\n Average = %lf", average(Val1, 3.5, Val2, 4.5, 0.0));
   printf("\n Average = %lf", average(1.0, 2.0, 0.0));
   printf("\n Average = %lf\n", average((double)num2, Val2,
                        (double)num1, (double)num4, (double)num3, 0.0));
}

/* Function to calculate the average of a variable number of arguments */
double average( double v1, double v2,...)
{
   va_list parg;                 /* Pointer for variable argument list */
   double sum = v1+v2;           /* Accumulate sum of the arguments    */
   double value = 0;             /* Argument value                     */
   int count = 2;                /* Count of number of arguments       */

   va_start(parg,v2);            /* Initialize argument pointer        */

   while((value = va_arg(parg, double)) != 0.0)
   {
     sum += value;
     count++;
   }
   va_end(parg);                 /* End variable argument process      */
   return sum/count;
}
