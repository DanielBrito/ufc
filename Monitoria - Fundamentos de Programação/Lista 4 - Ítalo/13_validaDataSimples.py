# Questão 13 - Lista 4 (Ítalo)

def validaData(m,a):
    
    if m<1 or m>12 or a>2019:
        return -1
    else:
        return 1
    
mes = int(input("Digite o mes: "))
ano = int(input("Digite o ano: "))

if validaData(mes, ano)==1:
    print("\nData valida")
else:
    print("\nData invalida")