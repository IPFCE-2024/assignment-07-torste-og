/*
 * Exercise 1: Taylor Series Approximation for Sine Function
 * Assignment 7 - IPFCE 2025
 * 
 * Implement the taylor_sine function that calculates the sine of x
 * using Taylor series approximation with n terms.
 * 
 * Taylor series for sin(x) = x - x^3/3! + x^5/5! - x^7/7! + ...
 */

#include "taylor_sine.h"

/* 
 * Calculate sine using Taylor series approximation
 * x: input value in radians
 * n: number of terms in the series
 * Returns: approximation of sin(x)
 */
#define PI 3.14159265358979323846

/* funktion der holder vinklen x mellem pi og minus pi da sin kun tager værdier mellem pi og minus pi*/
double norm_angle(double x) {
    while (x > PI)
        x -= 2 * PI;
    while (x < -PI)
        x += 2 * PI;
return x;
}

double taylor_sine(double x, int n) {
    // TODO: Implement the Taylor series approximation for sine
    // Hint: The series is: x - x^3/3! + x^5/5! - x^7/7! + ...
    // Use a loop to calculate n terms of the series

    x = norm_angle(x); /*bruger den x værdi vi har fundet mellem PI og -PI*/

    double term = x; /*ledet*/
    double sum = term; /*summen*/
    double sign = -1.0; /*fortegnet*/

    for (int i = 1; i < n; i++){
        term = term * x * x / ((2 * i) * (2 * i + 1));
        sum += sign * term;
        sign = -sign;
    }
    return sum; // placeholder - replace with your implementation
}
