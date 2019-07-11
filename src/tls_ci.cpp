
#include "tls.h"

std::pair<double,double> borders_ci(
        uint ar_events[], uint sz, double confidence_interval) {

    // ar_events - точки графика с накопленной статистикой
    // sz - количество точек графика
       
    uint cnt = 0;
    // всего данных в массиве данных
    for (uint i = 0; i < sz; ++i) cnt += ar_events[i];

    // количество лишних данных слева и справа
    double proc_cnt = (1.0 - confidence_interval) * cnt / 2.0;

    double lo = 0;

    uint su = 0;
    // отсчитываю данные слева
    for (uint i = 0; i < sz; ++i) {
        uint c_in_stp = ar_events[i];

        if (su + c_in_stp >= proc_cnt) {
            // граница определяется пропорцией по точке графика,
            //   размерность одной точки графика это 1.0/sz
            lo = (DD(i) + (proc_cnt - DD(su)) / DD(c_in_stp)) / DD(sz);
            break;
        }

        su += c_in_stp;
    }

    double hi = 0;
    su = 0;
    // отсчитываю данные справа
    for (uint i = sz; i > 0; --i) {
        uint c_in_stp = ar_events[i-1];

        if (su + c_in_stp >= proc_cnt) {
            hi = (DD(i) - (proc_cnt - DD(su)) / DD(c_in_stp)) / DD(sz);
            break;
        }

        su += c_in_stp;
    }

    return std::make_pair(lo,hi);
}
