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


/** Alegoria (cenário)															
	~ Os macacos vervets, tal como alguns de outras espécies, desenvolveram um meio eficiente para aumentar a proteção dos membros do grupo de seus predadores														
	~ Estes animais usam alarmes para informar a presença de seus predadores, a águia, a cobra e o tigre, aos outros membros do grupo														
	~ O alarme tem uma função adaptativa importante pois:														
		/se um tigre se aproxima o comportamento de fuga é o de ir para os galhos mais finos (externos) da árvore													
		/se uma águia se aproxima o comportamento de fuga é o de ir para a copa da árvore													
		/se uma cobra se aproxima é preciso ficar atendo à relva e à folhagem													
	~ Cada alarme leva a um comportamento de fuga que é eficiente para um tipo de predador, mas pode não ser para outro														
	~ Todavia, os macacos não nascem com este processo sígnico compartilhado pelos outros														
	~ Para que a linguagem traga vantagens adaptativas aos vervets, eles precisam compartilhar a dupla Sígno (alarme) - Predador*/

/*for (int i = 0; i < 50; i++) {
  for (int j = 0; j < 50; j++) {
    // Faça algo com o elemento matrix[i][j]
  }
}*/


#include <iostream>
#include <vector>
#include <string>
#include <math.h>
#include <algorithm>


const int m = 20;
const int p = 5;
const int coluna = 10;
const int linha = 10;

int MATRIZ_AMBIENTE[coluna][linha];

using namespace std;

struct PREDADOR {
    int x, y;
};
struct MACACO {
    int x, y;
    vector<string> simbolos;
    vector<float> pesos;
    int rp, ra;
};

void gerarPredador() {
  PREDADOR predador;
  predador.x = rand() % coluna;
  predador.y = rand() % linha;
  MATRIZ_AMBIENTE[predador.x][predador.y] = 1;
}

void gerarMacaco(MACACO &macaco) {
  macaco.x = rand() % coluna;
  macaco.y = rand() % linha;
  MATRIZ_AMBIENTE[macaco.x][macaco.y] = 2;
}

void moverMacaco(MACACO &macaco) {
  int novaPosicaoX = rand() % coluna;
  int novaPosicaoY = rand() % linha;
  while (MATRIZ_AMBIENTE[novaPosicaoX][novaPosicaoY] != 0) {
    novaPosicaoX = rand() % coluna;
    novaPosicaoY = rand() % linha;
  }
  MATRIZ_AMBIENTE[macaco.x][macaco.y] = 0;
  MATRIZ_AMBIENTE[novaPosicaoX][novaPosicaoY] = 2;
  macaco.x = novaPosicaoX;
  macaco.y = novaPosicaoY;
}

