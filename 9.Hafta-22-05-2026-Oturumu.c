/*
Toplumsal açıdan güncel ve ilgi çekici bir konu olarak otonom bisiklet sürüş güvenliği seçilmiştir. Soruda, farklı bisiklet modelleri için ortak kod yazmaya imkan tanıyan void * tabanlı bir soyutlama yapısı bulunmaktadır. Kod parçasında bazı satırlar bilerek hatalı bırakılmıştır.

Beklenenler:

Fonksiyonlara bazen değişken, bazen değişken adresi, bazen de dizi parametresi geçirilmesi gereken yerleri doğru biçimde ayırt etmeniz
void * ile çalışan fonksiyonlarda uygun veri tipine göre doğru kullanımı bulmanız
Kod içindeki hatalı satırları düzeltmeniz
Not:
 * Her hatalı satırın hemen üstünde !!! ile başlayan bir ipucu yorumu bulunmaktadır.
 * Çözüm satırları, sınav öncesi kaldırılabilmesi için ilgili hatalı satırın altına yorum olarak eklenmiştir.

*/
#include <stdio.h>

/* Bu yapi sehir icinde kullanilan bir bisikletin temel bilgilerini tutar. */
typedef struct {
    /* model: bisikletin adini saklar. */
    char model[32];
    /* batteryLevel: pil yuzdesini tutar. */
    int batteryLevel;
    /* currentSpeed: o anki hizi tutar. */
    int currentSpeed;
    /* routeRiskScores: rota uzerindeki risk puanlarini dizi olarak tutar. */
    int routeRiskScores[4];
} CityBike;

/* Bu yapi yuk tasiyan bisikletin bilgilerini tutar. */
typedef struct {
    /* model: bisikletin adini saklar. */
    char model[32];
    /* batteryLevel: pil yuzdesini tutar. */
    int batteryLevel;
    /* currentSpeed: o anki hizi tutar. */
    int currentSpeed;
    /* cargoWeight: tasinan yuk miktarini tutar. */
    int cargoWeight;
    /* routeRiskScores: rota uzerindeki risk puanlarini dizi olarak tutar. */
    int routeRiskScores[4];
} CargoBike;

/* Bu fonksiyon pil degerini adres uzerinden degistirir. */
void setBatteryLevel(int *batteryLevel, int newLevel) {
    *batteryLevel = newLevel;
}

/* Bu fonksiyon hizi azaltir. Hiz 0'in altina dusmez. */
void applyEmergencyBrake(int *speed, int amount) {
    *speed = *speed - amount;
    if (*speed < 0) {
        *speed = 0;
    }
}

/* Bu fonksiyon dizideki her risk puanina ayni cezayi ekler. */
void addRiskPenalty(int scores[], int size, int penalty) {
    int i = 0;

    while (i < size) {
        scores[i] = scores[i] + penalty;
        i++;
    }
}

/* Bu fonksiyon risk puanlarini toplayip tek bir toplam deger dondurur. */
int totalRiskScore(const int scores[], int size) {
    int i = 0;
    int total = 0;

    while (i < size) {
        total = total + scores[i];
        i++;
    }

    return total;
}

/* Bu fonksiyon void pointer kullanarak farkli bisiklet tiplerini ekrana yazar. */
void printBikeReport(void *bike, int bikeType) {
    if (bikeType == 1) {
        /* city degiskeni, gelen adresin sehir bisikleti oldugunu varsayar. */
        CityBike *city = (CityBike *)bike;
        printf("Sehir Bisikleti: %s | Pil: %d | Hiz: %d\n",
               city->model,
               city->batteryLevel,
               city->currentSpeed);
    } else if (bikeType == 2) {
        /* cargo degiskeni, gelen adresin yuk bisikleti oldugunu varsayar. */
        CargoBike *cargo = (CargoBike *)bike;
        printf("Yuk Bisikleti: %s | Pil: %d | Hiz: %d | Yuk: %d\n",
               cargo->model,
               cargo->batteryLevel,
               cargo->currentSpeed,
               cargo->cargoWeight);
    }
}

/* Bu fonksiyon iki risk puanini karsilastirir. Kucuk olan daha guvenlidir. */
int compareSafetyScores(int scoreA, int scoreB) {
    if (scoreA < scoreB) {
        return 1;
    }

    return 2;
}

int main(void) {
    /* city: sehir bisikleti icin ornek veri tutar. */
    CityBike city = {"VeloCity", 72, 24, {3, 5, 4, 6}};
    /* cargo: yuk bisikleti icin ornek veri tutar. */
    CargoBike cargo = {"LoadRunner", 65, 18, 12, {6, 7, 5, 8}};

    printf("Otonom bisiklet guvenlik raporu baslatiliyor...\n\n");

    /* !!!*/
    setBatteryLevel(city.batteryLevel, 90);

    /* !!!*/
    applyEmergencyBrake(city.currentSpeed, 8);

    /* !!!*/
    addRiskPenalty(city.routeRiskScores[0], 4, 2);

    /* !!!*/
    int cityTotal = totalRiskScore(city.routeRiskScores[0], 4);

    /* !!!*/
    printBikeReport(&city, 2);

    /* !!!*/
    int saferBike = compareSafetyScores(&cityTotal, &cargo.routeRiskScores);

    /* !!!*/
    setBatteryLevel(cargo.batteryLevel, 80);

/* !!!*/
    addRiskPenalty(cargo.routeRiskScores, 3, -1);

    printBikeReport(&cargo, 2);

    printf("\nSehir bisikleti toplam risk skoru: %d\n", cityTotal);
    printf("Daha guvenli bisiklet kodu: %d\n", saferBike);

    return 0;
}
