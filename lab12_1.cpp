#include <iostream>
#include <cmath>
using namespace std;

void stat(const double[],int,double []);

int main()
{
    double A[] = {1.2,-3.5,6.9,7.8,12.5,-0.5};
    int N = sizeof(A)/sizeof(A[0]);
    double B[4];
    stat(A,N,B);
    cout << "Average = " << B[0];
    cout << "\nS.D. = " << B[1];
    cout << "\nMax = " << B[2];
    cout << "\nMin = " << B[3];
    return 0;
}

void stat(const double A[],int N,double B[]){
    int i;
    double mean,sd,max,min,sum=0,sump2=0;
    for(i=0;i<N;i++){
        sum += A[i];
        sump2 += pow(A[i],2); 
        if(A[i]>max||i==0) max=A[i];
        if(A[i]<min||i==0) min=A[i];
    }
    mean=sum/N;
    B[0] = mean;
    B[1] = sqrt((1.0/N*sump2)-pow(mean,2));
    B[2] = max;
    B[3] = min;
}
