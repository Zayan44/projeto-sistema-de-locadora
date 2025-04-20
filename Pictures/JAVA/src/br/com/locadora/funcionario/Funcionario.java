package br.com.locadora.funcionario;

import java.util.Scanner;
import java.util.ArrayList;
import br.com.locadora.pessoa.Pessoa;

public class Funcionario extends Pessoa {
    private String cargo;
    private static ArrayList<Funcionario> funcionarios = new ArrayList<>();

    public String getCargo() {
        return cargo;
    }

    public void setCargo(String cargo) {
        this.cargo = cargo;
    }

    public Funcionario(String nome, String cpf, String cargo) {
        setNome(nome);
        setCpf(cpf);
        setCargo(cargo);
    };

    public static void cadastrarFuncionario() {

        Scanner entrada = new Scanner(System.in);

        System.out.println("Insira o nome do funcionário");
        String nome = entrada.nextLine();

        System.out.println("Insira o cpf funcionário");
        String cpf = entrada.nextLine();

        System.out.println("Insira o cargo do funcionário");
        String cargo = entrada.nextLine();

        entrada.close();

        Funcionario novoFuncionario = new Funcionario(nome, cpf, cargo);

        funcionarios.add(novoFuncionario);

        System.out.println("<---FUNCIONÁRIO CADASTRADO--->");
        System.out.println("Nome: " + novoFuncionario.getNome());
        System.out.println("CPF: " + novoFuncionario.getCpf());
        System.out.println("Cargo: " + novoFuncionario.getCargo());

    }

    public static void listarFuncionarios() {
        for (Funcionario listar : funcionarios) 
        {
            System.out.println(listar.getNome());
            System.out.println(listar.getCpf());
            System.out.println(listar.getCargo());
        }
    }

    public static void removerFuncionario() {
        
        Scanner entrada = new Scanner(System.in);

        String nomeBater = entrada.nextLine();

        entrada.close();

        for (Funcionario remover : funcionarios) {
            if (nomeBater.equals(remover.getNome())) {
                funcionarios.remove(remover);
            }
        }
    }

    
}
