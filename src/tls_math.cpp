
#include "tls.h"

double pow_n(double v, uint n) {
    return (n==0 ? 1.0 : v * pow_n(v, n-1));
}

double factorial(uint n) {
    return (n<=1 ? 1.0 : n * factorial(n-1));
}

double binom(uint k, uint n) {
    return factorial(n) / factorial(k) / factorial(n-k);
}

double bernoulli(double p, uint k, uint n) {
    return pow_n(p, k) * pow_n(1.0 - p, n-k) * binom(k, n);
}

double SQR(double v) { return v*v; }

double gauss(double x, double mean, double std_dev) {
    double variance = SQR(std_dev);
    return 1.0 / sqrt( 2.0 * variance * M_PI ) * exp( - SQR(x - mean) / 2.0 / variance );
}



