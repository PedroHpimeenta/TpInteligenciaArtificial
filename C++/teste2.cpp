#include <iostream>
#include <vector>
#include <string>
#include <math.h>
#include <algorithm>
#include <set>
#include <time.h>

const int m = 30;
const int p = 5;
const int coluna = 10;
const int linha = 10;

const int rp = 2;
const int ra = 5;


int MATRIZ_AMBIENTE[coluna][linha];

using namespace std;

struct PREDADOR {
    int x, y;


};

struct MACACO {
    int x, y;
};

void gerarPredador() {
    PREDADOR predador;
    predador.x = rand() % coluna;
    predador.y = rand() % linha;
    MATRIZ_AMBIENTE[predador.x][predador.y] = 1;
}

void gerarMacaco(MACACO& macaco) {
    MATRIZ_AMBIENTE[macaco.x][macaco.y] = 2;
}

// Função para gerar um macaco em uma posição aleatória diferente de outras posições ocupadas
MACACO gerarMacacoAleatorio(int coluna, int linha, std::set<std::pair<int, int>>& posicoes_ocupadas) {
    MACACO macaco;
    do {
        macaco.x = rand() % coluna; // Gera uma posição aleatória de x
        macaco.y = rand() % linha;  // Gera uma posição aleatória de y
    } while (posicoes_ocupadas.count({ macaco.x, macaco.y }) > 0); // Verifica se a posição já está ocupada

    posicoes_ocupadas.insert({ macaco.x, macaco.y }); // Adiciona a posição ocupada ao conjunto
    return macaco;
}

// Função para mover um macaco para uma posição aleatória diferente de outras posições ocupadas
void moverMacaco(MACACO& macaco, int coluna, int linha, std::set<std::pair<int, int>>& posicoes_ocupadas) {
    int novaPosicaoX = rand() % coluna;
    int novaPosicaoY = rand() % linha;
    while (posicoes_ocupadas.count({ novaPosicaoX, novaPosicaoY }) > 0) {
        novaPosicaoX = rand() % coluna;
        novaPosicaoY = rand() % linha;
    }

    posicoes_ocupadas.erase({ macaco.x, macaco.y });
    posicoes_ocupadas.insert({ novaPosicaoX, novaPosicaoY });

    // Verificar se o macaco encontrou um predador
    for (int i = 0; i < coluna; i++) {
        for (int j = 0; j < linha; j++) {
            if (MATRIZ_AMBIENTE[i][j] == 1) {
                int distancia_x = abs(novaPosicaoX - i); // Distância em relação ao eixo x
                int distancia_y = abs(novaPosicaoY - j); // Distância em relação ao eixo y
                int distancia_total = distancia_x + distancia_y;

                if (distancia_total == rp) {
                    cout << "Alerta: Macaco encontrou um predador na posição (" << i << ", " << j << ")!" << endl;
                }
                else if (distancia_total == ra){
                  cout <<" Alerta: Macaco viu um predador (" << i << "," << j << ")!" << endl;
                }
            }
        }
    }

    macaco.x = novaPosicaoX;
    macaco.y = novaPosicaoY;
}

void moverPredador(PREDADOR& predador) {
    int novaPosicaoX = rand() % coluna;
    int novaPosicaoY = rand() % linha;
    while (MATRIZ_AMBIENTE[novaPosicaoX][novaPosicaoY] != 0) {
        novaPosicaoX = rand() % coluna;
        novaPosicaoY = rand() % linha;
    }
    MATRIZ_AMBIENTE[predador.x][predador.y] = 0;
    MATRIZ_AMBIENTE[novaPosicaoX][novaPosicaoY] = 1;
    predador.x = novaPosicaoX;
    predador.y = novaPosicaoY;
}

// Função para gerar novos predadores em posições aleatórias
void gerarPredadores() {
    for (int i = 0; i < p; i++) {
        int novaPosicaoX = rand() % coluna;
        int novaPosicaoY = rand() % linha;
        while (MATRIZ_AMBIENTE[novaPosicaoX][novaPosicaoY] != 0) {
            novaPosicaoX = rand() % coluna;
            novaPosicaoY = rand() % linha;
        }
        MATRIZ_AMBIENTE[novaPosicaoX][novaPosicaoY] = 1;
    }
}

int main() {
    // Semente do gerador de números aleatórios
    srand(static_cast<unsigned int>(time(0)));

    MACACO macaco;

    // Inicializa a matriz com zeros
    for (int i = 0; i < coluna; i++) {
        for (int j = 0; j < linha; j++) {
            MATRIZ_AMBIENTE[i][j] = 0;
        }
    }

    // Conjunto para armazenar as posições ocupadas pelos macacos
    std::set<std::pair<int, int>> posicoes_ocupadas;

    gerarPredadores(); // Gera os predadores iniciais

    // Gera os macacos
    vector<MACACO> macacos;
    for (int i = 0; i < m; i++) {
        MACACO macaco = gerarMacacoAleatorio(coluna, linha, posicoes_ocupadas);
        posicoes_ocupadas.insert({ macaco.x, macaco.y });
        macacos.push_back(macaco); // Adiciona o macaco ao vetor
        gerarMacaco(macaco);
    }

    for (int i = 0; i < 10; i++) {
        // Move os macacos
        for (int j = 0; j < m; j++) {
            moverMacaco(macacos[j], coluna, linha, posicoes_ocupadas);
        }

        // Atualiza a matriz com as novas posições dos macacos
        for (int j = 0; j < coluna; j++) {
            for (int k = 0; k < linha; k++) {
                MATRIZ_AMBIENTE[j][k] = 0;
            }
        }

        gerarPredadores(); // Gera novos predadores em cada iteração

        for (const auto& posicao : posicoes_ocupadas) {
            MATRIZ_AMBIENTE[posicao.first][posicao.second] = 2;
        }

        // Imprime a matriz com macacos e predadores
        for (int j = 0; j < coluna; j++) {
            for (int k = 0; k < linha; k++) {
                std::cout << MATRIZ_AMBIENTE[j][k] << " ";
            }
            std::cout << std::endl;
        }

        std::cout << "---------------------------" << std::endl;
    }

return 0;
}