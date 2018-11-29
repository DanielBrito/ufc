package com.br.exe4;

public class RepositorioDisciplinas implements Colecao {
	
	public String disciplinas[] = {"Análise e Projeto de Sistemas", 
			                       "Álgebra Linear", 
			                       "Matemática Discreta",
			                       "Linguagens de Programação",
			                       "Linguagens Formais e Autômatos",
			                       "Probabilidade e Estatística"};

	@Override
	public Iterator getIterator() {

		return new IteratorDisciplinas();
	}
	
	private class IteratorDisciplinas implements Iterator{
		
		int index;
		
		@Override
		public boolean hasNext() {
			
			if(index<disciplinas.length) {
				
				return true;
			}
			
			return false;
		}

		@Override
		public Object next() {

			if(this.hasNext()) {
				
				return disciplinas[index++];
			}
			
			return null;
		}
	}
}