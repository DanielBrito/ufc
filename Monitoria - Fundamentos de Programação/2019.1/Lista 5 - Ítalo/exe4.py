# Lista 4 (Ítalo) - Questao 4

numeros = [35, 602, 100, 38, 82, 62, 510]

print("Elementos com indice par e multiplos de 2 e 5: ")

for i in range(0, len(numeros)):
    if (i%2==0) and (numeros[i]%2==0 and numeros[i]%5==0):
        print(numeros[i], end=" ")