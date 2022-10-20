#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {

    // imprime o cabecalho do jogo
    printf("------------------------------------------\n");
    printf("|     Bem vindo ao jogo de adivinhacao   |\n");
    printf("------------------------------------------\n");

    int segundos = time(0);
    srand(segundos);
    int numerogrande = rand();
    int chute;
    int numerosecreto = numerogrande % 100;
    int ganhou = 0;
    int tentativas = 0;
    double pontos = 1000;
    int acertou = 0;
    int nivel;
    printf("Qual nivel de dificuldade?\n");
    printf("(1) Facil (2) Medio (3) Dificil\n\n");
    printf("Escolha: ");
    scanf("%d", &nivel);

    int numerodetentativas;
    switch(nivel){
        case 1:
            numerodetentativas = 20;
            printf("Nivel facil escolhido.\n");
            break;

        case 2:
            numerodetentativas = 15;
            printf("Nivel medio escolhido.\n");
            break;
        
        default:
            numerodetentativas = 6;
            printf("Nivel dificil escolhido.\n");
            break;
    }

    for(int i = 1; i <= numerodetentativas; i++){
        printf("Tentativa %d.\n", tentativas+1);
        printf("Qual e o seu chute? ");
        scanf("%d", &chute);
        printf("Seu chute foi o numero %d\n", chute);

        if (chute < 0){
            printf("Voce nao pode chutar numeros negativos\n");
            //faz o laço resetar, voltando para o inicio e ignorando as condiçoes abaixo
            continue;
        }

        acertou = (chute == numerosecreto);
        int maior = (chute > numerosecreto);

        if(acertou) {
            break;
        }
        else if (maior){
            printf("O numero que voce digitou e maior que o numero secreto\n");
        }
        else{
            printf("O numero que voce digitou e menor que o numero secreto\n");
        }

        double pontosperdidos = abs(chute - numerosecreto) / 2.0;
        pontos = pontos - pontosperdidos;
        tentativas++;
    }
    printf("Fim de jogo\n");
    if(acertou){
        printf("Voce ganhou!\n");
        printf("Voce ganhou o jogo em %d tentativas!\n", tentativas);
        printf("Total de pontos: %.1f\n", pontos);
    } else{
        printf("Voce perdeu:(\n");
    }
}
