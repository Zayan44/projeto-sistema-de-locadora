#ifndef LOCAL_H
#define LOCAL_H

#include "veiculo.h"
#include <cstring>
#include <vector>

using namespace std;

class Local {

private:

    // Atributos
    char nomeLocal[200];
    int coordXLocal;
    int coordYLocal;

    static vector<Local> locais; 

public:

    // Construtor
    Local(const char* PnomeLocal, int PcoordXLocal, int PcoordYLocal);
    Local();
    
    // Getters
    const char* getNomeLocal() const;
    int getCoordXLocal() const;
    int getCoordYLocal() const;
    static vector<Local>& getLocais();

    // Setters
    void setNomeLocal(const char* nomeLocal);
    void setCoordXLocal(int coordXLocal);
    void setCoordYLocal(int coordYLocal);

    //sistema de locais
    static void cadastroLocal();
    static void listarLocal();
    static void atualizacaoLocal();
    static void deletarLocal();
};



#endif