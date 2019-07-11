

#include "tls.h"

void test3() {
    const uint sz_ar_events = 50;
    uint ar_events[sz_ar_events];
    for (uint i = 0; i < sz_ar_events; ++i) ar_events[i] = 0;
    uint cnt_events = 0;

    uint k = 4;
    uint n = 5;

    // предположим что вероятность решки выпадает
    //   по нормальному распределению с такими параметрами
    double coin_mean = 0.5;
    double coin_dev = 0.1;

    while (cnt_events < 100000) {
        // случайный выбор предполагаемой вероятности
        // эксперимента, из диапазона 0..1
        double probability = get_random_normal_distribution(coin_mean, coin_dev);
        if (probability <= 0.0 || probability >= 1.0) continue;

        uint c_true = 0;
        for (uint i = 0; i < n; ++i) {
            // если вероятность события в эксперименте probability,
            // то n-раз взяли истина или ложь с выбранной ранее вероятностью
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

    for (uint i = 0; i < sz_ar_events; ++i) {
        double p = (0.5 + DD(i))/sz_ar_events;
        // предположенное распределение всех монет
        double g = gauss(p, coin_mean, coin_dev);
        // распределение текущей исследуемой монеты
        // плотность вероятности: вероятность на отрезке деленное на протяженность отрезка
        double v = DD(ar_events[i])/cnt_events / (1.0/sz_ar_events);
        printf("%4.2f %f %f\n", p, g, v);
    }
}

