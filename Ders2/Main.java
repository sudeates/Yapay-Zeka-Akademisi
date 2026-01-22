public class Main {
    public static void main(String[] args) {
        System.out.println("Merhaba Java!");
        int ogrenciSayisi = 50;
        double faizOrani = 0.12;
        char cevap = 'E';
        boolean gectiMi = true;

        int maas;        // Tanımlama
        maas = 5000;     // Değer atama
        int yas = 25;    // Hem tanımlama hem atama

        //FINAL değişkenler
        final double PI = 3.14159;
        final int HAFTANIN_GUNLERI = 7;
        // PI = 3.15; // HATA! Final değişken değiştirilemez.

        // 100 elemanlı boş bir tamsayı dizisi oluşturma
        int[] sayilar = new int[100]; 
        // Tanımlarken değer atama
        double[] notlar = {10.5, 50.0, 75.5};
        // Erişme
        sayilar[0] = 5; // İlk elemana değer ata
        System.out.println(notlar[1]); // Ekrana 50.0 yazar

        String selamlama = "Merhaba Dünya";
        // String aslında bir sınıftır, ilkel tip değildir.
    }   
}