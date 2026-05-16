/*
===============================================================================
 ORBIT-X UYDU OTOMASYONU - C PROGRAMLAMA UYGULAMA SINAVI
===============================================================================

Bu dosya bilerek hatali yazilmistir. Goreviniz programi derlenebilir ve dogru
calisabilir hale getirmektir.

Tema:
  ORBIT-X yer istasyonu, bir haberlesme uydusundan gelen telemetri verilerini
  kontrol etmektedir. Program; batarya, sicaklik, anten sinyal gucu ve yakit
  verilerini analiz ederek uydunun goreve hazir olup olmadigini raporlamalidir.

Kurallar:
  1. Program C dilinde kalmalidir.
  2. main fonksiyonundaki veri setleri korunmalidir.
  3. Fonksiyon isimlerini degistirmeyiniz.
  4. Program uyarilarla degil, temiz sekilde derlenmelidir.
  5. Cozumunuzda hard-code sonuc yazmak yerine hesaplama yapiniz.

Beklenen genel davranis:
  - Uydu adini duzgun yazdirmali.
  - Batarya ortalamasini hesaplamali.
  - Kritik sicaklik sayisini bulmali.
  - En guclu anten sinyalini bulmali.
  - Yakit yuzdesini dogru hesaplamali.
  - Gorev durumunu verilerden uretmelidir.

Derleme onerisi:
  gcc -Wall -Wextra -std=c11 orbitx_exam_broken.c -o orbitx_exam

===============================================================================
*/

#include <stdio.h>
#include <string.h>

#define TELEMETRY_COUNT 6
#define TEMP_LIMIT 75
#define MIN_BATTERY_AVG 60
#define MIN_FUEL_PERCENT 25

/* Gorev: Uydu adini ekrana "Uydu adi: ..." formatinda yazdirmalidir.
   Parametre: name, null karakteri ile biten uydu adidir. */
void printSatelliteName(char *name)
{
    int i;

    printf("Uydu adi: ");

    for (i = 0; i <= strlen(name); i++) {    /* ! */
        printf("%c", name[i]);
    }

    printf("\n");
}

/* Gorev: Batarya yuzdelerinin ortalamasini hesaplayip double olarak dondurmelidir.
   Parametreler: batteryLevels batarya verilerini temsil etmelidir. */
double calculateBatteryAverage(int batteryLevels[])
{    /* ! */
    int i;
    int total = 0;
    int count = sizeof(batteryLevels) / sizeof(batteryLevels[0]);    /* ! */

    for (i = 0; i <= count; i++) {    /* ! */
        total += batteryLevels[i];
    }

    return total / count;    /* ! */
}

/* Gorev: TEMP_LIMIT degerinden buyuk sicaklik olcumlerinin sayisini bulmalidir.
   Parametreler: temperatures sicaklik dizisini, count ise eleman sayisini temsil eder. */
int countCriticalTemperatures(int *temperatures, int count)
{
    int i;
    int criticalCount = 0;

    for (i = 1; i <= count; i++) {    /* ! */
        if (*(temperatures + i) > TEMP_LIMIT) {
            criticalCount++;
        }
    }

    return criticalCount;
}

/* Gorev: Anten sinyalleri arasindaki en yuksek sinyal degerini dondurmelidir.
   Parametreler: signals sinyal dizisini, count ise eleman sayisini temsil eder. */
int findStrongestSignal(int signals[], int count)
{
    int i;
    /* ipucu: strongest degiskeninin ilk degeri algoritmanin icra edilebilmesi
    icin ne olmalidir? */
    int strongest = 0;
    for (i = 0; i < count; i++) {
        if (signals[i] < strongest) {    /* ! */
            strongest = signals[i];
        }
    }

    return strongest;
}

/* Gorev: Mevcut yakitin maksimum yakita gore yuzdesini double olarak hesaplamalidir.
   Parametreler: fuelKg mevcut yakit miktari, maxFuelKg maksimum yakit kapasitesidir. */
double calculateFuelPercent(int fuelKg, int maxFuelKg)
{    /* ! */
    return fuelKg / maxFuelKg * 100;
}

/* Gorev: 50'nin altindaki zayif anten sinyallerini 10 puan artirarak iyilestirmelidir.
   Parametreler: signals guncellenecek sinyal dizisini, count ise eleman sayisini temsil eder. */
void repairWeakSignals(int *signals, int count)
{
    int i;
    /* ! */
    for (i = 0; i <= count; i++) {
        if (signals[i] < 50) {
            signals[i] = signals[i] + 10;
        }
    }
}

/* Gorev: Batarya, sicaklik, yakit ve sinyal kosullarina gore gorevin hazir olup
   olmadigini belirlemelidir. Tum guvenlik kosullari saglaniyorsa 1, degilse 0 dondurmelidir. */
int isMissionReady(double batteryAverage, int criticalTemperatureCount,
                   double fuelPercent, int strongestSignal)
{    /* ! */
    if (batteryAverage > MIN_BATTERY_AVG ||
        criticalTemperatureCount == 0 ||
        fuelPercent > MIN_FUEL_PERCENT ||
        strongestSignal > 70) {
        return 1;
    }

    return 0;
}

/* Gorev: Anten sinyal dizisindeki tum degerleri ekrana sirayla yazdirmalidir.
   Parametreler: signals yazdirilacak sinyal dizisini, count ise eleman sayisini temsil eder. */
void printSignals(int signals[], int count)
{
    int i;

    printf("Anten sinyalleri: ");
      /* ! */
    for (i = 0; i < count; i++);
    {
        printf("%d ", signals[i]);
    }

    printf("\n");
}

/* Gorev: ORBIT-X telemetri verilerini hazirlar, fonksiyonlari cagirir ve analiz
   sonuclarini ekrana yazdirir. */
int main(void)
{
    char satelliteName[8] = "ORBIT-X";   /* ! */

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
    /* ! */
    batteryAverage = calculateBatteryAverage(batteryLevels);
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
    /* ! */
    if (missionReady = 1) {
        printf("Gorev durumu: HAZIR\n");
    } else {
        printf("Gorev durumu: HAZIR DEGIL\n");
    }

    return 0;
}
