#include <iostream>
#include <vector>
#include <map>
#include <cmath>
#include <iomanip>

std::vector<double> task() 
{
    // Мапы для хранения вероятностей
    std::map<int, double> probA, probB, probAB;
    
    // Вычисление вероятностей для суммы (A) и произведения (B)
    for (int i = 1; i <= 6; ++i) {
        for (int j = 1; j <= 6; ++j) {
            int sum = i + j;
            int product = i * j;
            probA[sum] += 1.0 / 36;
            probB[product] += 1.0 / 36;
            probAB[sum * 10 + product] += 1.0 / 36; // Уникальный ключ для пары (A,B)
        }
    }

    // Энтропия H(A), H(B) и H(A,B)
    double HA = 0, HB = 0, HAB = 0;
    for (const auto& p : probA) {
        HA -= p.second * log2(p.second);
    }
    for (const auto& p : probB) {
        HB -= p.second * log2(p.second);
    }
    for (const auto& p : probAB) {
        HAB -= p.second * log2(p.second);
    }

    // Условная энтропия Ha(B)
    double HaB = 0;
    for (const auto& p : probAB) {
        int sum = p.first / 10;
        double pA = probA[sum];
        HaB -= p.second * log2(p.second / pA);
    }

    // Взаимная информация I(A,B)
    double IAB = HA + HB - HAB;

    // Округление до двух знаков после запятой
    return {round(HAB * 100) / 100, round(HA * 100) / 100, round(HB * 100) / 100, round(HaB * 100) / 100, round(IAB * 100) / 100};
}
