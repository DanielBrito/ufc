package com.example.teste.repository;

import org.springframework.data.jpa.repository.JpaRepository;
import org.springframework.data.jpa.repository.Query;

import com.example.teste.model.Contato;

public interface ContatoRepository extends JpaRepository<Contato, Integer> {
	@Query("from Contato where nome = ?1")
	Contato findByNome(String nome);
}
