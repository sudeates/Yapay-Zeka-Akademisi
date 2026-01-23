#include <iostream>
#include <vector>
#include <queue> // BFS için gerekli
using namespace std;

/*
 ============================================================================
 BÖLÜM 1: ALGORİTMA ANALİZİ (BIG O NOTATION)
 ============================================================================
 Amaç: Kodun hızını saniye cinsinden değil, işlem adımı cinsinden ölçmek.
 
 O(1)   -> Sabit Zaman: Girdi ne olursa olsun süre değişmez. (Örn: Dizi[0])
 O(N)   -> Lineer Zaman: Girdi arttıkça süre artar. (Örn: For döngüsü)
 O(N^2) -> Karesel Zaman: İç içe iki döngü. (Örn: Bubble Sort)
 O(logN)-> Logaritmik: Her adımda veri yarıya iner. (Örn: Binary Search)
 */


/*
 ============================================================================
 BÖLÜM 2: STRUCTS (YAPILAR)
 ============================================================================
 Diziler sadece aynı tip veriyi tutar (int array). 
 Farklı tipleri bir arada tutmak için 'struct' kullanılır.
 */
struct Ogrenci {
    int okulNo;      // 4 byte
    string isim;     // 24+ byte
    double ortalama; // 8 byte
}; 
// Not: Class'tan farkı, varsayılan olarak her şeyin 'public' olmasıdır.


/*
 ============================================================================
 BÖLÜM 3: LINKED LISTS (BAĞLI LİSTELER)
 ============================================================================
 Sorun: Dizilerin boyutu sabittir (int a[100]). Dolunca patlar.
 Çözüm: Veriler bellekte dağınık durabilir, birbirlerini işaret ederler.
 */

// Düğüm (Node) Yapısı
struct Node {
    int data;       // Veri
    Node* next;     // Bir sonraki düğümün adresi (Pointer)
};

class BagliListe {
    Node* head; // Listenin başını tutan pointer

public:
    BagliListe() { head = NULL; }

    // BAŞA EKLEME (Push)
    // Karmaşıklık: O(1) - Çok Hızlı (Kaydırma yok, sadece pointer değişimi)
    void basaEkle(int veri) {
        Node* yeni = new Node();
        yeni->data = veri;
        yeni->next = head; // 1. Yeni düğüm eski başı göstersin
        head = yeni;       // 2. Artık baş sensin
    }

    // SONA EKLEME (Append)
    // Karmaşıklık: O(N) - Yavaş (Sona kadar yürümek zorundayız)
    void sonaEkle(int veri) {
        Node* yeni = new Node();
        yeni->data = veri;
        yeni->next = NULL;

        if (head == NULL) {
            head = yeni;
            return;
        }

        // Sona kadar yürü
        Node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = yeni; // Sonuncunun next'ine bağla
    }

    // LİSTEYİ GEZME (Traversal)
    // Karmaşıklık: O(N)
    void yazdir() {
        Node* temp = head;
        while (temp != NULL) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
};


/*
 ============================================================================
 BÖLÜM 4: STACK (YIĞIN)
 ============================================================================
 Mantık: LIFO (Last In First Out) - Son giren ilk çıkar.
 Örnek: Üst üste dizilmiş tabaklar, Tarayıcı "Geri" butonu.
 */
class Stack {
    int dizi[100];
    int top; // En üstteki elemanın indeksi

public:
    Stack() { top = -1; } // Başlangıçta boş

    // Ekleme O(1)
    void push(int x) {
        if (top >= 99) { cout << "Stack dolu!"; return; }
        dizi[++top] = x; // İndeksi artır ve ekle
    }

    // Çıkarma O(1)
    int pop() {
        if (top < 0) { cout << "Stack boş!"; return -1; }
        return dizi[top--]; // Değeri ver ve indeksi azalt
    }
};


/*
 ============================================================================
 BÖLÜM 5: QUEUE (KUYRUK)
 ============================================================================
 Mantık: FIFO (First In First Out) - İlk giren ilk çıkar.
 Örnek: Yazıcı sırası, Ekmek kuyruğu.
 
 Kritik Nokta: Dairesel Kuyruk (Circular Queue)
 Düz dizide eleman çıkardıkça baş taraf boşalır ama kullanamayız.
 Modüler aritmetik (%) ile diziyi halka haline getiririz.
 Formül: rear = (rear + 1) % boyut
 */


/*
 ============================================================================
 BÖLÜM 6: GRAFLAR (GRAPHS) & ARAMA ALGORİTMALARI
 ============================================================================
 Yapı: Düğümler (Vertices) ve Kenarlar (Edges).
 Tutma Yöntemi: Adjacency List (Komşuluk Listesi).
 */

// Global değişkenler (Basitlik için)
vector<int> adj[100];    // Her düğümün komşularını tutan liste
bool visited[100];       // Gidilen yerleri işaretlemek için

// Düğüm Ekleme
void kenarEkle(int u, int v) {
    adj[u].push_back(v); // u'nun komşusu v'dir
    adj[v].push_back(u); // v'nin komşusu u'dur (Yönsüz graf)
}

// ALGORİTMA 1: DFS (Depth First Search - Derinlemesine Arama)
// Mantık: Bir yola gir ve sonuna kadar git (Stack mantığı/Recursion).
// Kullanım: Labirent çözme.
void DFS(int u) {
    visited[u] = true;       // 1. Ziyaret ettim
    cout << u << " ";        // 2. İşlemi yap

    // 3. Komşulara bak
    for (int v : adj[u]) {
        if (!visited[v]) {   // Gitmediysem
            DFS(v);          // Oraya dal (Recursion)
        }
    }
}

// ALGORİTMA 2: BFS (Breadth First Search - Genişlemesine Arama)
// Mantık: Halka halka yayıl. Önce en yakınlar. (Queue mantığı).
// Kullanım: En kısa yol (Shortest Path).
void BFS(int baslangic) {
    queue<int> q;
    
    // Temizlik (Visited dizisini sıfırla)
    for(int i=0; i<100; i++) visited[i] = false;

    // 1. Başlangıcı kuyruğa at
    q.push(baslangic);
    visited[baslangic] = true;

    while (!q.empty()) {
        int u = q.front(); // Sıradakini al
        q.pop();
        cout << u << " ";

        // Komşuları sıraya ekle
        for (int v : adj[u]) {
            if (!visited[v]) {
                visited[v] = true;
                q.push(v);
            }
        }
    }
}

/*
 ============================================================================
 MAIN (TEST ALANI)
 ============================================================================
 */
int main() {
    // 1. Linked List Test
    cout << "--- Linked List ---" << endl;
    BagliListe liste;
    liste.basaEkle(10); // 10
    liste.basaEkle(20); // 20 -> 10
    liste.sonaEkle(30); // 20 -> 10 -> 30
    liste.yazdir();

    // 2. Graph Test
    cout << "\n--- Graph DFS/BFS ---" << endl;
    // Grafı Oluştur (0-1, 0-2, 1-3 şeklinde bağlı)
    kenarEkle(0, 1);
    kenarEkle(0, 2);
    kenarEkle(1, 3);
    
    cout << "DFS (Derinlemesine): ";
    // visited dizisini sıfırla
    for(int i=0; i<100; i++) visited[i] = false;
    DFS(0); // Çıktı: 0 1 3 2 (Sıra değişebilir)

    cout << "\nBFS (Genişlemesine): ";
    BFS(0); // Çıktı: 0 1 2 3 (Katman katman)

    return 0;
}