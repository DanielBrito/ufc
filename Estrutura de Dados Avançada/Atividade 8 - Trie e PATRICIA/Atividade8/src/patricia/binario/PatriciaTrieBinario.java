package patricia.binario;

public class PatriciaTrieBinario {
	
	PatriciaNoBinario raiz = null;
	
	public class PatriciaNoBinario {
		
		int index;
		PatriciaNoBinario esq, dir;
		String chave;
		
		public PatriciaNoBinario() {
			
			index = 0;
			esq = null;
			dir = null;
			chave = null;
		}
		
		public PatriciaNoBinario(String palavra, int i) {
			
			index = i;
			esq = null;
			dir = null;
			chave = palavra;
		}
	}
	
	public boolean procurar(String palavra) {
		
		if (palavra == null || raiz == null) {
			
			return false;
		}
		
		return procurar(palavra, raiz);
	}
	
	public boolean procurar(String palavra, PatriciaNoBinario no) {
		
		if (no == null) {
			
			return false;
		}

		if (no.chave == null) {
			
			if (no.index >= palavra.length()) {
				
				return false;
				
			} 
			else 
			if (palavra.charAt(no.index) == '0') {
				
				return procurar(palavra, no.esq);
			} 
			else {
				
				return procurar(palavra, no.dir);
			}
		} 
		else {
			
			if (palavra.equals(no.chave) && palavra.length() == no.chave.length()) {
				
				return true;
			} 
			else {
				
				int tamanho = Math.min(no.chave.length(), palavra.length());
				int indexDiferenca = -1;
				
				for (int i=0; i<tamanho; i++) {
					
					if (no.chave.charAt(i) != palavra.charAt(i)) {
						
						indexDiferenca = i;
						
						break;
					}
				}
				if (indexDiferenca==-1) {
					
					if (palavra.length() >= no.chave.length()) {
						
						return (palavra.charAt(tamanho) == '0') ? procurar(palavra, no.esq) : procurar(palavra, no.dir);
					} 
					else {
						
						return false;
					}
				} 
				else {
					
					return (palavra.charAt(indexDiferenca) == '0') ? procurar(palavra, no.esq) : procurar(palavra, no.dir); 
				}
			}
		}
		
		
	}
	
	public boolean inserir(String palavra) {
		
		if (raiz == null) {
			
			raiz = new PatriciaNoBinario(palavra, palavra.length());
			
			return true;
		} 
		else 
		if (procurar(palavra) == true) {
			
			return false;
		}
		
		PatriciaNoBinario no = raiz;
		
		return inserir(palavra, no, null, 0, -1);
	}
	
