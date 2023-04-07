#include <stdio.h>
#include <stdlib.h>

//En buyuk adayi bulan fonksiyon
int max_ada(int **mat, int m, int n) {
    int max_ada_boyut = 0;
    
    //Matrisi incele
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (mat[i][j] == 1) {
                //Adayi bulduysak boyutunu hesapla
                int ada_boyut = 0;
                
                //Dfs kullanarak adalari gez
                void dfs(int x, int y) {
                    //Su anki eleman ada degilse veya matrisin sinirlarinin disindaysa geri don
                    if (x < 0 || x >= m || y < 0 || y >= n || mat[x][y] == 0) {
                        return;
                    }
                    
                    //Gezilmis elemanlari isaretle
                    mat[x][y] = 0;
                    ada_boyut++;
                    
                    //Yanlardaki elemanlari gez
                    dfs(x+1, y);
                    dfs(x-1, y);
                    dfs(x, y+1);
                    dfs(x, y-1);
                }
                
                dfs(i, j);
                
                //Gerekiyorsa en buyuk ada boyutunu guncelle
                if (ada_boyut > max_ada_boyut) {
                    max_ada_boyut = ada_boyut;
                }
            }
        }
    }
    
    return max_ada_boyut;
}

int main(int argc, char *argv[]) {
    int n, m;
    printf("Satir sayisini giriniz: ");
    scanf("%d", &n);
    printf("Sutun sayisini giriniz: ");
    scanf("%d", &m);
    //Matrisin boyutlarini kullanicidan al
    
    //Matris icin bellek ayarla
    int **mat = (int **)malloc(m * sizeof(int *));
    for (int i = 0; i < m; i++) {
        mat[i] = (int *)malloc(n * sizeof(int));
    }
    
    //Matrisin degerlerini al
    printf("Matrisin elemanlarini girin (0 veya 1): \n");
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &mat[i][j]);
        }
    }
    
    //En buyuk ada boyutunu bul
    int adamaxboyut = max_ada(mat, m, n);
    
    //Sonuclari al
    if (adamaxboyut == 0) {
        printf("Ada bulunamadi.\n");
    } else {
        printf("En buyuk adanin boyutu: %d\n", adamaxboyut);
    }
    
    //Hafizayi temizle
    for (int i = 0; i < m; i++) {
        free(mat[i]);
    }
    free(mat);
    
    return 0;
}

