

#include "tls.h"


static std::vector<double> make_case(
        uint k, uint n, uint sz_ar_events, uint ma_cnt_events) {

    uint ar_events[sz_ar_events];
    for (uint i = 0; i < sz_ar_events; ++i) ar_events[i] = 0;
    uint cnt_events = 0;

    while (cnt_events < ma_cnt_events) {
        // выбор случайной вероятности из диапазона 0..1
        double probability = get_random_real_0_1();

        uint c_true = 0;
        for (uint i = 0; i < n; ++i) {
            // n-раз взяли истина или ложь с выбранной ранее вероятностью
            bool v = get_true_with_probability(probability);
            if (v) ++c_true;
        }

        // если из n-раз получили k-раз истину, значит это тот самый случай
        if (c_true == k) {
            uint idx = lrint(floor(probability*sz_ar_events));
            assert( idx < sz_ar_events ); // проверка, что с округлением не напутал
            ++ar_events[idx];
            ++cnt_events;
        }
    }

    std::vector<double> res;

    for (uint i = 0; i < sz_ar_events; ++i) {
        // плотность вероятности: вероятность на отрезке деленное на протяженность отрезка
        res.push_back( DD(ar_events[i])/cnt_events / (1.0/sz_ar_events));
    }

    double lo;
    double hi;
    std::tie(lo,hi) = borders_ci(ar_events, sz_ar_events, 0.95);

    printf("ready %i / %i, confidence interval: %f - %f (%f)\n", k, n, lo, hi, hi-lo);

    return res;
}

void test2() {

    std::vector<std::vector<double>> ar;

    uint sz_ar_events = 50;
    uint ma_cnt_events = 1000000;

    ar.push_back(make_case(4,5, sz_ar_events, ma_cnt_events));
    ar.push_back(make_case(7,9, sz_ar_events, ma_cnt_events));
    ar.push_back(make_case(11,14, sz_ar_events, ma_cnt_events));
    ar.push_back(make_case(24,30, sz_ar_events, ma_cnt_events));

    for (uint i = 0; i < sz_ar_events; ++i) {
        double p0 = DD(i)/sz_ar_events;
        printf("%4.2f %f %f %f %f\n",
                p0,
                ar[0][i],
                ar[1][i],
                ar[2][i],
                ar[3][i]);
    }
}






