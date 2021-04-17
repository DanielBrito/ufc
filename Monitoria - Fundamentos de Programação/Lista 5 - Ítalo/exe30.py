# Lista 4 (Ítalo) - Questao 30

matriz = [[4, 6, 8, 12] ,
          [1, 9, 4, 3],
          [8, 6, 11, 13] ,
          [3, 7, 5, 2]]

for i in range(len(matriz)) :
    for j in range(len(matriz[i])) :
        print(matriz[i][j], end=" ")
    print("")

print ("\nElementos da segunda linha da matriz:")

print (matriz[1])

print ("\nElementos da terceira coluna da matriz:")

for i in matriz :
    print (i[2])

print ("\nSoma dos elementos da quarta linha da matriz:")

soma = 0

for n in matriz [3]:
    soma += n

print ("Soma =", soma)
 
print ("\nProduto dos elementos da primeira coluna:")

produto = 1

for linha in matriz :
    produto *= linha [0]

print ("Produto =", produto)

print ("\nMaior elemento da segunda coluna:")

maior = -10000

for linha in matriz :
    if linha [1] > maior :
        maior = linha [1]

print (maior)

print ("\nMenor elemento da diagonal principal")

menor = 10000

for i in range (0, 4):
    if matriz [i][i]<menor:
        menor = matriz [i][i]

print (menor)

print ("\nMaior elemento da matriz:")

maior = -10000

for i in matriz :
    for j in i :
        if j > maior :
            maior = j

print (maior)