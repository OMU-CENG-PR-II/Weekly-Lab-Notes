Sınav oturma düzeni:

L-19 D GRUBU:    9:00-10:30    

R-19 A GRUBU:    9:00-10:30    

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

Program içinde `fakt` ve `adim` adlı iki tamsayı değişkeni tanımlayıp bu değişkenlere kod içerisinde değer atayınız. `fakt` değerinden başlayarak geriye doğru `adim` kadar sayının çarpımını, çarpma operatörü kullanmadan, yalnızca toplama işlemi ve `while` döngüsü kullanarak hesaplayan `C` programını yazınız. `scanf` kullanmayınız. Negatif değerler, sıfır gibi istisna durumları dikkate almayınız.

Örneğin:
```c
fakt=10  adim=3 için
10 * 9 * 8 = 720
Ekrana 720 yazdırmalıdır.
```

```c
fakt=7  adim=2 için
7 * 6 = 42
Ekrana 42 yazdırmalıdır.
```

```c
fakt=5  adim=4 için
5 * 4 * 3 * 2 = 120
Ekrana 120 yazdırmalıdır.
```

```c
fakt=11  adim=3 için
11 * 10 * 9 = 990
Ekrana 990 yazdırmalıdır.
```

Normal faktoriyel hesabı girilen sayıdan 1' e kadar geri giderken; burada belirlenen adım kadar geri gitmelidir.

Çözüm:
```c
#include <stdio.h>

int main() {
    int fakt = 10;
    int adim = 3;

    int sonuc = 1;
    int i = 0;

    while (i < adim) {
        int sayi = fakt - i;   // 10, 9, 8 ...
        int temp = 0;
        int j = 0;

        // sonuc * sayi işlemini toplama ile yap
        while (j < sayi) {
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

Programınızda her çarpma işlemini gerçekleştirmek için içeride bir toplama döngüsü kurmanız gerekecek. Ayrıca sonuç ilk başta 1 olmalı ve fakt değerinden başlayarak her adımda bir azaltarak (10, 9, 8 ...) sonucu o sayı ile çarpıyormuş gibi güncellemelisiniz. Yani dış döngü kaç sayı çarpılacağını, iç döngü ise çarpmanın yerine yapılan tekrarlı toplamayı kontrol edecektir.
