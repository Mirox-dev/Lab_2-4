//
// Created by user on 29.11.2025.
//

#include <iostream>
#include <sstream>
#include <string>

using namespace std;

void inputData(float** const p, const int d, const int h){
    for (int i = 0; i < d; i++) {
        while (true) {
            cout << "Day " << i+1 << ": ";
            string s;
            getline(cin, s);
            istringstream ss(s);  // Важно
            bool exit = true;
            for (int j = 0; j < h; j++) {
                if (!(ss >> *(*(p + i) + j))) {
                    cout << "Wrong input, try again" << endl;
                    exit = false;
                    break;
                }
                if (*(*(p + i) + j) < -50 or *(*(p + i) + j) > 50) {
                    cout << "Wrong input, try again" << endl;
                    exit = false;
                    break;
                }
            }
            if (char one_more; exit && ss >> one_more) {
                cout << "Wrong input, try again" << endl;
                exit = false;
            }
            if (exit) break;
        }
    }
}

float dayAverage(const float* row, const int h) {
    float avg = 0.0;
    for (int i = 0; i < h; i++) {
        avg += *(row + i);
    }
    return avg / static_cast<float>(h);
}

float overallAverage(float** p, const int d, const int h) {
    float ovravg = 0.0;
    for (int i = 0; i < d; i++) {
        ovravg += dayAverage(*(p + i), h);
    }
    return ovravg / static_cast<float>(d);
}

void showHotDays(float** p, const int d, const int h) {
    const float avg = overallAverage(p, d, h);
    for (int i = 0; i < d; i++) {
        if (dayAverage(*(p +i), h) > avg) {
            cout << "Day " << i+1 << " (average = " << dayAverage(*(p + i), h) << ")" << endl;
        }
    }
}

int main() {
    int d, h;
    string input;
    while (true) {
        cout << "Enter the number of days: ";
        getline(cin, input);
        if (stringstream ss(input); ss >> d && ss.eof() and 0 < d < 31) {
            break;
        }
        else {
            cout << "Wrong input, try again" << endl;
        }
    }
    while (true) {
        cout << "Enter the number of measurements in single day: ";
        getline(cin, input);
        if (stringstream ss(input); ss >> h && ss.eof() and 0 < h < 24) {
            break;
        }
        else {
            cout << "Wrong input, try again" << endl;
        }
    }
    auto** data = new float*[d];
    for (int i = 0; i < d; i++) {
        *(data + i) = new float[h];
    }
    inputData(data, d, h);
    cout << "Overall average temperature is: " << overallAverage(data, d, h) << endl;
    cout << "Hot days:" << endl;
    showHotDays(data, d, h);
    for (int i = 0; i < d; i++) {
        delete[] *(data + i);
    }
    delete[] data;
    return 0;
}