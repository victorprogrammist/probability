
#include <clocale>
#include <cstdio>
#include <windows.h>
#include <iostream>

void test1();
void test2();
void test3();
void test4();

#include <QTextStream>
#include <QTextCodec>

int main() {

    QTextStream cout(stdout);
#ifdef _WIN32
    cout.setCodec(QTextCodec::codecForName("cp866"));
#endif

    cout << QString(
                "1: данные распределения для 4 из 5\n"
                "2: распределения 4/5, 7/9, 11/14, 24/30 (долго)\n"
                "3: 4/5 при не равномерном исходном распределении\n"
                "4: 4/5...40/50 при не равномерном распределении (очень долго)\n"
                "5: выход\n\n[1..5] : ");

    cout.flush();

    int c = getchar();

    if (c == '1')
        test1();
    else if (c == '2')
        test2();
    else if (c == '3')
        test3();
    else if (c == '4')
        test4();

    return 0;
}




