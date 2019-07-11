
#include "tls.h"

double get_random_real_0_1() {
    static std::random_device rd;
    static std::mt19937 gen(rd());
    static std::uniform_real_distribution<> dis(0.0, 1.0);
    return dis(gen);
}

bool get_true_with_probability(double p) {
    return get_random_real_0_1() <= p;
}

double get_random_normal_distribution(double m, double d) {
    static std::random_device rd;
    static std::mt19937 gen(rd());
    std::normal_distribution<> dis(m, d);
    return dis(gen);
}
