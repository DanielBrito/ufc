# Lista 4 (Ítalo) - Questao 3

numeros = [102, 450, 29, 559, 315, 94, 120]

print("Elementos com indice multiplo de 3: ")
print(numeros[0::3])

print("\nElementos divisiveis por 5: ")
for n in numeros:
    if n%5==0:
        print(n, end=" ")