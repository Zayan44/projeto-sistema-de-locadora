#include "local.h"

#include <iostream>
#include <cstring>
#include <vector>

#define INPUTMAXNOME 200

using namespace std;

vector<Local> Local::locais; // vetor estático de locais

// Construtor
Local::Local(const char *nomeLocal, int coordXLocal, int coordYlocal)
{
    strcpy(this->nomeLocal, nomeLocal);
    this->nomeLocal[INPUTMAXNOME - 1] = '\0'; // garante que termina com null
    this->coordXLocal = coordXLocal;
    this->coordYLocal = coordYlocal;
}

Local::Local() {
    strcpy(nomeLocal, ""); // nome vazio
    coordXLocal = 0;
    coordYLocal = 0;
}


// Getters
const char *Local::getNomeLocal() const
{
    return this->nomeLocal;
}

int Local::getCoordXLocal() const
{
    return this->coordXLocal;
}

int Local::getCoordYLocal() const
{
    return this->coordYLocal;
}

vector<Local>& Local::getLocais() {
    return locais;
}

// Setters
void Local::setNomeLocal(const char *nomeLocal)
{
    strncpy(this->nomeLocal, nomeLocal, INPUTMAXNOME);
    this->nomeLocal[INPUTMAXNOME - 1] = '\0';
}

void Local::setCoordXLocal(int coordXLocal)
{
    this->coordXLocal = coordXLocal;
}

void Local::setCoordYLocal(int coordYLocal)
{
    this->coordYLocal = coordYLocal;
}

// Função para cadastro de locais
 void Local::cadastroLocal()
{

    char inputNomeLocal[INPUTMAXNOME];
    int inputCoordXLocal;
    int inputCoordYLocal;

    cout << endl
         << "Insira o endereco (Brasil, MG, Belo Horizonte, Rua A 100):" << endl;

    cin.ignore();
    fgets(inputNomeLocal, INPUTMAXNOME, stdin);
    inputNomeLocal[strcspn(inputNomeLocal, "\n")] = 0;

    cout << endl
         << "Insira a coordenada X:" << endl;
    cin >> inputCoordXLocal;

    cout << endl
         << "Insira a coordenada Y" << endl;
    cin >> inputCoordYLocal;

    Local novoLocal(inputNomeLocal, inputCoordXLocal, inputCoordYLocal);

    locais.push_back(novoLocal);

    cout << endl
<< "Local cadastrado com sucesso!" << endl;
}

// Função para listar locais
void Local::listarLocal()
{

    int contador = 1;

    if (locais.empty())
    {
        cout << endl
             << "Nenhum local foi cadastrado." << endl;
    }

    else
    {
        cout << "===== LISTA DE LOCAIS" << endl;

        for (const auto listador : locais)
        {

            cout << endl
                 << "Numero " << contador << endl;
            cout << "Endereco: " << listador.getNomeLocal() << endl;
            cout << "Coordenada X: " << listador.getCoordXLocal() << endl;
            cout << "Coordenada Y: " << listador.getCoordYLocal() << endl;
            ++contador;
        }
    }
}

// Função para atualização das informações já cadastradas anteriormente
void Local::atualizacaoLocal()
{
    char inputAtualizarNome[INPUTMAXNOME];
    int comando;

    cout << endl
         << "Insira o nome do endereço que deseja alterar" << endl;

    cin.ignore();
    fgets(inputAtualizarNome, INPUTMAXNOME, stdin);
    inputAtualizarNome[strcspn(inputAtualizarNome, "\n")] = 0;

    for (auto &listador : locais)
    {
        if (strcmp(inputAtualizarNome, listador.getNomeLocal()) == 0)
        {

            do
            {

                cout << endl
                     << "Escolha a qual informação deseja alterar" << endl
                     << "1 - Nome" << endl
                     << "2 - Coordenadas X" << endl
                     << "3 - Coordenadas Y" << endl;

                cin >> comando;

                switch (comando)
                {
                case 1:
                {
                    char novoNome[INPUTMAXNOME];
                    cout << endl
                         << "Insira o novo nome" << endl;

                    cin.ignore();
                    fgets(novoNome, INPUTMAXNOME, stdin);
                    novoNome[strcspn(novoNome, "\n")] = 0;

                    listador.setNomeLocal(novoNome);
                    cout << endl
                         << "Nome atualizado com sucesso!" << endl;
                    break;
                }

                case 2:
                {
                    int novaCoordX;
                    cout << endl
                         << "Insira a nova coordenada X" << endl;
                    cin >> novaCoordX;
                    listador.setCoordXLocal(novaCoordX);
                    cout << endl
                         << "Coordenada X atualizada com sucesso!" << endl;
                    break;
                }

                case 3:
                {
                    int novaCoordY;
                    cout << endl
                         << "Insira a nova coordenada Y" << endl;
                    cin >> novaCoordY;
                    listador.setCoordYLocal(novaCoordY);
                    cout << endl
                         << "Coordenada Y atualizada com sucesso!" << endl;
                    break;
                }
                }

            } while (comando < 1 || comando > 3);
        }
    }
}

// Função para deletar algum local
void Local::deletarLocal()
{

    char inputDeletarNome[INPUTMAXNOME];
    bool encontrado = false;

    cout << endl
         << "Insira o endereço que deseja excluir" << endl;

    cin.ignore();
    fgets(inputDeletarNome, INPUTMAXNOME, stdin);
    inputDeletarNome[strcspn(inputDeletarNome, "\n")] = 0;

    for (auto iterador = locais.begin(); iterador != locais.end(); ++iterador)
    {
        if (strcmp(inputDeletarNome, iterador->getNomeLocal()) == 0)
        {
            locais.erase(iterador);
            encontrado = true;
            cout << endl
                 << "Local removido com sucesso!" << endl;
            break;
        }
    }

    if (!encontrado)
    {
        cout << "Local não encontrado";
    }
}