void moverPredador(PREDADOR &predador) { 
  
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


void gerarSimbolosMacaco(MACACO &macaco) {
    macaco.x = rand() % coluna;
    macaco.y = rand() % linha;
    for (int i = 0; i < 10; i++) {
    string simbolos = "simbolo " + to_string(i);
    float pesos = rand() / (float)RAND_MAX;
    macaco.simbolos.push_back(simbolos);
    macaco.pesos.push_back(pesos);
    cout << "Simbolos:" ;
  for (auto simbolos : macaco.simbolos) {
    cout << simbolos << " ";
  }
  cout << endl;
  cout << "Pesos: ";
  for (auto pesos : macaco.pesos) {
    cout << pesos << " ";
  }
  cout << endl;
  }
  macaco.rp = rand() % 10;
  macaco.ra = rand() % 10;
}

float distancia(int x1, int y1, int x2, int y2) {
    return sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
}

void interagirMacacos(MACACO &macaco, MACACO &macaco2) {
  // Se o macaco1 percebe a presença de um predador, ele consulta a tabela e dispara o alarme de maior valor f
  if (distancia(macaco.x, macaco.y, macaco2.x, macaco2.y) < macaco.rp) {
    int maior_peso = 0;
    string maior_simbolo;

    for (const auto &simbolo : macaco.simbolos) {
      int simbolo_int = std::stoi(simbolo);
      if (macaco2.pesos[simbolo_int] > maior_peso) {
        maior_peso = macaco2.pesos[simbolo_int];
        maior_simbolo = simbolo;
      }
    }
    cout << "O macaco1 percebe a presença de um predador e dispara o alarme de maior valor f: " << maior_peso << " " << maior_simbolo << endl;
  }

  // Se o macaco1 percebe um alarme e um predador, o valor de f da dupla (símbolo, predador) aumenta seguindo uma função recursiva, ex: f <− f+0,1
  if (distancia(macaco.x, macaco.y, macaco2.x, macaco2.y) < macaco.ra) {
    for (const auto &simbolo : macaco.simbolos) {
      float simbolo_float = std::stof(simbolo);
      if (macaco2.pesos[simbolo_float] > 0) {
        macaco2.pesos[simbolo_float] += 0.1;
        cout << "O macaco1 percebe um alarme e um predador e o valor de f da dupla (símbolo, predador) aumenta para: " << macaco2.pesos[simbolo_float] << endl;
      }
    }
  }

  // Se o macaco2 percebe a presença de um predador, ele consulta a tabela e dispara o alarme de maior valor f
  if (distancia(macaco2.x, macaco2.y, macaco.x, macaco.y) < macaco2.rp) {
    int maior_peso = 0;
    string maior_simbolo;

    for (const auto &simbolo : macaco2.simbolos) {
      int simbolo_int = std::stoi(simbolo);
      if (macaco.pesos[simbolo_int] > maior_peso) {
        maior_peso = macaco.pesos[simbolo_int];
        maior_simbolo = simbolo;
      }
    }
    cout << "O macaco2 percebe a presença de um predador e dispara o alarme de maior valor f: " << maior_peso << " " << maior_simbolo << endl;
  }

  // Se o macaco2 percebe um alarme e um predador, o valor de f da dupla (símbolo, predador) aumenta seguindo uma função recursiva, ex: f <− f+0,1
  if (distancia(macaco2.x, macaco2.y, macaco.x, macaco.y) < macaco2.ra) {
    for (const auto &simbolo : macaco2.simbolos) {
      float simbolo_float = std::stof(simbolo);
      if (macaco.pesos[simbolo_float] > 0) {
        macaco.pesos[simbolo_float] += 0.1;
        cout << "O macaco2 percebe um alarme e um predador e o valor de f da dupla (símbolo, predador) aumenta para: " << macaco.pesos[simbolo_float] << endl;
      }
    }
  }
}


void alarme_macaco(MACACO &macaco2){
// Se o macaco2 percebe um predador x, ele se move para a copa da árvore
  if (std::find(macaco2.simbolos.begin(), macaco2.simbolos.end(), "x") != macaco2.simbolos.end()) {
    macaco2.y = 10;
    cout << "O macaco2 percebe um predador x e se move para a copa da árvore" << endl;
  }

  // Se o macaco2 percebe um predador y, ele fica atento à relva e à folhagem
  if (std::find(macaco2.simbolos.begin(), macaco2.simbolos.end(), "y") != macaco2.simbolos.end()) {
    macaco2.x = 5;
    macaco2.y = 5;
    cout << "O macaco2 percebe um predador y e fica atento à relva e à folhagem" << endl;
  }
}

int main(){
/*
    alarme_macaco(macaco2);
    gerarSimbolosMacaco(macaco);
    gerarSimbolosMacaco(macaco2);
    interagirMacacos(macaco, macaco2);
*/
    MACACO macaco, macaco2;
// gerar alarme em 10 iterações 
    for (int i = 0; i < 10; i++) {
        interagirMacacos(macaco,macaco2);
    }

    return 0;

};




/*
    for (int i = 0; i < coluna; i++) {
      for (int j = 0; j < linha; j++) {
      MATRIZ_AMBIENTE[i][j] = 0;
     }
    }

  for (int i = 0; i < p; i++) {
    gerarPredador();
  }

  for (int i = 0; i < m; i++) {
    gerarMacaco(macaco);
  }
// imprimir a matriz com os valorer dos Macacos e Predadores 
  for (int i = 0; i < coluna; i++) {
    for (int j = 0; j < linha; j++) {
      cout << MATRIZ_AMBIENTE[i][j] << " ";
    }
    cout << endl;
  }

*/

 
  





