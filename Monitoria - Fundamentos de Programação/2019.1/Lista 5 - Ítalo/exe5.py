# Lista 4 (Ítalo) - Questao 5

numeros = []

for i in range(1, 6):
    n = int(input("Digite um elemento: "))
    numeros.append(n)
    
print("\nNumeros impares com indice impar: ")
    
for n in numeros[1::2]:
    if n%2!=0:
        print(n, end=" ")