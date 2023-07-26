#include <iostream>
#include <vector>
#include <string>
#include <math.h>
#include <algorithm>
#include <set>
#include <time.h>
#include <map>



const int m = 30;
const int p = 5;
const int coluna = 10;
const int linha = 10;
const int rp = 2;
const int ra = 5;
// Variável global para armazenar o número aleatório gerado
double numero_aleatorio = 0.0;

int MATRIZ_AMBIENTE[coluna][linha];


using namespace std;


// Gera um mapa para representar as condições dos animais encontrados ou avistados 
map<int, string> animal_condicao = {
    {1, "Cobra"},
    {2, "Tigre"},
    {3, "Aguia"}
};



// Lista de pares para armazenar o número gerado aleatoriamente e o animal associado
vector<pair<int, string>> simbolos;



//prototipo da função
double gerar_pesos_f();



// Função para gerar um número aleatório inteiro entre min e max
int gerar_numero_aleatorio(int min, int max) {
    return rand() % (max - min + 1) + min;
}



//Estrutura para criação do Predador 
struct PREDADOR {
    int x, y;
    vector<double> AGUIA;
    vector<double> TIGRE;
    vector<double> COBRA;
};

//Estrutura para a criação do Macaco
struct MACACO {
    int x, y;
};


// Função para gerar um macaco em uma posição aleatória e diferente de outras posições ocupadas
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
string moverMacaco(MACACO& macaco, int coluna, int linha, set<pair<int, int>>& posicoes_ocupadas, set<pair<int, int>>& predadores_encontrados) {
    PREDADOR predador;
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
                int distancia_predador = distancia_total;
                
                if (distancia_total == rp) {
                    // Verifica se o predador já foi encontrado antes
                    if (!predadores_encontrados.count({ i, j })) {
                        cout << "Alerta: Macaco encontrou um predador na posição (" << i << ", " << j << ")!" << endl;
                        predadores_encontrados.insert({ i, j });

                        // Gerar aleatoriamente uma lista de valores entre 1 e 10
                        vector<int> valores_aleatorios;
                        for (int i = 1; i <= 10; i++) {
                            valores_aleatorios.push_back(i);
                        }
                        random_shuffle(valores_aleatorios.begin(), valores_aleatorios.end());

                        // Atribuir cada animal a um valor aleatório
                        int index = 0;
                        for (const auto& animal : {"Cobra", "Tigre", "Aguia"}) {
                            animal_condicao[valores_aleatorios[index++]] = animal;
                        }
                        // Chamando a função para gerar um número aleatório
                        double numero_aleatorio = gerar_pesos_f();

                        // Obter o valor inteiro correspondente ao animal gerado aleatoriamente
                        int valor_aleatorio = static_cast<int>(numero_aleatorio * 3) + 1; // Intervalo de 1 a 3

                        // Obter o nome do animal associado ao valor aleatório gerado
                        //falta implementar esse valor *********
                        string animal_gerado = animal_condicao[valor_aleatorio];


                        // Com base no valor de distancia_predador, obter o animal correspondente
                        
                        string animal = animal_condicao[distancia_predador];

                        // Adicionar o par (valor da condição, animal) à lista de símbolos
                        simbolos.push_back(make_pair(distancia_predador, animal));

                        // Exibir qual animal encontrado 
                        cout << "Encontrou " << animal << ": " << numero_aleatorio << endl;

                        // Retornar o nome do animal encontrado
                        return animal;
                    }

                }

                // organizar o If superior com o inferior 
                else if (distancia_total == ra) {
                    // Verifica se o predador já foi encontrado antes
                    if (!predadores_encontrados.count({ i, j })) {
                        cout << "Alerta: Macaco viu um predador (" << i << "," << j << ")!" << endl;
                        predadores_encontrados.insert({ i, j });

                        // Gerar aleatoriamente uma lista de valores entre 1 e 10
                        vector<int> valores_aleatorios;
                        for (int i = 1; i <= 10; i++) {
                            valores_aleatorios.push_back(i);
                        }
                        random_shuffle(valores_aleatorios.begin(), valores_aleatorios.end());

                        // Atribuir cada animal a um valor aleatório
                        int index = 0;
                        for (const auto& animal : {"Cobra", "Tigre", "Aguia"}) {
                            animal_condicao[valores_aleatorios[index++]] = animal;
                        }
                        // Chamando a função para gerar um número aleatório
                        double numero_aleatorio = gerar_pesos_f();

                        // Com base no valor de distancia_predador, obter o animal correspondente
                        string animal = animal_condicao[distancia_predador];

                        // Adicionar o par (valor da condição, animal) à lista de símbolos
                        simbolos.push_back(make_pair(distancia_predador, animal));

                        // Exibir qual animal encontrado 
                        cout << "Encontrou " << animal << ": " << numero_aleatorio << endl;

                        // Retornar o nome do animal encontrado
                        return animal;
                        
                    }
                    
                }
            }
        }
    }

    macaco.x = novaPosicaoX;
    macaco.y = novaPosicaoY;
}


