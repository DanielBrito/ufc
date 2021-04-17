# Lista 4 (Ítalo) - Questao 29

listaA = []
listaB = []
listaC = []

listaA.extend(range(1, 21)) # 1..20
listaB.extend(range(61, 71)) # 61..70

print("Lista A:", listaA)
print("Lista B:", listaB)

for i in range(0, len(listaA)):
    
    if i<len(listaB):
        listaC.append(listaA[i]+listaB[i])
    else:
        listaC.append(listaA[i])
    
print("Lista C:", listaC)