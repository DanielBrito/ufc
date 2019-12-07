# Lista 4 (Ítalo) - Questao 8

numeros = []
maior = -1

for i in range(1, 6):
    n = int(input("Digite um elemento: "))
    numeros.append(n)
    
for n in numeros:
    if (n>maior) and (n%5==0):
        maior = n

print("\nMaior elemento divisivel por 5: ", maior)