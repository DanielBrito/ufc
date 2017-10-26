typedef struct indice Indice;

Indice* criarListaIndice();

Indice* inserirIndice(Indice* ind, int pg);

void imprimirListaIndice(Indice* ind);

Indice* buscarNome(Nome* n, char* str, Nome* nBuscado, int qtdT);

Indice* remover(Indice* ind, int pg);

Indice* removerPaginasRepetidas(Indice* ind);

Indice* verificarIntersecao(Indice* indLista, Indice* indProcurado, int qtdT);

Indice* listarIndiceNomeBuscado(Nome* n, Nome* nBuscado);


/*

// FUNÇÕES DE TESTE:

void imprimirListaIndiceDeNome(Nome* n);

*/