	public boolean inserir(String palavra, PatriciaNoBinario no, PatriciaNoBinario anterior, int direcao, int nivelIndex) {
		
		if (no == null) {
			
			PatriciaNoBinario newNode = new PatriciaNoBinario(palavra, palavra.length());
			
			if (direcao == 0) {
				
				anterior.esq = newNode;
			} 
			else {
				
				anterior.dir = newNode;
			}
		} 
		else 
		if (no.chave == null) {

			if (no.index == palavra.length()) {
				
				int indexDiferenca = -1;
				PatriciaNoBinario stringNo = no;
				
				while (stringNo.chave == null) {
					
					stringNo = stringNo.esq;
				}
				
				for (int i = 0; i < palavra.length(); i++) {
					
					if (palavra.charAt(i) != stringNo.chave.charAt(i)) {
						
						indexDiferenca = i;
						
						break;
					}
				}
				
				PatriciaNoBinario novoNo = new PatriciaNoBinario(palavra, palavra.length());
				PatriciaNoBinario noDiferenca = new PatriciaNoBinario(null, indexDiferenca);
				
				if (indexDiferenca == -1) {
					
					no.chave = palavra;
					no.index = palavra.length();
				} 
				else {

					if (anterior != null) {
						
						if (direcao == 0) {
							
							anterior.esq = noDiferenca;
						} 
						else {
							
							anterior.dir = noDiferenca;
						}
						
						if (palavra.charAt(indexDiferenca) == '0') {
							
							noDiferenca.esq = novoNo;
							noDiferenca.dir = no;
							
						} 
						else {
							
							noDiferenca.esq = no;
							noDiferenca.dir = novoNo;
						}

					} 
					else {
						
						if (palavra.charAt(indexDiferenca) == '0') {
							
							noDiferenca.esq = novoNo;
							noDiferenca.dir = no;
						} 
						else {
							
							noDiferenca.esq = no;
							noDiferenca.dir = novoNo;
						}
						
						raiz = noDiferenca;
					}
				}
			} 
			else 
			if (no.index < palavra.length()) {
				
				int diferencaIndex = -1;
				PatriciaNoBinario stringNo = no;
				
				while (stringNo.chave == null) {
					
					stringNo = stringNo.esq;
				}
				
				for (int i = 0; i < no.index; i++) {
					
					if (palavra.charAt(i) != stringNo.chave.charAt(i)) {
						
						diferencaIndex = i;
						
						break;
					}
				}
				
				if (diferencaIndex == -1) {
					
					return (palavra.charAt(no.index) == '0') ? inserir(palavra, no.esq, no, 0, no.index) : inserir(palavra, no.dir, no, 1, no.index); 

				} else {
					
					PatriciaNoBinario novoNo = new PatriciaNoBinario(palavra, palavra.length());
					PatriciaNoBinario noDiferenca = new PatriciaNoBinario(null, diferencaIndex);
					
					if (diferencaIndex < no.index) {
						
						if (anterior != null) {
							
							if (palavra.charAt(diferencaIndex) == '0') {
								
								noDiferenca.esq = novoNo;
								noDiferenca.dir = no;
								
							} 
							else {
								
								noDiferenca.esq = no;
								noDiferenca.dir = novoNo;
							}
							if (direcao == 0) {
								
								anterior.esq = noDiferenca;
							} 
							else {
								
								anterior.dir = noDiferenca;
							}
						} 
						else {
							
							if (palavra.charAt(diferencaIndex) == '0') {
								
								noDiferenca.esq = novoNo;
								noDiferenca.dir = no;
							} 
							else {
								
								noDiferenca.esq = no;
								noDiferenca.dir = novoNo;
							}
							raiz = noDiferenca;
						}
					}
				}
			} 
			else {
				
				int indexDiferenca = -1;
				PatriciaNoBinario stringNo = no;
				
				while (stringNo.chave == null) {
					
					stringNo = stringNo.esq;	
				}
				
				for (int i = 0; i < palavra.length(); i++) {
					
					if (palavra.charAt(i) != stringNo.chave.charAt(i)) {
						
						indexDiferenca = i;
						
						break;
					}
				}
				
				PatriciaNoBinario newNode = new PatriciaNoBinario(palavra, palavra.length());
				
				if (indexDiferenca != -1) {
					
					PatriciaNoBinario noDiferenca = new PatriciaNoBinario(null, indexDiferenca);
					
					if (anterior == null) {
						
						if (palavra.charAt(indexDiferenca) == '0') {
							
							noDiferenca.esq = newNode;
							noDiferenca.dir = no;
							
						} else {
							
							noDiferenca.esq = no;
							noDiferenca.dir = newNode;
						}
						
						raiz = noDiferenca;
					} 
					else {
						
						if (palavra.charAt(indexDiferenca) == '0') {
							
							noDiferenca.esq = newNode;
							noDiferenca.dir = no;
						} 
						else {
							
							noDiferenca.esq = no;
							noDiferenca.dir = newNode;
						}
						
						if (direcao == 0) {
							
							anterior.esq = noDiferenca;
							
						} 
						else {
							
							anterior.dir = noDiferenca;
						}
					}
				} 
				else {
					
					if (anterior != null) {
						
						if (direcao == 0) {
							
							anterior.esq = newNode;
						} 
						else {
							
							anterior.dir = newNode;	
						}
					
						if (stringNo.chave.charAt(palavra.length()) == '0') {
							
							newNode.esq = no;
						} 
						else {
							
							newNode.dir = no;
						}
					} 
					else {
						
						if (anterior == null) {
							
							if (stringNo.chave.charAt(palavra.length()) == '0') {
								
								newNode.esq = no;
							} 
							else {
								
								newNode.dir = no;
							}
							
							raiz = newNode;
						}
					}
				}
			}
		} 
		else {
			
			int tamanho = Math.min(palavra.length(), no.chave.length());
			int indexDiferenca = -1;

			for (int i = 0; i < tamanho; i++) {
				
				if (palavra.charAt(i) != no.chave.charAt(i)) {
					
					indexDiferenca = i;
					
					break;
				}
			}

			if (indexDiferenca != -1) {
				
				PatriciaNoBinario noDiferenca = new PatriciaNoBinario(null, indexDiferenca);
				PatriciaNoBinario novoNo = new PatriciaNoBinario(palavra, palavra.length());
				
				if (palavra.charAt(indexDiferenca) == '0') {
					
					noDiferenca.esq = novoNo;
					noDiferenca.dir = no;
					
					if (anterior != null) {
						
						if (direcao == 0) {
							
							anterior.esq = noDiferenca;
						} 
						else {
							
							anterior.dir = noDiferenca;
						}
					}
					
					if (nivelIndex == -1) {
						
						raiz = noDiferenca;
					}
				} 
				else {
					
					noDiferenca.esq = no;
					noDiferenca.dir = novoNo;
					
					if (anterior != null) {
						
						if (direcao == 0) {
							
							anterior.esq = noDiferenca;
						} 
						else {
							
							anterior.dir = noDiferenca;
						}
					}
					
					if (nivelIndex == -1) {
						
						raiz = noDiferenca;
					}
				}
			} 
			else {
				
				PatriciaNoBinario novoNo = new PatriciaNoBinario(palavra, palavra.length());
				
				if (palavra.length() > no.chave.length()) { 
					
					return (no.chave.length() == '0') ? inserir(palavra, no.esq, no, 0, no.index) : inserir(palavra, no.dir, no, 1, no.index); 
									
				} else {
					
					if (no.chave.charAt(palavra.length()) == '0') {
						
						novoNo.esq = no;
						
						if (anterior != null) {
							
							if (direcao == 0) {
								
								anterior.esq = novoNo;
								
							} 
							else {
								
								anterior.dir = novoNo;
							}
						} 
						else {
							
							raiz = novoNo;
						}
					} 
					else {
						
						novoNo.dir = no;
						
						if (anterior != null) {
							
							if (direcao == 0) {
								
								anterior.esq = novoNo;
							} 
							else {
								
								anterior.dir = novoNo;
							}
						} 
						else {
							
							raiz = novoNo;
						}
					}
				}
			}
		}
		
		return true;	
	}
}
