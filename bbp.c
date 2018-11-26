/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   bpp.c
 * Author: tonor
 *
 * Created on 2018. szeptember 28., 19:10
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>


long n16modk(int n, int k) {

    int t = 1;
    while (t <= n)
        t *= 2;

    long r = 1;

    while (1) {

        if (n >= t) {
            r = (16 * r) % k;
            n = n - t;
        }

        t = t / 2;

        if (t < 1)
            break;

        r = (r * r) % k;

    }

    return r;
}

double d16Sj(int d, int j) {

    double d16Sj = 0.0;

    for (int k = 0; k <= d; ++k)
        d16Sj += (double) n16modk(d - k, 8 * k + j) / (double) (8 * k + j);



    return d16Sj - floor(d16Sj);
}

int main(int argc, char** argv) {

    double d = 1000000;
    double d16Pi = 0.0;

    double d16S1t = d16Sj(d, 1);
    double d16S4t = d16Sj(d, 4);
    double d16S5t = d16Sj(d, 5);
    double d16S6t = d16Sj(d, 6);

    d16Pi = 4.0 * d16S1t - 2.0 * d16S4t - d16S5t - d16S6t;

    d16Pi = d16Pi - floor(d16Pi);


    char hexaJegyek[] = {'A', 'B', 'C', 'D', 'E', 'F'};

    while (d16Pi != 0.0) {

        int jegy = (int) floor(16.0 * d16Pi);

        if (jegy < 10) {

            printf("%d",jegy);
        } else {

            printf("%c",(hexaJegyek[jegy - 10]));
        }
        d16Pi = (16.0 * d16Pi) - floor(16.0 * d16Pi);
    }


    return (EXIT_SUCCESS);
}

