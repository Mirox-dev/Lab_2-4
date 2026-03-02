# Lab_2-4

*[Русский](#ru) | [English](#en)*

---

<a name="ru"></a>

## Описание

Два учебных консольных приложения на **C++**, демонстрирующих работу с динамической памятью и указателями.

## Lab 2-3 — Анализ показаний датчика

Программа принимает N вещественных показаний датчика (диапазон −50…50) и вычисляет:

- Среднее значение
- Минимальное и максимальное значение
- Список значений, превышающих среднее

**Файл:** `Lab2_3.cpp`

### Сборка и запуск

```bash
g++ Lab2_3.cpp -o sensor
./sensor
```

### Пример работы

```
=== Sensor analysis ===
Enter the number of measurements: 5
Enter values: 1.5 3.0 -2.0 4.5 2.0
Average value is: 1.8
Minimum value is: -2
Maximum value is: 4.5
Above average values are: 3 4.5 2
```

---

## Lab 4 — Анализ температуры

Программа принимает температурные данные за D дней, H измерений в день, и определяет «жаркие дни» — те, чья средняя температура превышает общее среднее.

**Файл:** `Lab4.cpp`

### Сборка и запуск

```bash
g++ Lab4.cpp -o temperature
./temperature
```

### Пример работы

```
Enter the number of days: 3
Enter the number of measurements in single day: 2
Day 1: 20.0 22.0
Day 2: 30.0 35.0
Day 3: 18.0 19.0
Overall average temperature is: 24
Hot days:
Day 2 (average = 32.5)
```

---

<a name="en"></a>

## Description

Two educational console applications in **C++**, demonstrating dynamic memory allocation and pointer arithmetic.

## Lab 2-3 — Sensor Data Analysis

The program reads N floating-point sensor measurements (range −50…50) and computes:

- Average value
- Minimum and maximum value
- List of values above the average

**File:** `Lab2_3.cpp`

### Build & Run

```bash
g++ Lab2_3.cpp -o sensor
./sensor
```

### Example

```
=== Sensor analysis ===
Enter the number of measurements: 5
Enter values: 1.5 3.0 -2.0 4.5 2.0
Average value is: 1.8
Minimum value is: -2
Maximum value is: 4.5
Above average values are: 3 4.5 2
```

---

## Lab 4 — Temperature Analysis

The program reads temperature data for D days with H measurements per day and identifies "hot days" — days whose average temperature exceeds the overall average.

**File:** `Lab4.cpp`

### Build & Run

```bash
g++ Lab4.cpp -o temperature
./temperature
```

### Example

```
Enter the number of days: 3
Enter the number of measurements in single day: 2
Day 1: 20.0 22.0
Day 2: 30.0 35.0
Day 3: 18.0 19.0
Overall average temperature is: 24
Hot days:
Day 2 (average = 32.5)
```
