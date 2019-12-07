# Lista 4 (Ítalo) - Questao 25

listaA = [0, 2, 4, 6, 8]
listaB = [1, 3, 5, 7, 9]
listaC = []

for i in range(0, 5):
    listaC.append(listaA[i])
    listaC.append(listaB[i])
    
for i in range(len(listaC)):
    print(listaC[i], end=" ")