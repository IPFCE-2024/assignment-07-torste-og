/*
 * Exercise 1: Taylor Series Approximation for Sine Function
 * Assignment 7 - IPFCE 2025
 * 
 * Implement the taylor_sine function that calculates the sine of x
 * using Taylor series approximation with n terms.
 * 
 * Taylor series for sin(x) = x - x^3/3! + x^5/5! - x^7/7! + ...
 */

#include "include/taylor_sine.h"
#include <assert.h>

/* 
 * Calculate sine using Taylor series approximation
 * x: input value in radians
 * n: number of terms in the series
 * Returns: approximation of sin(x)
 */


#define PI 3.1415926535

double norm_angle(double x) {
    while (x > PI)
        x -= PI;
    while (x < -PI)
        x += PI;

    return x;
}

double taylor_sine(double x, int n) {
    // TODO: Implement the Taylor series approximation for sine
    // Hint: The series is: x - x^3/3! + x^5/5! - x^7/7! + ...
    // Use a loop to calculate n terms of the series

    assert(n > 0);

    x = norm_angle(x);

    double term = x;
    double sum = x;

    for (int i = 1; i < n; i++) {
        term *= (x * x) / ((2.0 * i) * (2.0 * i + 1.0));
        
        if (i % 2 == 1) {
            sum -= term;
        } else {
            sum += term;
        }
    }
    
    return sum;
}