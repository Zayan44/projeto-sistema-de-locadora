package br.com.locadora.pessoa;


public class Pessoa {

    // Atributos

    protected String nome;
    protected String cpf;

    // Métodos

    protected void setNome(String nome) {

        if (nome.trim().isEmpty()) {
            System.out.println("Valor do Nome inválido");
            return;
        } else {
            this.nome = nome;
        }

    }

    protected void setCpf(String cpf) {

        if (cpf.trim().isEmpty() || cpf.length() != 11 ) {
            System.out.println("Valor do CPF inválido");
            return;
        }
        
         else {
            this.cpf = cpf;
        }
    }

    protected String getNome() {
        return this.nome;
    }

    protected String getCpf() {
        return this.cpf;
    }

}