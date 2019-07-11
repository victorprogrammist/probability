
#ifndef TLS_H
#define TLS_H

#include <cstdio>
#include <cmath>
#include <random>
#include <assert.h>
#include <vector>
#include <tuple>

using uint = unsigned int;

#define DD(X) static_cast<double>(X)
#define DIV(X,Y) (DD(X)/DD(Y))

double gauss(double x, double mean, double std_dev);
double SQR(double v);
double bernoulli(double p, uint k, uint n);
double binom(uint k, uint n);
double factorial(uint n);
double pow_n(double v, uint n);

double get_random_real_0_1();
bool   get_true_with_probability(double p);
double get_random_normal_distribution(double m, double d);

std::pair<double,double> borders_ci(
        uint ar_events[], uint sz, double confidence_interval);

#endif // TLS_H
