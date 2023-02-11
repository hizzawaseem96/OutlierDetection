#include <stdio.h>
#include "test.h"

void printArray(int* array, int array_length);
void testFunction(int* input_data, int* output_data, int input_data_length, int max_change_rate);

int main() {
   int input_data[5] = {1,3,783,9,200};
   int output_data[5];
   testFunction(input_data, output_data, 5, 10);

   int input1_data[5] = {1,-20,-783,-58,-200};
   testFunction(input1_data, output_data, 5, 10);

   int input2_data[5] = {1,5,-30,10,-200};
   testFunction(input2_data, output_data, 5, 10);
   
   return 0;
}

void printArray(int* array, int array_length){
   for(int i = 0; i < array_length; i++)
      printf("%d ", array[i]);
   printf(" \n");
}

void testFunction(int* input_data, int* output_data, int input_data_length, int max_change_rate){
   int num_errors = calculate(input_data, output_data, input_data_length, max_change_rate);
   printf("Number of outliers: %d\n", num_errors);
   printf("Input Array: ");
   printArray(input_data, input_data_length);
   printf("Output Array: ");
   printArray(output_data, input_data_length);
}