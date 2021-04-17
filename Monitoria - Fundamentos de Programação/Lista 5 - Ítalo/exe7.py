# Lista 4 (Ítalo) - Questao 7

numeros = []
menor = 9999

for i in range(1, 6):
    n = int(input("Digite um elemento: "))
    numeros.append(n)
    
for i in range(0, len(numeros)):
    if (i%2!=0) and (numeros[i]<menor):
        menor = numeros[i]

print("\nMenor elemento de indice impar da lista: ", menor)