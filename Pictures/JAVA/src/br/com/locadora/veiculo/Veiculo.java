package br.com.locadora.veiculo;

import java.util.Scanner;
import java.util.ArrayList;

public class Veiculo {
    private String veiculo;
    private String cor;
    private String placa;
    private static ArrayList<Veiculo> veiculos = new ArrayList<>();

    public void setVeiculo(String veiculo) {

        this.veiculo = veiculo;
    }

    public void setCor(String cor) {
        this.cor = cor;
    }

    public void setPlaca(String placa) {
        this.placa = placa;
    }

    public String getVeiculo() {
        return this.veiculo;
    }

    public String getCor() {
        return this.cor;
    }

    public String getPlaca() {
        return this.placa;
    }

    public Veiculo(String veiculo, String cor, String placa) {
        setVeiculo(veiculo);
        setCor(cor);
        setPlaca(placa);
    };

    public static void cadastrarVeiculo() {
        Scanner entrada = new Scanner(System.in);

        String veiculo = entrada.nextLine();
        String cor = entrada.nextLine();
        String placa = entrada.nextLine();

        entrada.close();

        Veiculo novoVeiculo = new Veiculo(veiculo, cor, placa);

        veiculos.add(novoVeiculo);

        System.out.println("Veiculo adicionado com sucesso\n\nVeículo: " + novoVeiculo.getVeiculo() + "\nCor: "
                + novoVeiculo.getCor() + "\nPlaca: " + novoVeiculo.getPlaca());
    }

    public static void removerVeiculo() {
        Scanner entrada = new Scanner(System.in);

        System.out.print("Insira a placa do veiculo a ser removido: ");
        String removerVeiculo = entrada.nextLine();

        entrada.close();
        for (Veiculo remover : veiculos) {

            if (remover.getPlaca().equals(removerVeiculo)) {
                veiculos.remove(remover);
                System.out.println("Veiculo removido com sucesso");
            }
        }
    }

    public static void listarVeiculos() {

        System.out.println("Lista de veículos cadastrados\n");
        for (Veiculo listarVeiculo : veiculos) {
            System.out.println(listarVeiculo.getVeiculo());
            System.out.println(listarVeiculo.getCor());
            System.out.println(listarVeiculo.getPlaca() + "\n");
        }

    }
}
