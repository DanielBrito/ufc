# Lista 4 (Ítalo) - Questao 21

todosImpares = True
numeros = [1, 3, 6, 7, 8, 9]

for n in numeros:
    if n % 2 == 0:
        todosImpares = False
        break
 
if(todosImpares==True):
    print("Todos os elementos são ímpares")
else:
    print("Nem todos os elementos são ímpares")