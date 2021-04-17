# Lista 4 (Ítalo) - Questao 6

numeros = []
maior = -1

for i in range(1, 6):
    n = int(input("Digite um elemento: "))
    numeros.append(n)
    
for n in numeros:
    if n>maior:
        maior = n

print("\nMaior elemento da lista: ", maior)