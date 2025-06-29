#ifndef VEICULO_H
#define VEICULO_H

class Local; 

#include <iostream>
#include <cstring>
#include <vector>

#define INPUTMAXPLACA 8

using namespace std;

class Veiculo {
private:
    char placa[INPUTMAXPLACA];     
    char modelo[50];    
    bool disponivel;
    Local* localAtual; 

    static vector<Veiculo> veiculos;

public:
    // Construtores
    Veiculo(const char* placa, const char* modelo, bool disponivel, const Local& local);

    // Getters
    const char* getPlaca() const;
    const char* getModelo() const;
    bool getDisponibilidade() const;
    static vector<Veiculo>& getVeiculos();

    Local getLocalAtual() const;

    // Setters
    void setPlaca(const char* p);
    void setModelo(const char* modelo);
    void setDisponibilidade(bool d);
    void setLocalAtual(const Local& l);

    // Funções do sistema
   static void cadastrarVeiculo();
   static void listarVeiculo();
   static void atualizarVeiculo();
   static void deletarVeiculo();
};

#endif
