Sınav oturma düzeni:

L-19 B GRUBU:    10:30-12:00    

R-19 C GRUBU:    10:30-12:00   

Sınav Kuralları:

 1. Sınava salonuna telefon/akıllı saat/iletişim aracı getirmek yasaktır. Mecburi getirenler hoca masasına bırakmalıdırlar.

 2. Sınavda herkes kendi monitörüne odaklanmalıdır. Kendisini ve arkadaşını itham altında bırakacak hareketler yapmamalıdır.

 3. Sınava, kişisel bilgisayarı olanların getirmesi rica edilir. Sınav başlamadan ekranlarını gözetmenlere teyit ettirmelidirler (Windows + Tab). 

 4. Kişisel bilgisayarı olanlar sınav esnasında sadece notepad++(https://notepad-plus-plus.org/downloads/) gibi basit editörler kullanmalıdırlar. VS Code vb. yapay zeka entegre edilen araçlar kullanılmamalıdır. Sınavdan önce bilgisayarınıza gerekli kurulumu yapınız. Görevliye editörünüzü gösteriniz.

 5. Sınava hazırlık için masaüstünde `main.c` dosyasını oluşturup, derleyip "merhaba dunya" yazdırıp. Sınavın başlaması beklenmelidir.

 7. Masaüstüne VSCode WSL Terminalden gitmek için:

  ```bash
  cd /mnt/c/Users/Vagrant/Desktop
  touch main.c
  gcc -o main main.c
```

 8. Sınavdan sonra kamera görüntüleri incelenecektir. Sınav esnasında görülmeyen şüpheli hususlar, sınavdan sonra da değerlendirilebilir.

---


# SORU 1 - 20 dk.

Program içinde `n` adlı bir tamsayı değişkeni tanımlayıp bu değişkene bir değer atayınız. 1'den `n`'e kadar olan pozitif sayıları `while` döngüsü kullanarak toplayan ve sonucu ekrana yazdıran C programını yazınız. `scanf` kullanmayınız.

Örneğin:

```c
n = 4 için
4 + 3 + 2 + 1 = 10 
Ekrana 10 yazdırmalıdır.
```

```c
n = 11 için
11 + 10 + 9 + 8 + 7 + 6 + 5 + 4 + 3 + 2 + 1 = 66
Ekrana 66 yazdırmalıdır.
```

Çözüm:

```c
#include <stdio.h>

int main() {
    int n = 4;   // atanacak deger
    int toplam = 0;

    while (n > 0) {
        toplam = toplam + n;
        n = n - 1;
    }

    printf("Toplam: %d\n", toplam);

    return 0;
}
```

# SORU 2 - 60 dk.

Program içinde `taban` ve `us` adlı iki tamsayı değişkeni tanımlayıp bu değişkenlere kod içerisinde değerler atayınız. `taban` sayısının `us` kuvvetini, çarpma operatörü kullanmadan, yalnızca toplama işlemi ve `while` döngüsü kullanarak hesaplayan `C` programını yazınız. `scanf` kullanmayınız. Negatif değerler gibi istisna durumları dikkate almayınız.

Örneğin:
```c
taban=10  us=3 için
10 * 10 * 10 = 1000
Ekrana 1000 yazdırmalıdır.
```

```c
taban=7  us=2 için
7 * 7 = 49
Ekrana 49 yazdırmalıdır.
```

```c
taban=2  us=10 için
2 * 2 * 2 * 2 * 2 * 2 * 2 * 2 * 2 * 2 = 1024
Ekrana 1024 yazdırmalıdır.
```

Çözüm:
```c
#include <stdio.h>

int main() {
    int taban = 10;
    int us = 3;

    int sonuc = 1;
    int i = 0;

    while (i < us) {
        int temp = 0;
        int j = 0;

        // sonuc * taban işlemini toplama ile yap
        while (j < taban) {
            temp = temp + sonuc;
            j = j + 1;
        }

        sonuc = temp;
        i = i + 1;
    }

    printf("Sonuc: %d\n", sonuc);

    return 0;
}
```

İPUCU:

Örneğin 3 * 4 işleminde (taban=3, us=4):

1. Adım 3 + 3 + 3  (3 tane 3' ün toplamı) = 9
   
2. Adım 9 + 9 + 9 (3 tane 9' un toplamı) = 27
   
4. Adım 27 + 27 + 27 (3 tane 27' nin toplamı) = 81
   
us en dıştaki döngü sayısını belirlemektedir. İçteki çarpma işlemini toplama operatörü ile yapan döngüde ise toplanacak sayı değeri değişmektedir.
