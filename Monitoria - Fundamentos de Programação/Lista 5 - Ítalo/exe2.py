# Lista 4 (Ítalo) - Questao 2

numeros = [54, 42, 33, 18, 75, 72]

print("Elementos de indice impar: ")
print(numeros[1::2])

print("\nElementos de valor par: ")
for n in numeros:
    if n%2==0:
        print(n, end=" ")