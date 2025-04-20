package br.com.locadora.cliente;

import java.util.Scanner;
import java.util.ArrayList;

import br.com.locadora.pessoa.Pessoa;

public class Cliente extends Pessoa {

    private String produto;
    private static ArrayList<Cliente> clientes = new ArrayList<>();


    public void setProduto(String produto) {

        if (produto == null || produto.trim().isEmpty()) {
            System.out.println("Insira alguma coisa");
            return;
        }

        else {
            this.produto = produto;
        }
        
    }

    public String getProduto() {
        return produto;
    }

    public Cliente(String nome, String cpf, String produto) {
        setNome(nome);
        setCpf(cpf);
        setProduto(produto);
    }

    public static void cadastrarCliente() {

        Scanner entrada = new Scanner(System.in);

        System.out.println("Insira o nome do cliente");
        String nome = entrada.nextLine();

        System.out.println("Insira o cpf do cliente");
        String cpf = entrada.nextLine();

        System.out.println("Insira o veiculo do cliente");
        String cargo = entrada.nextLine();

        entrada.close();

        Cliente novoCliente = new Cliente(nome, cpf, cargo);

        clientes.add(novoCliente);

        System.out.println("<---CLIENTE CADASTRADO--->");
        System.out.println("Nome: " + novoCliente.getNome());
        System.out.println("CPF: " + novoCliente.getCpf());
        System.out.println("Cargo: " + novoCliente.getProduto());

    }

    public static void removerCliente() {
        Scanner entrada = new Scanner(System.in);
        String removerNome = entrada.nextLine();

        for (Cliente removerCliente : clientes) {
            if(removerCliente.getNome().equals(removerNome)) {
                clientes.remove(removerCliente);
                System.out.println("Cliente removido com sucesso");
            }
        }

        entrada.close();
    }

    public static void listarClientes() {
        for (Cliente listar : clientes) {
            listar.getNome();
            listar.getCpf();
            listar.getProduto();
        }
    }

}
