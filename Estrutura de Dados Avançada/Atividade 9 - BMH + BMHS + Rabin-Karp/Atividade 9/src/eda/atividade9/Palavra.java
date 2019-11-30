package eda.atividade9;

import java.util.Objects;

public class Palavra implements Comparable<Palavra> {
	
	private String palavra;
	private int quantidade;
	
	public Palavra(String palavra, int quantidade) {
		
		this.palavra = palavra;
		this.quantidade = quantidade;
	}

	public String getPalavra() {
		
		return palavra;
	}

	public void setPalavra(String palavra) {
		
		this.palavra = palavra;
	}

	public int getQuantidade() {
		
		return quantidade;
	}

	public void setQuantidade(int quantidade) {
		
		this.quantidade = quantidade;
	}

	@Override
	public String toString() {
		
		return palavra + ": " + quantidade;
	}

	@Override
    public boolean equals(Object o) {
		
        if (this==o) return true;
        
        if (o==null || getClass()!=o.getClass()) return false;
        
        Palavra p = (Palavra) o;
        
        return Double.compare(p.quantidade, quantidade)==0 && Objects.equals(p, p.palavra);
    }

    @Override
    public int hashCode() {
    	
        return Objects.hash(palavra, quantidade);
    }

    public int compareTo(Palavra p) {
    	
        if(this.getQuantidade() > p.getQuantidade()) {
        	
            return 1;
            
        } else if (this.getQuantidade() < p.getQuantidade()) {
        	
            return -1;
            
        } else {
        	
            return 0;
        }
    }
}
