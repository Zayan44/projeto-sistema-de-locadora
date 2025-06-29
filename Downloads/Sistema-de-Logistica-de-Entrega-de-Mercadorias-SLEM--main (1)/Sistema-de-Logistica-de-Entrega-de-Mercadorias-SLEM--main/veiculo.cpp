#include "veiculo.h"
#include "local.h"

#include <iostream>
#include <vector>
#include <locale.h>
#include <cstring>

#define INPUTMAXPLACA 8

using namespace std;

vector<Veiculo> Veiculo::veiculos;

// Construtor
Veiculo::Veiculo(const char *p, const char *m, bool d, const Local &l)
{
    strcpy(placa, p);
    strcpy(modelo, m);
    disponivel = d;
    localAtual = new Local(l);
}

// Getters
const char *Veiculo::getPlaca() const { return placa; }
const char *Veiculo::getModelo() const { return modelo; }
bool Veiculo::getDisponibilidade() const { return disponivel; }
Local Veiculo::getLocalAtual() const { return *localAtual; }
vector<Veiculo>& Veiculo::getVeiculos() { return veiculos;}
// Setters
void Veiculo::setPlaca(const char *p) { strcpy(this->placa, p); }
void Veiculo::setModelo(const char *m) { strcpy(modelo, m); }
void Veiculo::setDisponibilidade(bool d) { disponivel = d; }
void Veiculo::setLocalAtual(const Local &l)
{
    if (localAtual)
        delete localAtual;
    localAtual = new Local(l);
}

// Função para cadastrar veículo
void Veiculo::cadastrarVeiculo()
{
    setlocale(LC_ALL, "Portuguese");

    char inputPlaca[INPUTMAXPLACA], inputModelo[50], nomeLocal[50];
    bool inputDisponivel = true;

    cout << "\n--- Cadastro de Veiculo ---\n";

    cin.ignore();

    cout << "Insira a placa do veiculo: ";
    cin.getline(inputPlaca, INPUTMAXPLACA);

    cout << "Insira o modelo do veiculo: ";
    cin.getline(inputModelo, 50);

    cout << "Insira o nome do local do veiculo: ";
    cin.getline(nomeLocal, 50);

    bool localExiste = false;

    for (const auto &local : Local::getLocais())
    {
        if (strcmp(local.getNomeLocal(), nomeLocal) == 0)
        {
            localExiste = true;
            break;
        }
    }

    if (!localExiste)
    {
        cout << "Falha: Local informado nao esta cadastrado. Cadastre o local primeiro.\n";
        return;
    }

    Local localEncontrado;

    for (const auto &local : Local::getLocais()) {
    if (strcmp(local.getNomeLocal(), nomeLocal) == 0) {
        localEncontrado = local; // cópia correta com as coordenadas reais
        break;
    }
}

Veiculo novoVeiculo(inputPlaca, inputModelo, inputDisponivel, localEncontrado);


    cout << "Veiculo cadastrado com sucesso!\n";
    veiculos.push_back(novoVeiculo);
}

// Função para listar veiculos
void Veiculo::listarVeiculo()
{
    setlocale(LC_ALL, "Portuguese");

    if (veiculos.empty())
    {
        cout << "Nenhum veiculo foi cadastrado.\n";
        return;
    }

    cout << "\n===== Lista de veiculos cadastrados =====\n";

    for (const auto &veiculo : veiculos)
    {
        cout << endl;
        cout << "Placa: " << veiculo.getPlaca() << endl;
        cout << "Modelo: " << veiculo.getModelo() << endl;
        cout << "Disponibilidade: " << (veiculo.getDisponibilidade() ? "Disponivel" : "Indisponivel") << endl;
        cout << "Local atual: " << veiculo.getLocalAtual().getNomeLocal() << endl;
        cout << "----------------------------------------" << endl;
    }
}

