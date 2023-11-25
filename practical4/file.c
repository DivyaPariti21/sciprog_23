#include<stdio.h>
#include<math.h>
// Declaring global variables
int N=12;
// Declaring array
double TanValues[13];
// Declaring the necessary functions 
double degtorad(double deg);
double traprule(int N);


int main() {

    int i;
    double deg, rad;
    // Initiating loop to convert degrees
    for(i=0;i<=N;i++){
        deg = 5.0*i;
        rad = degtorad(deg);
        TanValues[i] = tan(rad);
    }
    //Finding approximate value using trapezoidal rule
    double integral_approx = traprule(N);
    //Finding exact value which is log(2.0)
    double integral_exact = log(2.0);
    //Comparing exact and approximate value
    printf("The approximation of the integral from x=0 degrees to x=60 degrees of the function tan(x) ith respect to x is :\n %.5f\nThe exact soultion is :\n%.5f\n", integral_approx, integral_exact);
    return 0;
}

// Defining the funciton to convert degrees to radius
double degtorad(double deg){
    return (deg * M_PI)/180.0;
}

double traprule(int N){
    int i;
    //Initializing area as the sum of first and last term
    double width, area = TanValues[0] + TanValues[N];
    for(i=1; i<N; i++){
        area = area + 2.0*TanValues[i];
    }
    //Adding b-a/2N to area
    width = degtorad((60.0 - 0)/(2.0*N));
    area = width * area;

    return area;
}
