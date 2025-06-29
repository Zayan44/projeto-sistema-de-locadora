#include "pedido.h"
#include "local.h"
#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

vector<Pedido> Pedido::pedidos;

int Pedido::proximoId = 1;

// Construtores
Pedido::Pedido() {
    identificadorUnico = 0;
    localOrigem = nullptr;
    localDestino = nullptr;
    pesoItem = 0.0;
}

Pedido::Pedido(Local* origem, Local* destino, double peso) {
    identificadorUnico = proximoId++;
    localOrigem = origem;
    localDestino = destino;
    pesoItem = peso;
}

// Getters
int Pedido::getIdentificadorUnico() const {
    return identificadorUnico;
}

Local* Pedido::getLocalOrigem() const {
    return localOrigem;
}

Local* Pedido::getLocalDestino() const {
    return localDestino;
}

double Pedido::getPesoItem() const {
    return pesoItem;
}

vector<Pedido>& Pedido::getPedidos() {
    return pedidos;
}

bool Pedido::getPendente() const {
    return pendente;
}

// Setters
void Pedido::setLocalOrigem(Local* origem) {
    localOrigem = origem;
}

void Pedido::setLocalDestino(Local* destino) {
    localDestino = destino;
}

void Pedido::setPesoItem(double peso) {
    pesoItem = peso;
}

void Pedido::setPendente(bool status) {
    pendente = status;
}

// Função auxiliar para encontrar local por nome
Local* Pedido::encontrarLocalPorNome(const char* nomeLocal) {
    vector<Local>& locais = Local::getLocais();
    
    for (auto& local : locais) {
        if (strcmp(local.getNomeLocal(), nomeLocal) == 0) {
            return &local;
        }
    }
    return nullptr;
}

// Marca o pedido como entregue
void Pedido::marcarComoEntregue() {
    pendente = false;
}

// Função para cadastro de pedidos
void Pedido::cadastroPedido() {
    char nomeOrigem[200];
    char nomeDestino[200];
    double peso;
    
    cout << endl << "========== CADASTRO DE PEDIDO ==========" << endl;
    
    // Verificar se existem locais cadastrados
    if (Local::getLocais().empty()) {
        cout << "Erro: Nenhum local foi cadastrado. Cadastre locais primeiro." << endl;
        return;
    }
    
    cout << "Locais disponíveis:" << endl;
    Local::listarLocal();
    
    cout << endl << "Insira o endereco de origem:" << endl;
    cin.ignore();
    cin.getline(nomeOrigem, 200);
    
    Local* origem = encontrarLocalPorNome(nomeOrigem);
    if (origem == nullptr) {
        cout << "Erro: Local de origem não encontrado." << endl;
        return;
    }
    
    cout << endl << "Insira o endereco de destino:" << endl;
    cin.getline(nomeDestino, 200);
    
    Local* destino = encontrarLocalPorNome(nomeDestino);
    if (destino == nullptr) {
        cout << "Erro: Local de destino não encontrado." << endl;
        return;
    }
    
    if (origem == destino) {
        cout << "Erro: Local de origem e destino não podem ser iguais." << endl;
        return;
    }
    
    cout << endl << "Insira o peso do item (em kg):" << endl;
    cin >> peso;
    
    if (peso <= 0) {
        cout << "Erro: O peso deve ser maior que zero." << endl;
        return;
    }
    
    Pedido novoPedido(origem, destino, peso);
    pedidos.push_back(novoPedido);
    
    cout << endl << "Pedido cadastrado com sucesso!" << endl;
    cout << "ID do pedido: " << novoPedido.getIdentificadorUnico() << endl;
}

// Função para listar pedidos
void Pedido::listarPedidos() {
    cout << endl << "========== LISTA DE PEDIDOS ==========" << endl;
    
    if (pedidos.empty()) {
        cout << "Nenhum pedido foi cadastrado." << endl;
        return;
    }
    
    for (const auto& pedido : pedidos) {
        cout << endl << "ID: " << pedido.getIdentificadorUnico() << endl;
        cout << "Origem: " << pedido.getLocalOrigem()->getNomeLocal() << endl;
        cout << "Destino: " << pedido.getLocalDestino()->getNomeLocal() << endl;
        cout << "Peso: " << pedido.getPesoItem() << " kg" << endl;
        cout << "----------------------------------------" << endl;
    }
}

