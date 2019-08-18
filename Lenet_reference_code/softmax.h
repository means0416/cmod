#include <cstdio>
#include <cstdlib>
#include <opencv2/opencv.hpp>
#include <iostream>
#include <cmath>
#include <time.h>
#include <cstring>

using namespace cv;
using namespace std;

void softMax(double *input, int quantity){
    double max = 0.0;
    double sum = 0;
    double *result = (double*)malloc(sizeof(double)*quantity);

    for(int out = 0 ; out<quantity ; out++){
            if (max < input[out])
            max = input[out]; 
    }

    for(int out = 0 ; out<quantity ; out++){
            sum += exp(input[out]-max); 
    }

    for(int out = 0 ; out<quantity ; out++){
        *(result+out) = exp(input[out]-max)/sum;
        printf(" %.4lf - '%d'\n", *(result+out), out);
    } 
    free(result);  
}