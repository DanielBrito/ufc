typedef struct nome Nome;

Nome* criarListaNome(void);

Nome* inserirNome(int pg, Nome* n, char* str);

Nome* listarNomeEntrada(int pg, Nome* n, char* str);

Nome* listarNomeBuscado(Nome* n, char* str);

int contarTermos(char* str);

Nome* inserirNomeBuscado(Nome* n, char* str);

char* padronizarNome(char* str);


/*

// FUNÇÕES DE TESTE:

void imprimirNome(Nome* n);

void imprimirUmNome(Nome* n);

*/