public class Exercise2{
    public static void main(String[] args) {
        String ad = "Ali";
        String tamAd = "Merhaba " + ad + "!"; // "Merhaba Ali!" olur.
        System.out.println("Cevap: " + 42); // Sayıyı otomatik metne çevirir.
        int not = 75;
        // Not 0 ile 100 arasında mı?
        boolean gecerliMi = (not >= 0) && (not <= 100);

        int sicaklik = 25;
        if (sicaklik > 30) {
            System.out.println("Hava çok sıcak.");
        } else if (sicaklik > 20) {
            System.out.println("Hava güzel.");
        } else {
            System.out.println("Hava soğuk.");
        }

        int gun = 2;
        switch (gun) {
            case 1: System.out.println("Pazartesi"); break;
            case 2: System.out.println("Salı"); break; // Burası çalışır
            default: System.out.println("Haftasonu");
        }

        // 0'dan 4'e kadar yazdır (0, 1, 2, 3, 4)
        for (int i = 0; i < 5; i++) {
            System.out.println("Sayı: " + i);
        }

        // Diziyi gezmek için (Enhanced For Loop)
        String[] isimler = {"Ali", "Veli"};
        for (String isim : isimler) {
            System.out.println(isim);
        }
        int sayac = 0;
        while (sayac < 3) {
            System.out.println("Sayaç: " + sayac);
            sayac++; // Bunu unutursanız sonsuz döngü olur!
        }
    }
}