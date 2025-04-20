package br.com.locadora.main;

import java.util.Scanner;

import br.com.locadora.cliente.*;
import br.com.locadora.funcionario.*;
import br.com.locadora.veiculo.*;

public class Main {

    public static void main(String[] args) {
        int comando;

        Scanner entrada = new Scanner(System.in);

        System.out.println("<---Sistema de Locação de Veículos--->\n");
        System.out.println("Selecione a opção desejada\n");

        System.out.println("1 - Cadastro de Funcionário\n2 - Cadastro de Cliente\n3 - Cadastro de Veículo\n4 - Alugar Veículo\n5 - Listar Funcionários\n6 - Listar Clientes\n7 - Listar Veículos\n8 - Remover Funcionário\n9 - Remover Cliente\n10 - Remover Veículo\n11 - Acompanhar Veículos Alugados");

        do {

            comando = entrada.nextInt();

            switch (comando) {
                
                case 1:
                         Funcionario.cadastrarFuncionario();
                    break;

                case 2:
                         Cliente.cadastrarCliente();
                    break;

                case 3:
                          Veiculo.cadastrarVeiculo();
                    break;

                case 4:
                           Veiculo.alugarVeiculo();
                    break;

                case 5:
                          Funcionario.listarFuncionarios();
                    break;

                case 6:
                        Cliente.listarClientes();
                    break;

                case 7:
                        Veiculo.listarVeiculos();
                    break;

                case 8:
                        Funcionario.removerFuncionario();
                    break;

                case 9:
                        Cliente.removerCliente();
                    break;

                case 10:
                        Veiculo.removerVeiculo();
                    break;

                case 11:
                        Alugado.listarAlugados();
                    break;
            }

        } while (comando < 1 || comando > 11);

    }

}
