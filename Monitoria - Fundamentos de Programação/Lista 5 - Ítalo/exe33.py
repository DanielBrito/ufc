# Lista 4 (Ítalo) - Questao 33

matriz = [[3, 16, 7, 11] ,
          [13, 0, 10, 8],
          [21, 8, 6, 5] ,
          [5, 9, 0, 15]]

for i in range(len(matriz)) :
    for j in range(len(matriz[i])) :
        print(matriz[i][j], end=" ")
    print("")

cont = 0;

for i in range(len(matriz)) :
    for j in range(len(matriz[i])) :
        if matriz[i][j]>10:
            cont += 1
            
print("\nA matriz possui", cont, "valores maiores que 10")