#include <iostream>
#include <vector>
#include <string>
#include <math.h>
#include <algorithm>
#include <map>

const int coluna = 10;
const int linha = 10;
int MATRIZ_AMBIENTE[coluna][linha];

struct MACACO {
  int x;
  int y;

  bool perceivePredator() {
    // A macaco percebe um predador se houver um predador na mesma posição que ele.
    int s = std::max_element(MATRIZ_AMBIENTE[x][y], MATRIZ_AMBIENTE[x][y] + linha) - MATRIZ_AMBIENTE[x][y];
    if (s == 3) {
      return true;
    } else {
      return false;
    }
  }

  void fireAlarm(int s) {
    // Um macaco dispara um alarme se ele perceber um predador.
    if (perceivePredator()) {
      MATRIZ_AMBIENTE[x][y][s] += 0.1;
    }
  }
};

bool perceiveAlarm() {
  // Um macaco percebe um alarme se houver um alarme na mesma posição que ele.
  int s = std::max_element(MATRIZ_AMBIENTE[x][y], MATRIZ_AMBIENTE[x][y] + linha) - MATRIZ_AMBIENTE[x][y];
  if (s == 2) {
    return true;
  } else {
    return false;
  }
}

void simulateMonkeyBehavior(std::vector<MACACO> macacos, int coluna, int linha) {
  for (int i = 0; i < macacos.size(); i++) {
    // Encontre o símbolo com o maior valor na matriz `MATRIZ_AMBIENTE`.
    int s = std::max_element(MATRIZ_AMBIENTE[macacos[i].x][macacos[i].y], MATRIZ_AMBIENTE[macacos[i].x][macacos[i].y] + linha) - MATRIZ_AMBIENTE[macacos[i].x][macacos[i].y];

    // Se o agente perceber a presença de um predador, dispare o alarme correspondente ao símbolo.
    if (macacos[i].perceivePredator()) {
      macacos[i].fireAlarm(s);
    }

    // Se o agente perceber um alarme, aumente o valor do símbolo correspondente na matriz `MATRIZ_AMBIENTE`.
    if (macacos[i].perceiveAlarm()) {
      MATRIZ_AMBIENTE[macacos[i].x][macacos[i].y][s] += 0.1;
    }
  }
}

using namespace std;

int main() {

  // Crie uma lista de macacos.
  vector<MACACO> macacos(10);

  // Adicione macacos à lista.
  for (int i = 0; i < 10; i++) {
    macacos.push_back({rand() % coluna, rand() % linha});
  };

  // Gerar predadores.
  int nPredadores = 10;

  // Repita o seguinte para cada predador.
  for (int i = 0; i < nPredadores; i++) {
    int x = rand() % coluna;
    int y = rand() % linha;
    MATRIZ_AMBIENTE[x][y] = 3;
  };


  // Imprima a matriz `MATRIZ_AMBIENTE` na tela.
  for (int i = 0; i < coluna; i++) {
    for (int j = 0; j < linha; j++) {
      std::cout << MATRIZ_AMBIENTE[i][j];
    }
    std::cout << std::endl;
  }

  return 0;
}

