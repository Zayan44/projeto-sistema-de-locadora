#include "local.h"
#include "veiculo.h"
#include "pedido.h"
#include "calculo.h"

#include <iostream>
#include <locale>
#include <vector>

using namespace std;

void menuLocal()
{

    int comando;

    do
    {
        cout << endl
             << "========== MENU LOCAL ==========" << endl
             << "1. Cadastrar local" << endl
             << "2. Listar locais" << endl
             << "3. Atualizar local" << endl
             << "4. Deletar local" << endl
             << "0. Retornar ao menu anterior" << endl;

        cin >> comando;

        switch (comando)
        {
        case 1:
            Local::cadastroLocal();
            break;

        case 2:
            Local::listarLocal();
            break;

        case 3:
            Local::atualizacaoLocal();
            break;

        case 4:
            Local::deletarLocal();
            break;

        case 0:
            return;
            break;
        }
    } while (true);
}

void menuVeiculo()
{
    int comando;

    do
    {
        cout << endl
             << "========== MENU VEÍCULO ==========" << endl
             << "1. Cadastrar veículo" << endl
             << "2. Listar veículos" << endl
             << "3. Atualizar veículos" << endl
             << "4. Deletar veículo" << endl
             << "0. Retornar ao menu anterior" << endl;

        cin >> comando;

        switch (comando)
        {
        case 1:
            Veiculo::cadastrarVeiculo();
            break;

        case 2:
            Veiculo::listarVeiculo();
            break;

        case 3:
            Veiculo::atualizarVeiculo();
            break;

        case 4:
            Veiculo::deletarVeiculo();
            break;

        case 0:
            return;

        default:
            cout << "Opção inválida. Tente novamente." << endl;
        }
    } while (true);
}

void menuPedido()
    {
        int comando;

        do
        {
            cout << endl
                 << "========== MENU PEDIDOS ==========" << endl
                 << "1. Cadastrar pedido" << endl
                 << "2. Listar pedidos" << endl
                 << "3. Atualizar pedido" << endl
                 << "4. Deletar pedido" << endl
                 << "0. Retornar ao menu anterior" << endl;

            cin >> comando;

            switch (comando)
            {
            case 1:
                Pedido::cadastroPedido();
                break;

            case 2:
                Pedido::listarPedidos();
                break;

            case 3:
                Pedido::atualizacaoPedido();
                break;

            case 4:
                Pedido::deletarPedido();
                break;

            case 0:
                return;
                break;
            }
        } while (true);
    }

void menuCalculo()
    {
        int comando;

        do
        {
            cout << endl
                 << "========== MENU CÁLCULO DE ROTA ==========" << endl
                 << "1. Calcular e Executar Rota de Entrega" << endl
                 << "2. Visualizar Veículos Disponíveis" << endl
                 << "3. Visualizar Pedidos Pendentes" << endl
                 << "0. Retornar ao menu anterior" << endl;

            cin >> comando;

            switch (comando)
            {
            case 1:
                    Calculo::calcularRotaEntrega(Pedido::getPedidos(), Veiculo::getVeiculos());
                break;

            case 2:
{
               cout << "\n===== VEÍCULOS DISPONÍVEIS =====\n";
            bool encontrou = false;
            for (const auto& v : Veiculo::getVeiculos()) {
                if (v.getDisponibilidade()) {
                    cout << "Placa: " << v.getPlaca()
                         << ", Modelo: " << v.getModelo()
                         << ", Local: " << v.getLocalAtual().getNomeLocal() << "\n";
                    encontrou = true;
                }
            }
            if (!encontrou) cout << "Nenhum veículo disponível.\n";
            break;
        }
            case 3:
                Pedido::listarPedidos();
                break;

            case 0:
                return;

            default:
                cout << "Opção inválida!" << endl;
            }
        } while (true);
    }

int main()
    {
        int comando;

        do
        {
            cout << endl
                 << "========== MENU PRINCIPAL ==========" << endl
                 << "1. Gerenciar Locais" << endl
                 << "2. Gerenciar Veículos" << endl
                 << "3. Gerenciar Pedidos" << endl
                 << "4. Calcular e Executar Rota de Entrega" << endl
                 << "5. Backup de Dados" << endl
                 << "6. Restaurar Dados" << endl
                 << "7. Sair" << endl;

            cin >> comando;

            switch (comando)
            {

            case 1:
                menuLocal();
                break;

            case 2:
                menuVeiculo();
                break;

            case 3:
                menuPedido();
                break;

            case 4:
                menuCalculo();
                break;
            case 7:
                cout << "Saindo do programa..." << endl;
                break;

            default:
                cout << "Opção inválida!" << endl;
                break;
            }
        } while (comando != 7);
    }