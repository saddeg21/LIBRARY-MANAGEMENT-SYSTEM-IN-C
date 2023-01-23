# LIBRARY-MANAGEMENT-SYSTEM-IN-C
It is a structural progrraming project for C language which focuses on dynamic memory allocation and structs.

The project has given with five pre-defined structs and some rules.

> STRUCTS
o struct Ogrenci { char ogrID[8]; char ad[30]; char soyad[30]; int puan; struct Ogrenci *next; struct Ogrenci *prev}
o struct Yazar { int yazarID; char yazarAd[30]; char yazarSoyad[30]; struct Yazar *next}
o struct KitapOrnek { char EtiketNo[20]; char Durum[8]; struct KitapOrnek *next }
o struct Kitap {char kitapAdı[30]; char ISBN[13]; int adet; struct Kitap *next; struct KitapOrnek *head }
o struct KitapYazar{ char ISBN[13]; int YazarID}
o struct Tarih{ int gun:5; int ay:4; int yil:12}
o struct KitapOdunc{ char EtiketNo[20]; char ogrID[8]; int islemTipi:1; struct Tarih islemTarihi}

> RULES
❖ Yukarıdaki maddelerde verilen bir menü ve her bir işlem için gerekli fonksiyonları tasarlayınız. Benzer mantıkla çalışan 
fonksiyonlarda tekrardan kaçınmak için fonksiyon pointer kullanınız.
❖ Yapılması gereken tüm ekle, sil ve güncelleme işlemler için fonksiyon tanımlamanız gerekmektedir. 
❖ Ekle, Sil, Güncelle gibi veri üzerinde değişiklik yapılan işlemleri ilgili veri yapısında yaptıktan sonra dosyaya mutlaka 
kaydediniz. 
❖ Programlarınızda static ve global değişken kullanımı yasaktır. 
❖ Her türlü bellek tahsisi, dinamik bellek yönetimi fonksiyonları ile yapılmalıdır.
❖ Yukarıda detayları verilen her bir dosyadaki nesne için uygun structure tanımlamalarını yapınız.
❖ Oluşturulacak dosyalar CSV dosyası formatında olmalıdır.

## CONTENTS OF THE PROJECT
IT basically has three property which are students,authors and books.
We have some functions and created linked lists for providing those functionalities. Every property has their own special functions and we can access them via GUI.

- Graphical User Interface is designed for command prompt.
