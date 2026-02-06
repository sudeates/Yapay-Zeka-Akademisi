public class MergeSort {

    // İki alt diziyi birleştiren (merge) metot
    void merge(int arr[], int l, int m, int r) {
        // İki alt dizinin boyutlarını bul
        int n1 = m - l + 1;
        int n2 = r - m;

        // Geçici dizileri oluştur
        int L[] = new int[n1];
        int R[] = new int[n2];

        // Verileri geçici dizilere kopyala
        for (int i = 0; i < n1; ++i)
            L[i] = arr[l + i];
        for (int j = 0; j < n2; ++j)
            R[j] = arr[m + 1 + j];

        // Geçici dizileri birleştir
        int i = 0, j = 0;
        int k = l; // Ana dizinin başlangıç indisi

        while (i < n1 && j < n2) {
            if (L[i] <= R[j]) {
                arr[k] = L[i];
                i++;
            } else {
                arr[k] = R[j];
                j++;
            }
            k++;
        }

        // Sol dizide kalan elemanları kopyala
        while (i < n1) {
            arr[k] = L[i];
            i++;
            k++;
        }

        // Sağ dizide kalan elemanları kopyala
        while (j < n2) {
            arr[k] = R[j];
            j++;
            k++;
        }
    }

    // Ana sıralama fonksiyonu
    void sort(int arr[], int l, int r) {
        if (l < r) {
            // Orta noktayı bul
            int m = l + (r - l) / 2;

            // İlk ve ikinci yarıları sırala
            sort(arr, l, m);
            sort(arr, m + 1, r);

            // Sıralı yarıları birleştir
            merge(arr, l, m, r);
        }
    }

    // Diziyi yazdırmak için yardımcı metot
    static void printArray(int arr[]) {
        int n = arr.length;
        for (int i = 0; i < n; ++i)
            System.out.print(arr[i] + " ");
        System.out.println();
    }

    public static void main(String args[]) {
        int arr[] = {12, 11, 13, 5, 6, 7};

        System.out.println("Verilen Dizi:");
        printArray(arr);

        MergeSort ob = new MergeSort();
        ob.sort(arr, 0, arr.length - 1);

        System.out.println("\nSıralanmış Dizi:");
        printArray(arr);
    }
}