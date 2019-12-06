package com.example.teste.controller;

import java.io.IOException;
import java.util.List;
import java.util.Optional;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.http.HttpStatus;
import org.springframework.http.ResponseEntity;
import org.springframework.web.bind.annotation.CrossOrigin;
import org.springframework.web.bind.annotation.PathVariable;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RequestMethod;
import org.springframework.web.bind.annotation.RequestParam;
import org.springframework.web.bind.annotation.RestController;
import org.springframework.web.multipart.MultipartFile;

import com.example.teste.model.Contato;
import com.example.teste.repository.ContatoRepository;
import com.example.teste.util.Upload;
//import com.example.teste.util.Upload;

@RestController
@RequestMapping(path = "/api/contatos")
@CrossOrigin
public class ContatoService {
	@Autowired
    private ContatoRepository contatos;
 
    @RequestMapping(method = RequestMethod.GET)
    public ResponseEntity<List<Contato>> getContatos() {
        return new ResponseEntity<List<Contato>>(contatos.findAll(), HttpStatus.OK);
        //return new ResponseEntity<List<Curso>>(cursos.findAll(new Sort(Sort.Direction.ASC, "id")), HttpStatus.OK);
    }
 
    @RequestMapping(value = "{id}", method = RequestMethod.GET)
    public ResponseEntity<Contato> getContato(@PathVariable("id") Integer id) {
        Optional<Contato> curso = contatos.findById(id);
 
        if (curso.isPresent()) {
            return new ResponseEntity<Contato>(curso.get(), HttpStatus.OK);
        } else {
            return new ResponseEntity<>(HttpStatus.NOT_FOUND);
        }      
    }
   
    @RequestMapping(value = "/search", method = RequestMethod.GET)
    public ResponseEntity<Contato> getContato(@RequestParam("nome") String nome) {
        System.out.println(nome);
        Contato curso = contatos.findByNome(nome);
 
        if (curso != null) {
            return new ResponseEntity<Contato>(curso, HttpStatus.OK);
        } else {
            return new ResponseEntity<>(HttpStatus.NOT_FOUND);
        }
    }
 
    @RequestMapping(method = RequestMethod.POST)
    public ResponseEntity<Contato> addContato(String nome, String endereco, String email, String telefones, MultipartFile image) {
       
    	System.out.println("OLAAAAA");
    	System.out.println();
    	System.out.println();
    	/*if (nome == null || endereco == null || nome.equals("null") || endereco.equals("null") || image == null) {
            return new ResponseEntity<>(HttpStatus.NOT_FOUND);
        }*/
        Contato contato = new Contato(null, nome, endereco, email, telefones);
        Contato contatoAux = contatos.save(contato);
        
        try {
            Upload.uploadFile(image.getInputStream(), contatoAux.getId());
        } catch (IOException e) {
            e.printStackTrace();
        }
 
        return new ResponseEntity<Contato>(contatoAux, HttpStatus.OK);
    }
 
    @RequestMapping(value = "{id}", method = RequestMethod.PUT)
    public ResponseEntity<Contato> atualizarContato(@PathVariable("id") int id, String nome, String endereco, String email, String telefones,
            MultipartFile image) {
        /*if (nome == null || endereco == null || nome.equals("null") || endereco.equals("null")) {
            return new ResponseEntity<>(HttpStatus.NOT_FOUND);
        }*/
        Optional<Contato> curso = contatos.findById(id);
 
        if (curso.isPresent()) {
            curso.get().setNome(nome);
            curso.get().setEndereco(endereco);
            curso.get().setEmail(email);
            curso.get().setTelefones(telefones);
            contatos.save(curso.get());
            
            try {
                if (image != null) {
                    Upload.uploadFile(image.getInputStream(), id);
                }
            } catch (IOException e) {
                e.printStackTrace();
            }
 
            return new ResponseEntity<Contato>(curso.get(), HttpStatus.OK);
        } else {
            return new ResponseEntity<>(HttpStatus.NOT_FOUND);
        }
    }
 
    @RequestMapping(value = "{id}", method = RequestMethod.DELETE)
    public ResponseEntity<?> deletarContato(@PathVariable("id") int id) {
        if(contatos.existsById(id)) {
            contatos.deleteById(id);
            return new ResponseEntity<>(HttpStatus.NO_CONTENT);
        } else {
            return new ResponseEntity<>(HttpStatus.NOT_FOUND);
        }
    }

}
