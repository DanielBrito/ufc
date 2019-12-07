# Lista 4 (Ítalo) - Questao 34

linhas = int(input("Digite a quantidade de linhas: "))
colunas = int(input("Digite a quantidade de colunas: "))

matrizA = []
matrizB = []

print("\nDigite os valores da Matriz A:")

for i in range(linhas):
    m = []
    for j in range(colunas):
        m.append(int(input()))
    matrizA.append(m)
    
print("\nDigite os valores da Matriz B:")

for i in range(linhas):
    m = []
    for j in range(colunas):
        m.append(int(input()))
    matrizB.append(m)
    
print("\nMatriz A:")
    
for i in range(linhas) :
    for j in range(colunas) :
        print(matrizA[i][j], end=" ")
    print("")
    
print("\nMatriz B:")
    
for i in range(linhas) :
    for j in range(colunas) :
        print(matrizB[i][j], end=" ")
    print("")
    
print("\nSoma das matrizes:")
    
for i in range(linhas):
    for j in range(colunas):
        print(matrizA[i][j]+matrizB[i][j], end=" ")
    print("")