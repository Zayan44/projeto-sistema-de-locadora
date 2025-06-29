#ifndef PEDIDO_H
#define PEDIDO_H

#include <vector>

class Local; // Declaração antecipada para evitar dependência circular

class Pedido {
private:
    // Atributos
    int identificadorUnico;
    Local* localOrigem;      // Referência ao local de origem
    Local* localDestino;     // Referência ao local de destino
    double pesoItem;         // Peso do item em kg
    bool pendente = true;
    
    static std::vector<Pedido> pedidos;  // Vetor estático de pedidos
    static int proximoId;               // Contador para gerar IDs únicos

public:
    // Construtores
    Pedido();
    Pedido(Local* origem, Local* destino, double peso);

    // Getters
    int getIdentificadorUnico() const;
    Local* getLocalOrigem() const;
    Local* getLocalDestino() const;
    double getPesoItem() const;
    bool getPendente() const;  

    static std::vector<Pedido>& getPedidos();

    // Setters
    void setLocalOrigem(Local* origem);
    void setLocalDestino(Local* destino);
    void setPesoItem(double peso);
    void setPendente(bool status);  // Define se o pedido está pendente ou não
    // Operações do sistema de pedidos
    
    void marcarComoEntregue();  
    
    static void cadastroPedido();
    static void listarPedidos();
    static void atualizacaoPedido();
    static void deletarPedido();

    // Função auxiliar para encontrar local por nome
    static Local* encontrarLocalPorNome(const char* nomeLocal);
};

#endif