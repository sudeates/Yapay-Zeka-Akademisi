public class Methods {

    // Main Metodu: Programın başladığı yer
    public static void main(String[] args) {
        // Metodu burada ÇAĞIRIYORUZ (Kullanıyoruz)
        System.out.println(aralikTopla(1, 10));  
        System.out.println(aralikTopla(20, 30)); 
    }

    // Yardımcı Metot: Main'in DIŞINDA tanımlanmalı
    public static int aralikTopla(int baslangic, int bitis) {
        int toplam = 0;
        for (int i = baslangic; i <= bitis; i++) {
            toplam += i;
        }
        return toplam;
    }
    
}