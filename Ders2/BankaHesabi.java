// 1. SINIF TANIMI (Taslak)
class BankaHesabi {
    
    // --- FIELDS (Özellikler) ---
    
    // PUBLIC: Herkes erişebilir (Genellikle isim gibi risksiz veriler)
    public String hesapSahibi;
    
    // PRIVATE: Sadece bu sınıf erişebilir (KAPSÜLLEME - Encapsulation)
    // Bakiyeyi dışarıdan kafalarına göre değiştiremesinler diye gizliyoruz.
    private double bakiye;
    
    // STATIC: Sınıfa aittir, nesneye değil. Tüm hesaplar bu sayacı ortak kullanır.
    public static int toplamHesapSayisi = 0;

    // --- CONSTRUCTOR (Yapıcı Metot) ---
    // Nesne ilk oluşturulduğunda (new dendiğinde) çalışır.
    public BankaHesabi(String hesapSahibi, double baslangicBakiyesi) {
        this.hesapSahibi = hesapSahibi; // 'this' karışıklığı önler
        
        // Başlangıç bakiyesi negatif olamaz, kontrol ediyoruz
        if (baslangicBakiyesi >= 0) {
            this.bakiye = baslangicBakiyesi;
        } else {
            this.bakiye = 0;
            System.out.println("Hata: Bakiye negatif olamaz, 0 olarak ayarlandı.");
        }
        
        // Her yeni hesap açıldığında bankadaki toplam hesap sayısını artırıyoruz
        toplamHesapSayisi++;
    }

    // --- METOTLAR (Davranışlar) ---

    // Para Yatırma
    public void paraYatir(double miktar) {
        if (miktar > 0) {
            bakiye += miktar;
            System.out.println(hesapSahibi + " hesabına " + miktar + " TL yatırıldı.");
        }
    }

    // Para Çekme (Kapsülleme sayesinde kontrol yapıyoruz)
    public void paraCek(double miktar) {
        if (miktar > bakiye) {
            System.out.println("Hata: Yetersiz bakiye! (Mevcut: " + bakiye + " TL)");
        } else {
            bakiye -= miktar;
            System.out.println(hesapSahibi + " hesabından " + miktar + " TL çekildi.");
        }
    }

    // GETTER Metodu: Private olan bakiyeyi sadece okumaları için dışarı açıyoruz
    public double bakiyeSorgula() {
        return bakiye;
    }
}

// 2. MAIN CLASS (Programın Çalıştığı Yer)
class Main{
    public static void main(String[] args) {
        
        // Static değişkene nesne oluşturmadan erişebiliriz
        System.out.println("Başlangıçta Toplam Hesap: " + BankaHesabi.toplamHesapSayisi);

        // --- NESNE OLUŞTURMA ---
        
        // 1. Müşteri: Ali (1000 TL ile açıyor)
        BankaHesabi hesap1 = new BankaHesabi("Ali Yılmaz", 1000);
        
        // 2. Müşteri: Ayşe (5000 TL ile açıyor)
        BankaHesabi hesap2 = new BankaHesabi("Ayşe Demir", 5000);

        // --- İŞLEMLER ---
        
        hesap1.paraYatir(500);       // Ali para yatırdı. Yeni bakiye: 1500
        hesap1.paraCek(2000);        // Ali 2000 çekmek istedi -> HATA verecek (Yetersiz Bakiye)
        
        hesap2.paraCek(1000);        // Ayşe para çekti. Yeni bakiye: 4000
        
        // --- SONUÇLARI GÖRME ---
        
        // hesap1.bakiye = 99999; // HATA! Yapamayız çünkü 'bakiye' private (gizli).
        
        System.out.println("Ali'nin Son Bakiyesi: " + hesap1.bakiyeSorgula() + " TL");
        System.out.println("Ayşe'nin Son Bakiyesi: " + hesap2.bakiyeSorgula() + " TL");
        
        // Static sayaç otomatik arttı
        System.out.println("Bankadaki Toplam Hesap Sayısı: " + BankaHesabi.toplamHesapSayisi);
    }
}