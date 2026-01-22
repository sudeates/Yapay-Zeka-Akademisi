public class Arrays {
    public static void main(String[] args){
        int[] sayılar={10,20,30,40,50};
        int toplam=0;
        for(int i=0;i<sayılar.length;i++){
            toplam+=sayılar[i];
        }
        int max=sayılar[0];
        for(int i=1;i<sayılar.length;i++){
            if(sayılar[i]>max){
                max=sayılar[i];
            }
        }
    }
}