// Função para atualizar veiculo
void Veiculo::atualizarVeiculo()
{
    if (veiculos.empty())
    {
        cout << "Nenhum veiculo cadastrado.\n";
        return;
    }

    char inputPlaca[INPUTMAXPLACA];
    cout << "Insira a placa do veiculo que deseja atualizar: ";
    cin.ignore();
    cin.getline(inputPlaca, INPUTMAXPLACA);

    Veiculo *veiculoEncontrado = nullptr;
    for (auto &veiculo : veiculos)
    {
        if (strcmp(veiculo.getPlaca(), inputPlaca) == 0)
        {
            veiculoEncontrado = &veiculo;
            break;
        }
    }

    if (veiculoEncontrado == nullptr)
    {
        cout << "Veiculo com placa " << inputPlaca << " não encontrado.\n";
        return;
    }

    cout << "Veiculo encontrado: " << veiculoEncontrado->getModelo() << endl;

    int comando;
    do
    {
        cout << "\n--- Atualização de Veiculo ---\n";
        cout << "1. Atualizar modelo\n";
        cout << "2. Atualizar disponibilidade\n";
        cout << "3. Atualizar local atual\n";
        cout << "4. Atualizar placa\n";
        cout << "0. Voltar\n";
        cout << "Opção: ";
        cin >> comando;

        switch (comando)
        {
        case 1:
        {
            char novoModelo[50];
            cin.ignore();
            cout << "Novo modelo: ";
            cin.getline(novoModelo, 50);
            veiculoEncontrado->setModelo(novoModelo);
            cout << "Modelo atualizado com sucesso!\n";
            break;
        }
        case 2:
        {
            int disponivel;
            cout << "Veiculo está disponível? (1 = sim, 0 = não): ";
            cin >> disponivel;
            veiculoEncontrado->setDisponibilidade(disponivel == 1);
            cout << "Disponibilidade atualizada com sucesso!\n";
            break;
        }
        case 3:
        {
            char novoNomeLocal[50];
            cin.ignore();
            cout << "Novo nome do local atual: ";
            cin.getline(novoNomeLocal, 50);

            // Adicione esta verificação antes de criar o novo Local:
            bool localExiste = false;
            for (const auto &local : Local::getLocais())
            {
                if (strcmp(local.getNomeLocal(), novoNomeLocal) == 0)
                {
                    localExiste = true;
                    break;
                }
            }

            if (!localExiste)
            {
                cout << "Falha: Local informado não está cadastrado.\n";
                break;
            }

            Local novoLocal(novoNomeLocal, 0, 0);
            veiculoEncontrado->setLocalAtual(novoLocal);
            cout << "Local atualizado com sucesso!\n";
            break;
        }
        case 4:
        {
            char novaPlaca[INPUTMAXPLACA];
            cin.ignore();
            cout << "Nova placa: ";
            cin.getline(novaPlaca, INPUTMAXPLACA);
            veiculoEncontrado->setPlaca(novaPlaca);
            cout << "Placa atualizada com sucesso!\n";
            break;
        }
        case 0:
            cout << "Retornando ao menu.\n";
            break;
        default:
            cout << "Opção inválida.\n";
        }
    } while (comando != 0);
}

// Função para deletar veiculo
void Veiculo::deletarVeiculo()
{
    setlocale(LC_ALL, "Portuguese");

    if (veiculos.empty())
    {
        cout << "Nenhum veiculo cadastrado.\n";
        return;
    }

    char inputPlaca[INPUTMAXPLACA];
    cout << "Insira a placa do veiculo que deseja deletar: ";
    cin.ignore();
    cin.getline(inputPlaca, INPUTMAXPLACA);

    for (auto veiculo = veiculos.begin(); veiculo != veiculos.end(); ++veiculo)
    {
        if (strcmp(veiculo->getPlaca(), inputPlaca) == 0)
        {
            veiculos.erase(veiculo);
            cout << "Veiculo deletado com sucesso!\n";
            return;
        }
    }

    cout << "Veiculo com placa " << inputPlaca << " não encontrado.\n";
}