// Função para atualização de pedidos
void Pedido::atualizacaoPedido() {
    int id;
    
    cout << endl << "========== ATUALIZAR PEDIDO ==========" << endl;
    
    if (pedidos.empty()) {
        cout << "Nenhum pedido foi cadastrado." << endl;
        return;
    }
    
    cout << "Insira o ID do pedido que deseja atualizar:" << endl;
    cin >> id;
    
    // Encontrar o pedido pelo ID
    Pedido* pedidoEncontrado = nullptr;
    for (auto& pedido : pedidos) {
        if (pedido.getIdentificadorUnico() == id) {
            pedidoEncontrado = &pedido;
            break;
        }
    }
    
    if (pedidoEncontrado == nullptr) {
        cout << "Pedido com ID " << id << " não encontrado." << endl;
        return;
    }
    
    cout << "Pedido encontrado:" << endl;
    cout << "ID: " << pedidoEncontrado->getIdentificadorUnico() << endl;
    cout << "Origem: " << pedidoEncontrado->getLocalOrigem()->getNomeLocal() << endl;
    cout << "Destino: " << pedidoEncontrado->getLocalDestino()->getNomeLocal() << endl;
    cout << "Peso: " << pedidoEncontrado->getPesoItem() << " kg" << endl;
    
    int opcao;
    do {
        cout << endl << "O que deseja atualizar?" << endl;
        cout << "1. Local de origem" << endl;
        cout << "2. Local de destino" << endl;
        cout << "3. Peso do item" << endl;
        cout << "0. Voltar" << endl;
        cin >> opcao;
        
        switch (opcao) {
            case 1: {
                char novoNomeOrigem[200];
                cout << "Locais disponíveis:" << endl;
                Local::listarLocal();
                cout << "Insira o novo endereco de origem:" << endl;
                cin.ignore();
                cin.getline(novoNomeOrigem, 200);
                
                Local* novaOrigem = encontrarLocalPorNome(novoNomeOrigem);
                if (novaOrigem == nullptr) {
                    cout << "Erro: Local não encontrado." << endl;
                } else if (novaOrigem == pedidoEncontrado->getLocalDestino()) {
                    cout << "Erro: Local de origem não pode ser igual ao destino." << endl;
                } else {
                    pedidoEncontrado->setLocalOrigem(novaOrigem);
                    cout << "Local de origem atualizado com sucesso!" << endl;
                }
                break;
            }
            case 2: {
                char novoNomeDestino[200];
                cout << "Locais disponíveis:" << endl;
                Local::listarLocal();
                cout << "Insira o novo endereco de destino:" << endl;
                cin.ignore();
                cin.getline(novoNomeDestino, 200);
                
                Local* novoDestino = encontrarLocalPorNome(novoNomeDestino);
                if (novoDestino == nullptr) {
                    cout << "Erro: Local não encontrado." << endl;
                } else if (novoDestino == pedidoEncontrado->getLocalOrigem()) {
                    cout << "Erro: Local de destino não pode ser igual à origem." << endl;
                } else {
                    pedidoEncontrado->setLocalDestino(novoDestino);
                    cout << "Local de destino atualizado com sucesso!" << endl;
                }
                break;
            }
            case 3: {
                double novoPeso;
                cout << "Insira o novo peso (em kg):" << endl;
                cin >> novoPeso;
                
                if (novoPeso <= 0) {
                    cout << "Erro: O peso deve ser maior que zero." << endl;
                } else {
                    pedidoEncontrado->setPesoItem(novoPeso);
                    cout << "Peso atualizado com sucesso!" << endl;
                }
                break;
            }
            case 0:
                cout << "Voltando ao menu anterior..." << endl;
                break;
            default:
                cout << "Opção inválida!" << endl;
                break;
        }
    } while (opcao != 0);
}

// Função para deletar pedidos
void Pedido::deletarPedido() {
    int id;
    
    cout << endl << "========== DELETAR PEDIDO ==========" << endl;
    
    if (pedidos.empty()) {
        cout << "Nenhum pedido foi cadastrado." << endl;
        return;
    }
    
    cout << "Insira o ID do pedido que deseja deletar:" << endl;
    cin >> id;
    
    // Encontrar e remover o pedido pelo ID
    for (auto it = pedidos.begin(); it != pedidos.end(); ++it) {
        if (it->getIdentificadorUnico() == id) {
            cout << "Pedido deletado com sucesso!" << endl;
            cout << "ID: " << it->getIdentificadorUnico() << endl;
            cout << "Origem: " << it->getLocalOrigem()->getNomeLocal() << endl;
            cout << "Destino: " << it->getLocalDestino()->getNomeLocal() << endl;
            cout << "Peso: " << it->getPesoItem() << " kg" << endl;
            
            pedidos.erase(it);
            return;
        }
    }
    
    cout << "Pedido com ID " << id << " não encontrado." << endl;
}
