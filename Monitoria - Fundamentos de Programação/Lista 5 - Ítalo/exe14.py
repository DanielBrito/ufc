# Lista 4 (Ítalo) - Questao 14

vet = [1,2,3,4,5,6]
T = 1

for i in range(0, len(vet)):
    T *= (pow(vet[i], 2)/(i+10))
    
T*=1.5
    
print("T = ", T)