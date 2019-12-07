# Lista 4 (Ítalo) - Questao 16

vet = [1,2,3,4,5,6]
encontrou = False

num = int(input("Digite o numero procurado: "))

for n in vet:
    if n==num:
        encontrou=True
    
print(vet)

if encontrou==True:
    print("O numero ", num, " esta na lista")
else:
    print("O numero ", num, " nao esta na lista")