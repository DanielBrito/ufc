# Lista 4 (Ítalo) - Questao 31

matriz = [[3, 16, 7, 11] ,
          [13, 4, 10, 8],
          [21, 8, 6, 5] ,
          [5, 9, 1, 15]]

for i in range(len(matriz)) :
    for j in range(len(matriz[i])) :
        print(matriz[i][j], end=" ")
    print("")

print("Elementos da terceira linha:")

print(matriz[2])

print("\nElementos da segunda coluna:")

for i in matriz:
    print(i[1])
    
print("\nSoma dos elementos da quarta coluna:")

soma = 0

for i in matriz:
    soma+=i[3]
    
print(soma)
    
print("\nProduto dos elementos da terceira linha:")

produto = 1

for i in matriz[2]:
    produto *= i

print(produto)

print("\nMenor elemento da quarta linha:")

menor = 10000

for i in matriz[3]:
    if i<menor:
        menor = i
        
print(menor)

print ("\nMaior elemento da diagonal principal:")

maior = -10000

for i in range (0, 4):
    if matriz [i][i]>maior:
        maior = matriz [i][i]

print (maior)

print ("\nMenor elemento da matriz:")

menor = 10000

for i in matriz :
    for j in i :
        if j < menor :
            menor = j

print (menor)

print ("\nValor médio dos elementos da matriz:")

soma = 0

for i in range(len(matriz)) :
    for j in range(len(matriz[i])) :
        soma += matriz[i][j]
        
media = soma/16

print (media)

print ("\nValor médio dos elementos da segunda linha:")

soma = 0

for i in matriz[1]:
    soma += i
    
media = soma/4

print(media)