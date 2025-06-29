#include "calculo.h"
#include <iostream>
#include <cmath>
#include <limits>

double Calculo::calcularDistanciaEuclidiana(const Local& local1, const Local& local2) {
    int deltaX = local1.getCoordXLocal() - local2.getCoordXLocal();
    int deltaY = local1.getCoordYLocal() - local2.getCoordYLocal();
    return sqrt(deltaX * deltaX + deltaY * deltaY);
}

Veiculo* Calculo::encontrarVeiculoMaisProximo(const std::vector<Veiculo>& veiculos, const Local& localOrigem) {
    Veiculo* veiculoMaisProximo = nullptr;
    double menorDistancia = std::numeric_limits<double>::max();

    for (auto& veiculo : const_cast<std::vector<Veiculo>&>(veiculos)) {
        if (veiculo.getDisponibilidade()) {
            Local localVeiculo = veiculo.getLocalAtual();
            double distancia = calcularDistanciaEuclidiana(localVeiculo, localOrigem);
            if (distancia < menorDistancia) {
                menorDistancia = distancia;
                veiculoMaisProximo = &veiculo;
            }
        }
    }

    return veiculoMaisProximo;
}

void Calculo::calcularRotaEntrega(std::vector<Pedido>& pedidos, std::vector<Veiculo>& veiculos) {
    if (pedidos.empty()) {
        std::cout << "\nNenhum pedido foi cadastrado." << std::endl;
        return;
    }

    std::cout << "\n===== PEDIDOS PENDENTES =====" << std::endl;
    int contador = 1;
    for (const auto& pedido : pedidos) {
        if (!pedido.getPendente()) continue;

        std::cout << "\nPedido " << contador << ":" << std::endl;
        std::cout << "ID: " << pedido.getIdentificadorUnico() << std::endl;
        std::cout << "Origem: " << pedido.getLocalOrigem()->getNomeLocal() << std::endl;
        std::cout << "Destino: " << pedido.getLocalDestino()->getNomeLocal() << std::endl;
        std::cout << "Peso: " << pedido.getPesoItem() << " kg" << std::endl;
        contador++;
    }

    int escolhaPedido;
    std::cout << "\nEscolha o número do pedido para calcular a rota: ";
    std::cin >> escolhaPedido;

    if (escolhaPedido < 1 || escolhaPedido > (int)pedidos.size()) {
        std::cout << "\nPedido inválido!" << std::endl;
        return;
    }

    Pedido& pedidoSelecionado = pedidos[escolhaPedido - 1];
    Veiculo* veiculoMaisProximo = encontrarVeiculoMaisProximo(veiculos, *pedidoSelecionado.getLocalOrigem());

    if (veiculoMaisProximo == nullptr) {
        std::cout << "\nNenhum veículo disponível encontrado!" << std::endl;
        return;
    }

    Local localVeiculo = veiculoMaisProximo->getLocalAtual();
    double distanciaVeiculoOrigem = calcularDistanciaEuclidiana(localVeiculo, *pedidoSelecionado.getLocalOrigem());
    double distanciaOrigemDestino = calcularDistanciaEuclidiana(*pedidoSelecionado.getLocalOrigem(), *pedidoSelecionado.getLocalDestino());
    double distanciaTotal = distanciaVeiculoOrigem + distanciaOrigemDestino;

    std::cout << "\n===== ROTA DE ENTREGA CALCULADA =====" << std::endl;
    std::cout << "Veículo selecionado: " << veiculoMaisProximo->getPlaca() << " (" << veiculoMaisProximo->getModelo() << ")" << std::endl;
    std::cout << "Local atual do veículo: " << localVeiculo.getNomeLocal() << std::endl;
    std::cout << "Local de origem do pedido: " << pedidoSelecionado.getLocalOrigem()->getNomeLocal() << std::endl;
    std::cout << "Local de destino do pedido: " << pedidoSelecionado.getLocalDestino()->getNomeLocal() << std::endl;
    std::cout << "Distância até a origem: " << distanciaVeiculoOrigem << " unidades" << std::endl;
    std::cout << "Distância origem-destino: " << distanciaOrigemDestino << " unidades" << std::endl;
    std::cout << "Distância total percorrida: " << distanciaTotal << " unidades" << std::endl;

    char confirmar;
    std::cout << "\nDeseja simular a entrega? (s/n): ";
    std::cin >> confirmar;

    if (confirmar == 's' || confirmar == 'S') {
        veiculoMaisProximo->setDisponibilidade(false);
        std::cout << "\nSimulando entrega..." << std::endl;
        std::cout << "Veículo " << veiculoMaisProximo->getPlaca() << " agora está OCUPADO." << std::endl;

        pedidoSelecionado.setPendente(false);
        std::cout << "Entrega concluída com sucesso!" << std::endl;

        veiculoMaisProximo->setLocalAtual(*pedidoSelecionado.getLocalDestino());
        veiculoMaisProximo->setDisponibilidade(true);

        std::cout << "Veículo " << veiculoMaisProximo->getPlaca() << " agora está DISPONÍVEL." << std::endl;
        std::cout << "Local atual do veículo atualizado para: " << pedidoSelecionado.getLocalDestino()->getNomeLocal() << std::endl;

        // Remove pedido da lista
        pedidos.erase(pedidos.begin() + (escolhaPedido - 1));
        std::cout << "Pedido removido da lista de pendentes." << std::endl;
    }
}
