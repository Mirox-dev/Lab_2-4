//
// Created by user on 10.11.2025.
//

#include <iostream>
#include <sstream>
#include <string>
#include <limits>

using namespace std;

void inputData(float* const p, int n){
    while (true) {
        cout << "Enter values:  ";
        string s;
        getline(cin, s);
        istringstream ss(s);  // Важно
        bool exit = true;
        for (int i = 0; i < n; i++) {
            if (!(ss >> *(p + i))) {
                cout << "Wrong input, try again" << endl;
                exit = false;
                break;
            }
            if (*(p + i) < -50 or *(p + i) > 50) {
                cout << "Wrong input, try again" <<endl;
                exit = false;
                break;
            }
        }
        float one_more;
        if (exit && ss >> one_more) {
            cout << "Wrong input, try again" << endl;
            exit = false;
        }
        if (exit) break;
    }
}

float average(const float* p, int n) {
    float avg = 0.0;
    for (int i = 0; i < n; i++) {
        avg += *(p + i);
    }
    return (avg / static_cast<float>(n));    // Важно
}

float minValue(const float* p, int n) {
    float min = *p;
    for (int i = 0; i < n; i++) {
        if (min > *(p + i)) {
            min = *(p + i);
        }
    }
    return min;
}

float maxValue(const float* p, int n) {
    float max = *p;
    for (int i = 0; i < n; i++) {
        if (max < *(p + i)) {
            max = *(p + i);
        }
    }
    return max;
}

float* filterAboveAverage(const float* p, int n, int& newCount) {
    float avg = average(p, n);
    newCount = 0;
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
    cout << "=== Sensor analysis ===" << endl;
    cout << "Enter the number of measurements: ";
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    auto* data = new float[n];
    inputData(data, n);
    float avg = average(data, n);
    float min = minValue(data, n);
    float max = maxValue(data, n);
    int newCount;
    float* aboveAvg = filterAboveAverage(data, n, newCount);
    cout << "Average value is: " << avg << endl;
    cout << "Minimum value is: " << min << endl;
    cout << "Maximum value is: " << max << endl;
    cout << "Above average values are: ";
    if (newCount == 0) {
        cout << "No measurements found" << endl;
    }
    else {
        for (int i = 0; i < newCount; i++) {
            cout << *(aboveAvg + i) << " ";
        }
    }
    cout << endl;
    delete[] data;
    delete[] aboveAvg;
    return 0;
}