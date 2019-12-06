package com.example.teste.model;

import javax.persistence.Column;
import javax.persistence.Entity;
import javax.persistence.GeneratedValue;
import javax.persistence.Id;
 
@Entity
public class Contato {
   
    @Id
    @GeneratedValue
    private Integer id;
    @Column(columnDefinition="text")
    private String nome;
    @Column(columnDefinition="text")
    private String endereco;
    @Column(columnDefinition="text")
    private String email;
    @Column(columnDefinition="text")
    private String telefones;
    
    public Contato() {
       
    }

	public Contato(Integer id, String nome, String endereco, String email, String telefones) {
		super();
		this.id = id;
		this.nome = nome;
		this.endereco = endereco;
		this.email = email;
		this.telefones = telefones;
	}

	public Integer getId() {
		return id;
	}

	public void setId(Integer id) {
		this.id = id;
	}

	public String getNome() {
		return nome;
	}

	public void setNome(String nome) {
		this.nome = nome;
	}

	public String getEndereco() {
		return endereco;
	}

	public void setEndereco(String endereco) {
		this.endereco = endereco;
	}

	public String getEmail() {
		return email;
	}

	public void setEmail(String email) {
		this.email = email;
	}

	public String getTelefones() {
		return telefones;
	}

	public void setTelefones(String telefones) {
		this.telefones = telefones;
	}

	@Override
	public String toString() {
		return "Contato [id=" + id + ", nome=" + nome + ", endereco=" + endereco + ", email=" + email + ", telefones="
				+ telefones + "]";
	}
	
}