Sınav oturma düzeni:

L-19 A GRUBU: 10:30-12:00

R-19 B GRUBU: 10:30-12:00

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


# TEK SORU (80 dk.) Çarpma ve Bölme Operatörü Kullanmadan Kombinasyon Hesabı

Kombinasyon hesabını (`C(n,r)`) çarpma (`*`) ve bölme (`/`) operatörlerini kullanmadan, yalnızca toplama (`+`), çıkarma (`-`) ve `while` döngüsü kullanarak hesaplayan bir C programı yazmanız beklenmektedir.

Program içerisinde `n` ve `r` adlı iki tamsayı değişkeni tanımlayınız ve bu değişkenlere kod içerisinde değer atayınız.

Program, aşağıdaki kombinasyon değerini hesaplamalıdır:

```text
C(n,r) = n(n-1)(n-2)...(n-r+1) / r!
```

Kısıtlar
 * (çarpma) operatörü kullanılmayacaktır
 / (bölme) operatörü kullanılmayacaktır
 % (mod) operatörü kullanılmayacaktır

Sadece:
 + (toplama)
 - (çıkarma)
 while döngüsü
kullanılacaktır

`scanf` kullanılmayacaktır. Negatif değerler ve özel durumlar dikkate alınmayacaktır

Pay kısmını hesapla:
n × r = n + n + n + ... (r kez)

Payda kısmını hesapla:
r! 
temp = r x (r-1) = r + r + r + .... (r-1 kez) 
temp = temp x (r-2) = temp + temp + temp + .... (r-2 kez)
temp = temp x (r-3) = temp + temp + .... (r-3 kez)
....
temp = temp x (r-m) = temp + temp (2 kez)
payda = temp

Payı, paydaya bölme işlemini çıkarma ile hesapla:

Örnek 1
```text
n = 7
r = 4

İşlem:

7 × 6 × 5 × 4 = 840 (toplayarak)
4! = 24 (toplayarak)
840 / 24 = 35 (çıkararak)

Çıktı:
35 veya daha okunaklı C(7,4) = 35
```
Örnek 2
```text
n = 5
r = 2

İşlem:

5 × 4 = 20 (toplayarak)
2! = 2 (toplayarak)
20 / 2 = 10 (çıkararak)

Çıktı:

10 veya daha okunaklı C(5,2) = 10
```
Örnek 3
```text
n = 6
r = 3

İşlem:

6 × 5 × 4 = 120 (toplayarak)
3! = 6 (toplayarak)
120 / 6 = 20 (çıkararak)

Çıktı:

20 veya daha okunaklı C(6,3) = 20
```

Çözüm:

```c
#include <stdio.h>

int main()
{
    int n = 7;
    int r = 4;

    int pay = 1;
    int payda = 1;
    int sonuc = 0;

    int i, j;
    int temp;

    //-----------------------------carpma (pay hesaplama)-----------------------------
    i = 0;
    while (i < r)
    {
        temp = 0;
        j = 0;

        while (j < (n - i))
        {
            temp = temp + pay;
            j = j + 1;
        }

        pay = temp;
        i = i + 1;
    }

    //-----------------------------carpma (faktoriyel hesaplama)-----------------------
    payda = 1;
    i = r;

    while (i > 1)
    {
        temp = 0;
        j = 0;

        while (j < i)
        {
            temp = temp + payda;
            j = j + 1;
        }

        payda = temp;
        i = i - 1;
    }

    //-----------------------------bolme (cikarma ile)--------------------------------
    temp = pay;

    while (temp >= payda)
    {
        temp = temp - payda;
        sonuc = sonuc + 1;
    }

    //-----------------------------sonuc----------------------------------------------
    printf("C(%d,%d) = %d\n", n, r, sonuc);

    return 0;
}
```
