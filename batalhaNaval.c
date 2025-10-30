#include <stdio.h>

int main() {

    //CRIAÇÃO DO TABULEIRO    

    int tabuleiro[10][10];
    int i, j;

    //Inicializa o tabuleiro com água (0)

    for (i = 0; i < 10; i++) {
        for (j = 0; j < 10; j++) {
            tabuleiro[i][j] = 0;
        }
    }

    int tamanho_navio = 3;

    // POSICIONAMENTO DOS 4 NAVIOS 
    // Navio 1: horizontal

    int linha_h1 = 1, coluna_h1 = 2;
    for (i = 0; i < tamanho_navio; i++)
        tabuleiro[linha_h1][coluna_h1 + i] = 3;

    // Navio 2: vertical

    int linha_v1 = 4, coluna_v1 = 7;
    for (i = 0; i < tamanho_navio; i++)
        tabuleiro[linha_v1 + i][coluna_v1] = 3;

    // Navio 3: horizontal

    int linha_h2 = 6, coluna_h2 = 0;
    for (i = 0; i < tamanho_navio; i++)
        tabuleiro[linha_h2][coluna_h2 + i] = 3;

    // Navio 4: vertical

    int linha_v2 = 0, coluna_v2 = 9;
    for (i = 0; i < tamanho_navio; i++)
        tabuleiro[linha_v2 + i][coluna_v2] = 3;


    // MATRIZES DE HABILIDADE

    int cone[5][5];
    int cruz[5][5];
    int octaedro[5][5];

    // Habilidade CONE

    for (i = 0; i < 5; i++) {
        for (j = 0; j < 5; j++) {
            if (j >= 2 - i && j <= 2 + i) 
                cone[i][j] = 1;
            else
                cone[i][j] = 0;
        }
    }

    // Habilidade CRUZ

    for (i = 0; i < 5; i++) {
        for (j = 0; j < 5; j++) {
            if (i == 2 || j == 2)
                cruz[i][j] = 1;
            else
                cruz[i][j] = 0;
        }
    }

    // Habilidade OCTAEDRO
    for (i = 0; i < 5; i++) {
        for (j = 0; j < 5; j++) {
            if (abs(i - 2) + abs(j - 2) <= 2)
                octaedro[i][j] = 1;
            else
                octaedro[i][j] = 0;
        }
    }

    // APLICAÇÃO DAS HABILIDADES NO TABULEIRO 

    int origem_cone_l = 3, origem_cone_c = 3;     // centro da habilidade cone
    int origem_cruz_l = 7, origem_cruz_c = 4;     // centro da habilidade cruz
    int origem_octa_l = 5, origem_octa_c = 1;     // centro da habilidade octaedro

    // Aplica CONE

    for (i = 0; i < 5; i++) {
        for (j = 0; j < 5; j++) {
            if (cone[i][j] == 1) {
                int l = origem_cone_l - 2 + i;
                int c = origem_cone_c - 2 + j;
                if (l >= 0 && l < 10 && c >= 0 && c < 10 && tabuleiro[l][c] == 0)
                    tabuleiro[l][c] = 5;
            }
        }
    }

    // Aplica CRUZ

    for (i = 0; i < 5; i++) {
        for (j = 0; j < 5; j++) {
            if (cruz[i][j] == 1) {
                int l = origem_cruz_l - 2 + i;
                int c = origem_cruz_c - 2 + j;
                if (l >= 0 && l < 10 && c >= 0 && c < 10 && tabuleiro[l][c] == 0)
                    tabuleiro[l][c] = 5;
            }
        }
    }

    // Aplica OCTAEDRO

    for (i = 0; i < 5; i++) {
        for (j = 0; j < 5; j++) {
            if (octaedro[i][j] == 1) {
                int l = origem_octa_l - 2 + i;
                int c = origem_octa_c - 2 + j;
                if (l >= 0 && l < 10 && c >= 0 && c < 10 && tabuleiro[l][c] == 0)
                    tabuleiro[l][c] = 5;
            }
        }
    }

    // EXIBIÇÃO FINAL 

    printf("=== TABULEIRO DE BATALHA NAVAL COM HABILIDADES ===\n\n");
    printf("Legenda: 0 = Agua | 3 = Navio | 5 = Area de Habilidade\n\n");

    for (i = 0; i < 10; i++) {
        for (j = 0; j < 10; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}


