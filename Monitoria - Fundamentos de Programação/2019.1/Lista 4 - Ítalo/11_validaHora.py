# Questão 11 - Lista 4 (Ítalo)

def validaHora(h,m):
    if h<0 or h>23 or m<0 or m>59:
        return -1
    else:
        return 1
    
hora = int(input("Digite a hora: "))
minuto = int(input("Digite o minuto: "))

if validaHora==1:
    print("\nHora valida")
else:
    print("\nHora invalida")