# Lista 4 (Ítalo) - Questao 18

vet = [3, 7, 9, 10]

print(vet)
    
encontrou = False

num = int(input("Digite o elemento a ser removido: "))
    
if (num in vet): 
    vet.remove(num)
    print(vet)
else:
    print("O elemento nao esta na lista")
    