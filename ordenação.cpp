#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
using namespace std;

struct Prato {
    int prioridade;
    int tempo;
    string nome;
};

// Critério de comparação
bool compara(const Prato& a, const Prato& b) {
    if (a.prioridade != b.prioridade)
        return a.prioridade > b.prioridade; // Ordem decrescente de prioridade
    return a.tempo < b.tempo;              // Ordem crescente de tempo
}

// Função para carregar os pratos de um arquivo CSV
vector<Prato> carregarPratos(const string& caminhoArquivo) {
    ifstream arquivo(caminhoArquivo);
    vector<Prato> pratos;
    string linha;

    // Ignorar o cabeçalho
    getline(arquivo, linha);

    while (getline(arquivo, linha)) {
        istringstream ss(linha);
        Prato prato;
        string prioridade, tempo;

        // Extrair dados do CSV
        getline(ss, prioridade, ',');
        getline(ss, tempo, ',');
        getline(ss, prato.nome, ',');

        prato.prioridade = stoi(prioridade);
        prato.tempo = stoi(tempo);

        pratos.push_back(prato);
    }

    return pratos;
}

// Função para salvar os pratos ordenados em um arquivo CSV
void salvarPratos(const string& caminhoArquivo, const vector<Prato>& pratos) {
    ofstream arquivo(caminhoArquivo);
    arquivo << "prioridade,tempo,nome\n";

    for (const auto& prato : pratos) {
        arquivo << prato.prioridade << "," << prato.tempo << "," << prato.nome << "\n";
    }
}

// Implementação do Bubble Sort
void bubbleSort(vector<Prato>& pratos) {
    int n = pratos.size();
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (!compara(pratos[j], pratos[j + 1])) {
                swap(pratos[j], pratos[j + 1]);
            }
        }
    }
}

// Particiona o vetor para o Quick Sort
int particiona(vector<Prato>& pratos, int low, int high) {
    Prato pivo = pratos[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (compara(pratos[j], pivo)) {
            i++;
            swap(pratos[i], pratos[j]);
        }
    }
    swap(pratos[i + 1], pratos[high]);
    return i + 1;
}

// Implementação do Quick Sort
void quickSort(vector<Prato>& pratos, int low, int high) {
    if (low < high) {
        int pi = particiona(pratos, low, high);
        quickSort(pratos, low, pi - 1);
        quickSort(pratos, pi + 1, high);
    }
}

int main() {
    string caminhoEntrada = "restaurante_pratos.csv";
    string caminhoSaida = "pratos_ordenados.csv";

    // Carregar os pratos do arquivo CSV
    vector<Prato> pratos = carregarPratos(caminhoEntrada);

    // Escolher o método de ordenação:

    // Bubble Sort (demora muuuiito mas funciona)
    //bubbleSort(pratos);

    // Quick Sort
   quickSort(pratos, 0, pratos.size() - 1);

    // Salvar os pratos ordenados no arquivo CSV
    salvarPratos(caminhoSaida, pratos);

    cout << "Pratos ordenados salvos em " << caminhoSaida << endl;

    return 0;
}
