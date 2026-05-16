/*
===============================================================================
 ORBIT-X UYDU OTOMASYONU - OGRETMEN COZUM DOSYASI
===============================================================================

Bu dosya, orbitx_exam_broken.c icin ornek dogru cozumdur.

Derleme:
  gcc -Wall -Wextra -std=c11 orbitx_exam_solution.c -o orbitx_exam_solution

Beklenen cikti degerleri:
  Uydu adi: ORBIT-X
  Batarya ortalamasi: 68.50
  Kritik sicaklik sayisi: 2
  Anten sinyalleri: 52 55 73 59 88 67
  En guclu anten sinyali: 88
  Yakit yuzdesi: 30.00
  Gorev durumu: HAZIR DEGIL

===============================================================================
*/

#include <stdio.h>

#define TELEMETRY_COUNT 6
#define TEMP_LIMIT 75
#define MIN_BATTERY_AVG 60
#define MIN_FUEL_PERCENT 25

void printSatelliteName(const char *name)
{
    printf("Uydu adi: %s\n", name);
}

double calculateBatteryAverage(const int batteryLevels[], int count)
{
    int i;
    int total = 0;

    for (i = 0; i < count; i++) {
        total += batteryLevels[i];
    }

    return (double) total / count;
}

int countCriticalTemperatures(const int *temperatures, int count)
{
    int i;
    int criticalCount = 0;

    for (i = 0; i < count; i++) {
        if (*(temperatures + i) > TEMP_LIMIT) {
            criticalCount++;
        }
    }

    return criticalCount;
}

int findStrongestSignal(const int signals[], int count)
{
    int i;
    int strongest = signals[0];

    for (i = 1; i < count; i++) {
        if (signals[i] > strongest) {
            strongest = signals[i];
        }
    }

    return strongest;
}

double calculateFuelPercent(int fuelKg, int maxFuelKg)
{
    return ((double) fuelKg / maxFuelKg) * 100;
}

void repairWeakSignals(int *signals, int count)
{
    int i;

    for (i = 0; i < count; i++) {
        if (signals[i] < 50) {
            signals[i] += 10;
        }
    }
}

int isMissionReady(double batteryAverage, int criticalTemperatureCount,
                   double fuelPercent, int strongestSignal)
{
    if (batteryAverage >= MIN_BATTERY_AVG &&
        criticalTemperatureCount == 0 &&
        fuelPercent >= MIN_FUEL_PERCENT &&
        strongestSignal >= 70) {
        return 1;
    }

    return 0;
}

void printSignals(const int signals[], int count)
{
    int i;

    printf("Anten sinyalleri: ");

    for (i = 0; i < count; i++) {
        printf("%d ", signals[i]);
    }

    printf("\n");
}

int main(void)
{
    char satelliteName[] = "ORBIT-X";

    int batteryLevels[TELEMETRY_COUNT] = {82, 77, 64, 58, 61, 69};
    int temperatures[TELEMETRY_COUNT] = {62, 71, 80, 74, 79, 68};
    int antennaSignals[TELEMETRY_COUNT] = {42, 55, 73, 49, 88, 67};

    int fuelKg = 180;
    int maxFuelKg = 600;

    double batteryAverage;
    int criticalTemperatureCount;
    int strongestSignal;
    double fuelPercent;
    int missionReady;

    printSatelliteName(satelliteName);

    batteryAverage = calculateBatteryAverage(batteryLevels, TELEMETRY_COUNT);
    criticalTemperatureCount = countCriticalTemperatures(temperatures, TELEMETRY_COUNT);

    repairWeakSignals(antennaSignals, TELEMETRY_COUNT);
    strongestSignal = findStrongestSignal(antennaSignals, TELEMETRY_COUNT);

    fuelPercent = calculateFuelPercent(fuelKg, maxFuelKg);

    missionReady = isMissionReady(batteryAverage, criticalTemperatureCount,
                                  fuelPercent, strongestSignal);

    printf("Batarya ortalamasi: %.2f\n", batteryAverage);
    printf("Kritik sicaklik sayisi: %d\n", criticalTemperatureCount);
    printSignals(antennaSignals, TELEMETRY_COUNT);
    printf("En guclu anten sinyali: %d\n", strongestSignal);
    printf("Yakit yuzdesi: %.2f\n", fuelPercent);

    if (missionReady == 1) {
        printf("Gorev durumu: HAZIR\n");
    } else {
        printf("Gorev durumu: HAZIR DEGIL\n");
    }

    return 0;
}
