
#include "tls.h"

void test1() {
    uint sz_ar_events = 50; // замеряемых точек графика
    uint ar_events[sz_ar_events]; // в этом массиве сбор данных для графика
    for (uint i = 0; i < sz_ar_events; ++i) ar_events[i] = 0;
    uint cnt_events = 0; // сколько уже событий в точках графика

    uint k = 4; // k событий из n экспериментов
    uint n = 5;

    while (cnt_events < 1000000) {
        // случайный выбор предполагаемой вероятности
        // эксперимента, из диапазона 0..1
        double probability = get_random_real_0_1();

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
            ++cnt_events; // всего событий
            ++ar_events[idx]; // событий в этой точке графика
        }
    }

    for (uint i = 0; i < sz_ar_events; ++i) {
        double p0 = DD(i)/sz_ar_events;
        // плотность вероятности: вероятность на отрезке деленное на протяженность отрезка
        double v = DD(ar_events[i])/cnt_events / (1.0/sz_ar_events);
        printf("%4.2f %f\n", p0, v);
    }
}

