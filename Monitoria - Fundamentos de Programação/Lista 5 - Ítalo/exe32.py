# Lista 4 (Ítalo) - Questao 32

matriz = [[3, 16, 7, 11] ,
          [13, 0, 10, 8],
          [21, 8, 6, 5] ,
          [5, 9, 0, 15]]

for i in range(len(matriz)) :
    for j in range(len(matriz[i])) :
        print(matriz[i][j], end=" ")
    print("")

zeros = 0;

for i in range(len(matriz)) :
    for j in range(len(matriz[i])) :
        if matriz[i][j]==0:
            zeros += 1
            
print("\nA matriz possui", zeros, "zeros")