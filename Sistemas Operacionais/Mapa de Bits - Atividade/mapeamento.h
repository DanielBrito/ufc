void imprimir(char* vet);
void inicializarVetor(char* vet);
void inicializarPosicoesOcupadas(char* vet);
void menu(char* vet, int* nextFitAuxP);
char* firstFit(char* vet, char* str, int* nextFitAuxP);
char* bestFit(char* vet, char*str, int* nextFitAuxP);
char* worstFit(char* vet, char*str, int* nextFitAuxP);
char* nextFit(char* vet, char*str, int* nextFitAuxP);
int verificarEspacoDisponivel(char* vet, char* str);
int verificarEspacoDisponivel_NextFit(char* vet, char* str, int* nextFitAuxP);