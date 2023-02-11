#include <stdio.h>
#include <stdlib.h>

/// @brief
/// @param input_data         Input data array, first sample is assumed to be "correct"
/// @param output_data        Filtered and fitted output
/// @param input_data_length  Length of the input array
/// @param max_change_rate    limit that function should use to detect "outliers"
/// @return                   number of samples errors detected, 0 if no errors, -1 if not able to fit samples etc

int calculate(int* input_data, int* output_data, int input_data_length, int max_change_rate){
   int num_errors = 0;
   int prev_change_rate = 0;

   // first sample is assumed to be "correct"
   output_data[0] = input_data[0];

   // iterate through input data
   for (int i = 1; i < input_data_length; i++) {
        // calculate change rate
        int change_rate = input_data[i] - output_data[i-1];
        
        // check if current sample is an outlier
        if (abs(change_rate) > max_change_rate) {
            output_data[i] = output_data[i-1] + prev_change_rate;
            num_errors++;
        } 
        else {
            //prev_change_rate = change_rate;
            output_data[i] = input_data[i];
            prev_change_rate = change_rate;
        }
   }

    // if diff in values of the array are greater than max_change_rate than something is wrong with the data set (return -1)
    if(num_errors == (input_data_length - 1))
        return -1;
    // return number of errors
    return num_errors;
}