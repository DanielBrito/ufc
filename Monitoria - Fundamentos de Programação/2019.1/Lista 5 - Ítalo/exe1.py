# Lista 4 (Ítalo) - Questao 1

numeros = [71, 62, 16, 11, 25, 31]

print("Elementos de indice par: ")
print(numeros[0::2])

print("\nElementos de valor par: ")
for n in numeros:
    if n%2==0:
        print(n, end=" ")