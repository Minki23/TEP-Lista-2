#include <iostream>
#include "CNumber.h"

int main()
{
    CNumber numer1;
    CNumber numer2 = 12;
    CNumber zero = 0;
    1024 >= numer1 >= numer2;
    std::cout << numer1.sToStr() << " n1 tosting\n";
    std::cout << numer2.sToStr() << " n2 tosting\n";
    std::cout << zero.sToStr() << " zero tosting\n\n";

    numer1 = -6;
    numer2 = numer1;
    numer1 = 4;

    std::cout << numer1.sToStr() << " n1 tosting zmiana\n";
    std::cout << numer2.sToStr() << " n2 tosting zmiana\n\n";

    std::cout << (numer2 + numer1).sToStr() << " dodawanie\n";
    std::cout << (numer1 + numer2).sToStr() << " dodawanie\n";
    std::cout << (zero + numer1).sToStr() << " dodawanie\n";
    std::cout << (numer2 + zero).sToStr() << " dodawanie\n";
    std::cout << (zero + zero).sToStr() << " dodawanie\n\n";

    std::cout << (zero - numer1).sToStr() << " odejmowanie\n";
    std::cout << (numer2 - numer1).sToStr()<<" odejmowanie\n";
    std::cout << (numer1 - numer2).sToStr() << " odejmowanie\n";
    std::cout << (numer2 - zero).sToStr() << " odejmowanie\n";
    std::cout << (numer2 - numer2).sToStr() << " odejmowanie\n";
    std::cout << (zero - zero).sToStr() << " odejmowanie\n\n";

    std::cout << (numer1 * numer2).sToStr() << " mnozenie\n";
    std::cout << (numer2 * numer1).sToStr() << " mnozenie\n";
    std::cout << (numer2 * numer2).sToStr() << " mnozenie\n";
    std::cout << (numer1 * numer1 * numer1*numer1).sToStr() << " mnozenie\n";
    std::cout << (numer2 * zero).sToStr() << " mnozenie\n";
    std::cout << (zero * numer2).sToStr() << " mnozenie\n";
    std::cout << (zero * numer1).sToStr() << " mnozenie\n";
    std::cout << (zero * zero).sToStr() << " mnozenie\n\n";

    std::cout << (numer1/numer2).sToStr() << " dzielenie\n";
    std::cout << (numer2 / numer1).sToStr() << " dzielenie\n";
    std::cout << (numer1 / zero).sToStr() << " dzielenie\n";
    std::cout << (zero / zero).sToStr() << " dzielenie\n";
    std::cout << (zero / numer1).sToStr() << " dzielenie\n\n";

    return 0;
}