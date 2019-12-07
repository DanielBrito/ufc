# Lista 4 (Ítalo) - Questao 19

vet = [10, 20, 30, 40, 50, 60, 70, 80, 90, 100]

cont = 0

num = int(input("Digite um numero: "))

for n in vet:
    if n>num:
        cont+=1
        
print(vet)
    
print("Existe(m) ", cont , " elemento(s) maior(es) que ", num)