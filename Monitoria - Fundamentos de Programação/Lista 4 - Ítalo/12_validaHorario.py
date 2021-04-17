# Questão 12 - Lista 4 (Ítalo)

def validaHorario(h,m,s,ms):
    if h<0 or h>23:
        return -1
    elif m<0 or m>59:
        return -1
    elif s<0 or s>59:
        return -1
    elif ms<0 or ms>999:
        return -1
    else:
        return 1
    
h = int(input("Digite a hora: "))
m = int(input("Digite o minuto: "))
s = int(input("Digite o segundo: "))
ms = int(input("Digite o milissegundo: "))

if validaHorario(h, m, s, ms)==1:
    print("\nHora valida")
else:
    print("\nHora invalida")