//Gerar um novo predador no ambiente 
void gerarPredador() {
    PREDADOR predador;
    predador.x = rand() % coluna;
    predador.y = rand() % linha;
    MATRIZ_AMBIENTE[predador.x][predador.y] = 1;
}

void gerarMacaco(MACACO& macaco) {
    MATRIZ_AMBIENTE[macaco.x][macaco.y] = 2;
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


// Função para gerar um número aleatório entre 0.0 e 1.0
double gerar_pesos_f() {
    return static_cast<double>(rand()) / RAND_MAX;
}



int main() {
    // Semente do gerador de números aleatórios
    srand(static_cast<unsigned int>(time(0)));

    // Inicializa a matriz com zeros
    for (int i = 0; i < coluna; i++) {
        for (int j = 0; j < linha; j++) {
            MATRIZ_AMBIENTE[i][j] = 0;
        }
    }

    // Conjunto para armazenar as posições ocupadas pelos macacos
    std::set<std::pair<int, int>> posicoes_ocupadas;
    std::set<std::pair<int, int>> predadores_encontrados; // Conjunto para armazenar os predadores encontrados

    gerarPredadores(); // Gera os predadores iniciais

    // Gera os macacos
    vector<MACACO> macacos;
    for (int i = 0; i < m; i++) {
        MACACO macaco = gerarMacacoAleatorio(coluna, linha, posicoes_ocupadas);
        posicoes_ocupadas.insert({ macaco.x, macaco.y });
        macacos.push_back(macaco); // Adiciona o macaco ao vetor
    }

    // Vetor para armazenar os predadores
    vector<PREDADOR> predadores;

    for (int i = 0; i < 10; i++) {
        // Move os macacos
        for (int j = 0; j < m; j++) {
            moverMacaco(macacos[j], coluna, linha, posicoes_ocupadas, predadores_encontrados);
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
                cout << MATRIZ_AMBIENTE[j][k] << " ";
            }
            cout << endl;
        }

        cout << "---------------------------" << endl;
    }

    // Imprime os valores dos vetores AGUIA, TIGRE e COBRA para cada predador
    for (const auto& pre : predadores) {
        cout << "Predador na posição (" << pre.x << ", " << pre.y << "):" << endl;
        cout << "AGUIA: ";
        for (const auto& aguia_val : pre.AGUIA) {
            cout << aguia_val << " ";
        }
        cout << endl;
        cout << "TIGRE: ";
        for (const auto& tigre_val : pre.TIGRE) {
            cout << tigre_val << " ";
        }
        cout << endl;
        cout << "COBRA: ";
        for (const auto& cobra_val : pre.COBRA) {
            cout << cobra_val << " ";
        }
        cout << endl;
        cout << "---------------------------" << endl;
    }



    // Imprimir o conteúdo do mapa animal_condicao
    for (const auto& entry : animal_condicao) {
        cout << "Numero " << entry.first << ", Animal " << entry.second << endl;
    }

     // Imprimir o conteúdo da lista de pares simbolos
    for (const auto& par : simbolos) {
        cout << "Peso_F " << par.first << ", Animal: " << par.second << endl;
    }

    // Imprimir os valores do mapa animal_condicao
    for (const auto& par : animal_condicao) {
        cout << "Peso_F " << par.first << ", Animal: " << par.second << endl;
    }

    
    
return 0;
};



