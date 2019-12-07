# Lista 4 (Ítalo) - Questao 15

vet = [1,2,3,4,5]
U = 1
numerador = 5

for i in range(0, len(vet)):
    U *= (numerador/vet[i])
    numerador+=2
    
U*=8
    
print("U = ", U)