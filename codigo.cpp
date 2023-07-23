/*
#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <string> 
int MATRIZ_AMBIENTE[50][50];

struct PREDADOR {
    int x, y;
};

struct MACACO {
    int x, y;
    int rp = 2;
    int ra = 5;
    double valor_de_f[10] = {0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0};
};

bool macaco_percebe_predador(MACACO macaco, PREDADOR predador) {
    return abs(macaco.x - predador.x) <= macaco.rp &&
           abs(macaco.y - predador.y) <= macaco.rp;
}

double aumentar_f(MACACO &macaco, PREDADOR &predador, double valor_de_f) {
    if (macaco_percebe_predador(macaco, predador)) {
        valor_de_f += 0.1;
    }
    return valor_de_f;
}
using namespace std;
int main() {

    srand(time(NULL));

    string simbolos[10] = {"s1", "s2", "s3", "s4", "s5", "s6", "s7", "s8", "s9", "s10"};
    double pesos[10] = {0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0};

    // Gera pesos aleatórios para os símbolos.
    for (int i = 0; i < 10; i++) {
        pesos[i] = rand() / (double)RAND_MAX;
    }

    // Inicializa os elementos da matriz com 0.
    for (int i = 0; i < 50; i++) {
        for (int j = 0; j < 50; j++) {
            MATRIZ_AMBIENTE[i][j] = 0;
        }
    }

    // Inicializa os macacos aleatoriamente.
    MACACO macaco[100];
    for (int i = 0; i < 10; i++) {
        macaco[i].x = rand() % 50;
        macaco[i].y = rand() % 50;
        macaco[i].rp = 2;
        macaco[i].ra = 5;
    }

    // Inicializa os predadores aleatoriamente.
    PREDADOR predador[3];
    for (int i = 0; i < 3; i++) {
        predador[i].x = rand() % 50;
        predador[i].y = rand() % 50;
    }

    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            // Verifica se o macaco percebe a presença de um predador.
            if (abs(macaco[i].x - predador[j].x) <= macaco[i].rp &&
                abs(macaco[i].y - predador[j].y) <= macaco[i].rp) {
                // Aumenta o valor de f para o símbolo de maior valor.
                macaco[i].valor_de_f[j] = aumentar_f(macaco[i], predador[j], macaco[i].valor_de_f[j]);
            }
        }
        // Imprime o valor de f para o símbolo de maior valor.
        int simbolo_maximo = std::max_element(macaco[i].valor_de_f, macaco[i].valor_de_f + 10) - macaco[i].valor_de_f;
        std::cout << "O valor de f para o símbolo de maior valor do macaco " << i << " é: " << macaco[i].valor_de_f[simbolo_maximo] << std::endl;
    }

    return 0;
}
*/


