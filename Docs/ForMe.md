## C++
- #pragma once →
- enum → 
- const → Değiştirilemez.
- std::string → Veri tipi (string/metin).
- & → Referans olarak al.
- message → Parametrenin (değişkenin) adı

## Git

- git add .
- git commit
- git commit -m "core: add logger with log level support"
- git push
- git status

## CMake

- cmake ..
- cmake --build .

add_definitions(-DUNICODE -D_UNICODE)
target_compile_definitions(MuytiEngine PRIVATE UNICODE _UNICODE)
## ortak

class Window
{
public:
    virtual bool Create() = 0;
    virtual void Update() = 0;
    virtual void Destroy() = 0;
};

Sonra

class WindowsWindow : public Window

diyoruz.

Bu cümlenin anlamı:

"WindowsWindow, Window'un verdiği kurallara uymak zorundadır."

## Virtual
Yani virtual kabaca:

"Bu fonksiyon alt sınıflar tarafından değiştirilebilir."

demektir.
- 
virtual bool Create() = 0;

0 döndürmek demek değildir.

false döndürmek de değildir.

Buradaki = 0 tamamen C++'a özel bir sözdizimidir.

Şunun anlamına gelir:

"Ben bu fonksiyonu burada yazmıyorum. Bunu yazmak zorundasın."
## üst sınıf
Window* window = new WindowsWindow();   = Windows Kütüphanesinden nesne oluşturuyoruz ama adresi WindowsWindow.

window->Create();  = Windowun tutuğu adresten createti çagır.

Delete window = ramde bir kere oluşturduktan sonra nesneyi siliyoreuz.

new ile ayırdığımız belleği işletim sistemine geri verir.

WindowsWindow tipinde bir nesne oluşturuyoruz.

Window değişkeni ise bu nesnenin adresini tutuyor.*

## windows.h
HWND

Yani kabaca:

"Windows'un oluşturduğu pencerenin kimliği (handle)."

Handle'ı şimdilik "Windows'un verdiği kimlik kartı" gibi düşünebilirsin.

## wchar_t
eski char sadece ingilizce harflerini destekliyordu bu yüzden wchar_t çıkarttı bu ise büttün dilleri destekliyor kullanımı char d = "salih" , wchar_t c = L"salih"

## LRESULT CALLBACK
LRESULT CALLBACK WindowProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam);

Bildirim (declaration). Derleyiciye bu fonksiyonun daha sonra tanımlanacağını söyler.

Bu satırın anlamı şudur:

"Merak etme derleyici, aşağıda WindowProc diye bir fonksiyon yazacağım."

Küçük bir benzetme

Diyelim ki sana diyorum:

"Yarın sana Ahmet'i tanıştıracağım."

Sen artık Ahmet'in var olduğunu biliyorsun.

Ama nasıl biri olduğunu bilmiyorsun.

Ertesi gün Ahmet geliyor.

## WindowProc
Penceremizin bizimle haberleşeceği fonksiyon mesela mouse pencerinin neresinde veya hangi pencerede(HNWD) olduğunu söyleyecek.

## Öğrendiğim En Önemli Şey
HWND = Pencerenin kimliği

Window* = Bizim C++ nesnemiz

WindowProc = Windows'un bizimle konuştuğu yer

HWND sayesinde doğru Window nesnesini bulabiliriz.

Windows bizim sınıflarımızı bilmez.

Windows sadece HWND bilir.

Biz ise HWND sayesinde kendi C++ nesnemizi buluruz.

## hInstance
hInstance nedir?

Windows'ta çalışan her programın bir instance'ı vardır.

Çok kabaca:

"Şu anda çalışan bu uygulama."

Windows diyor ki:

"Bu pencere hangi uygulamaya ait?"

Biz de cevap veriyoruz:

wc.hInstance = GetModuleHandle(nullptr);

Yani:

"Bu pencere şu anda çalışan uygulamaya ait."

## CreateWindowEx
Neden CreateWindowEx çıktı?

İlk Windows sürümlerinde sadece şunu vardı:

CreateWindow(...)

Sonra Microsoft dedi ki:

"Pencerelere yeni özellikler eklememiz gerekiyor."

Ama bir sorun vardı.

Eğer CreateWindow'ın parametrelerini değiştirirlerse...

1995'te yazılmış programlar çalışmazdı. 😬

Microsoft'un en önem verdiği şeylerden biri geriye dönük uyumluluk (backward compatibility)'dir.

Bu yüzden eski fonksiyonu bozmadılar.

Onun yerine:

CreateWindowEx(...)

çıktı.

Yani:

"Eski fonksiyon dursun, yeni özellik isteyen bunu kullansın."

Peki ilk parametre neden 0?

İlk parametrenin adı:

DWORD dwExStyle

Şimdi bunu parçalayalım.

DWORD → 32 bitlik sayı.
dw → Windows'un eski isimlendirme kuralı (double word).
ExStyle → Extended Style (Genişletilmiş stil).

Yani:

"Bu pencereye ekstra özellik istiyor musun?"

Biz şimdilik diyoruz ki:

0

Yani:

"Hayır. Standart pencere yeter."

İleride ne yazılabilir?

Mesela:

WS_EX_TOPMOST

Bu ne yapar?

Pencereyi her zaman en üstte tutar.

Örneğin Discord'un mini penceresi veya bazı video oynatıcıların "Always on Top" özelliği gibi.

Başka bir örnek:

WS_EX_LAYERED

Bu da pencereyi yarı saydam yapmana izin verir.

Yani ilk parametre aslında:

"Bu pencerenin ekstra güçleri var mı?"

Bizim cevabımız:

0

Çünkü daha yolun başındayız.

## createwindowex 2
Şu an CreateWindowEx'imiz şu durumda:

m_Window = CreateWindowEx(
    0,
    L"MuytiWindow",
    L"Muyti Engine",
    WS_OVERLAPPEDWINDOW,
    CW_USEDEFAULT,
    CW_USEDEFAULT,
    1280,
    720,

Buraya kadar tamam.

Şimdi kalan parametreleri ekleyelim.

    nullptr,
    nullptr,
    wc.hInstance,
    nullptr
);

Şimdi tek tek bakalım.

- 1
nullptr,

Bu Parent Window.

Sana soru:

Bir uygulamanın içinde başka bir pencerenin içine gömülü pencere gördün mü?

Mesela:

Dosya Aç penceresi
Material Editor
Inspector
Content Browser

Bazen bunlar ana pencerenin içinde yaşarlar.

Bizim şu an oluşturduğumuz pencere ise:

Ana pencere.

Bu yüzden parent'ı yok.

O yüzden

nullptr
- 2
nullptr,

Bu ise Menü.

Eskiden Windows uygulamalarında yukarıda şunlar olurdu.

File
Edit
View
Help

Bizim şimdilik menümüz yok.

O yüzden yine

nullptr
- 3
wc.hInstance,

Bunu zaten biraz önce doldurmuştuk.

Windows diyor ki:

"Bu pencere hangi uygulamaya ait?"

Biz de:

"Şu uygulamaya."

diyoruz.

- 4
nullptr

Bu ise:

Application'a başlangıçta göndermek istediğin özel veri.

Şimdilik yok.