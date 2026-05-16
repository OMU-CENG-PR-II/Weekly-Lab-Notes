Sınav oturma düzeni:

L-19 C GRUBU:    9:00-10:30    

R-19 D GRUBU:    9:00-10:30    

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
  code .
  gcc -o main main.c
```

 8. Sınavdan sonra kamera görüntüleri incelenecektir. Sınav esnasında görülmeyen şüpheli hususlar, sınavdan sonra da değerlendirilebilir.

---


# SORU 1 - 20 dk.

Bir sayının kendisinden küçük tüm pozitif sayılara bölümünden kalan değerlerini hesaplayan bir C programı yazmanız beklenmektedir. Programda bölme (`/`) ve mod (`%`) operatörleri kullanılmadan, yalnızca çıkarma işlemi ile kalan hesaplanacaktır.


Program içerisinde bir `n` tam sayısı atanacaktır (`scanf` kullanmayınız).

Program, `n` sayısını kendisinden küçük tüm pozitif sayılara (n-1, n-2, ..., 1) bölecek ve her bir bölüm işleminden kalan değeri ekrana yazdıracaktır.


Kısıtlar

- `%` (mod) operatörü **kullanılmayacaktır**
- `/` (bölme) operatörü **kullanılmayacaktır**
- Kalan hesabı yalnızca:
  - `-` (çıkarma)
  - `while` döngüsü (`for` döngüsü kullanmayınız)
    
  kullanılarak yapılacaktır


İpucu

Bir sayının başka bir sayıya bölümünden kalanı bulmak için:

```text
Büyük sayıdan küçük sayı, sonuç küçük sayıdan küçük olana kadar çıkarılır.
Kalan değer son elde edilen sayıdır.
```

Örneğin:
```text
n=8 için, ekrana satır satır
7:1
6:2
5:3
4:0
3:2
2:0
```

```text
n=12 için, ekrana satır satır
11:1
10:2
9:3
8:4
7:5
6:0
5:2
4:0
3:0
2:0
```

Çözüm:
```c
#include <stdio.h>

int main() {
    int n = 22;
    int i;
    int kalan;

    i = n - 1;   // n-1'den basla

    while (i > 0) {
        kalan = n;   // her seferinde n'i tekrar kullan

        // kalan hesaplama
        while (kalan >= i) {
            kalan = kalan - i;
        }

        printf("%d:%d\n", i, kalan);

        i = i - 1;  // bir azalt
    }

    return 0;
}
```


# SORU 2 - (60 dk.) Çarpma ve Bölme Kullanmadan Karekök Hesabı

Bir pozitif tam `s` sayının karekökünü hesaplayan C programını yazınız.

Kısıtlar:

Çarpma (*) ve bölme (/) operatörleri kullanılmayacaktır.
Sadece çıkarma (-) ve while döngüsü kullanılacaktır.
Program karekökün sadece tam kısmını hesaplayacaktır.

Açıklama:
Ardışık tek sayıların toplamı kullanılarak karekök bulunabilir. Program, sayıyı sırasıyla `1`, `3`, `5`, `7`, `...` gibi tek sayılarla azaltır.
Kaç adımda sıfıra (veya sıfırın altına) yaklaşıldığı sayılır.

Bu adım sayısı, sayının karekökünün tam kısmını verir.

Örnek 1
```text
s = 16

Yapılacak işlem:

16 - 1 = 15
15 - 3 = 12
12 - 5 = 7
7 - 7 = 0

Sonuç 0' a ulaştı. Adım sayısı 4.

Çıktı:
Karekoku: 4

```

Örnek 2
```text
s = 20

Yapılacak işlem:

20 - 1 = 19
19 - 3 = 16
16 - 5 = 11
11 - 7 = 4
4 - 9 → Sonuç negatif islem durur

Kalan 0' dan farklı çıktı. Adım sayısı 4.

Çıktı:
Karekoku: ~4
```

Örnek 3
```text
s = 25

Yapılacak işlem:

25 - 1 = 24
24 - 3 = 21
21 - 5 = 16
16 - 7 = 9
9  - 9 = 0

Sonuç 0' a ulaştı. Adım sayısı 5

Çıktı:
Karekoku: 5
```

Çözüm
```c
#include <stdio.h>

int main() {
    int s=81;
    int tek = 1;
    int karekok = 0;

    while (s >= tek) {
        s = s - tek;          // siradaki tek sayiyi cikar
        tek = tek - (-2);     // tek sayiyi 2 arttir ( + kullanmadan )
        karekok = karekok - (-1); // karekok sayacini 1 arttir
    }

    printf("Karekoku: %d\n", karekok);

    return 0;
}
```
