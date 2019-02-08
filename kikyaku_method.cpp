#include<stdio.h>
#include<iostream>
#include<math.h>
#include<stdlib.h>
#include<omp.h>
#include<vector>
#include<cmath>
#include<random>

#define  a1 1.0
#define  b1 0.0
#define  a2 1.0
#define  b2 0.0
#define NN 100
#define cout_m 100000000
#define cout_b 100
double arch2(double x,double y);
double arch3(double x,double y,double z);
double arch9(double x1,double x2,double x3,double x4,double x5,double x6,double x7,double x8,double x9);
double arch10(double x1,double x2,double x3,double x4,double x5,double x6,double x7,double x8,double x9,double x10);
int main(){
    std::random_device rn;
    std::mt19937 st_ran(rn());
    std::uniform_real_distribution<> rand_pi(b1,a1); 
    double test_cal=0.0;
    double sum_s=0.0;    
    double arch9_array[9];
    double rm=0.0;
    
    #pragma omp parallel for  reduction(+:sum_s)
    for(int i=0;i<cout_b;i++){
            test_cal=arch3(rand_pi(st_ran),rand_pi(st_ran),rand_pi(st_ran));
            if(test_cal < 1.0){
                sum_s++;
            }
    }
    


    std::cout << (sum_s/cout_b)*8.0 << std::endl;
    int j=0;
    sum_s=0.0;
    
#pragma omp parallel for  reduction(+:sum_s) 
    for(int i=0;i<cout_m;i++){
       
        test_cal=arch9(rand_pi(st_ran),rand_pi(st_ran),rand_pi(st_ran),rand_pi(st_ran),rand_pi(st_ran),rand_pi(st_ran),rand_pi(st_ran),rand_pi(st_ran),rand_pi(st_ran));
        if(test_cal < 1.0){
            sum_s++;
        }
    }
 std::cout << (sum_s/cout_m)*pow(2,9) << std::endl;
 
}

double arch2(double x,double y){
    return x*x+y*y;
}

double arch3(double x,double y,double z){
    return x*x+y*y+z*z;
}

double arch9(double x1,double x2,double x3,double x4,double x5,double x6,double x7,double x8,double x9){
    return x1*x1+x2*x2+x3*x3+x4*x4+x5*x5+x6*x6+x7*x7+x8*x8+x9*x9;
}

double arch10(double x1,double x2,double x3,double x4,double x5,double x6,double x7,double x8,double x9,double x10){
    return x1*x1+x2*x2+x3*x3+x4*x4+x5*x5+x6*x6+x7*x7+x8*x8+x9*x9+x10*x10;
}



