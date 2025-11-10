//
// Created by user on 10.11.2025.
//

#include <iostream>
#include <sstream>
#include <string>

using namespace std;

void inputData(float* const p, int n) {
    cout << "Введите значения: ";
    string s;
    cin >> s;
    istringstream ss(s);
    for (int i = 0; i < n; i++) {
        if (!(ss >> *(p + i))) {
            ss >> *(p + i);
            if (-50 <= *(p + i) <= 50) {
                cout << "Неверный ввод";
                exit(0);
            }
        }
        else {
            exit(0);
        }
    }
}
float average(const float* p, int n) {
    float avg = 0.0;
    for (int i = 0; i < n; i++) {
        avg += *(p + i);
    }
    return (avg / static_cast<float>(n));
}

float minValue(const float* p, int n) {
    float min = *(p + 0);
    for (int i = 0; i < n; i++) {
        if (min > *(p + i)) {
            min = *(p + i);
        }
    }
    return min;
}

float maxValue(const float* p, int n) {
    float max = *(p + 0);
    for (int i = 0; i < n; i++) {
        if (max < *(p + i)) {
            max = *(p + i);
        }
    }
    return max;
}

float* filterAboveAverage(float* const p, int n, int& newCount) {
    float avg = average(p, n);
    for (int i = 0; i < n; i++) {
        if (*(p + i) > avg) {
            newCount++;
        }
    }
    int j = 0;
    auto* result = new float[newCount];
    for (int i = 0; i < n; i++) {
        if (*(p + i) > avg) {
            *(result + j) = *(p + i);
            j++;
        }
    }
    return result;
}

int main() {
    int n;
    cout << "=== Анализ сенсора ===" << endl;
    cout << "Введите количество измерений: ";
    cin >> n;
    auto* data = new float[n];
    inputData(data, n);
    float avg = average(data, n);
    float min = minValue(data, n);
    float max = maxValue(data, n);
    int newCount;
    float* aboveAvg = filterAboveAverage(data, n, newCount);
    for (int i = 0; i < n; i++) {
        cout << *(data + i);
    }
    delete[] data;
    delete[] aboveAvg;
    return 0;
}