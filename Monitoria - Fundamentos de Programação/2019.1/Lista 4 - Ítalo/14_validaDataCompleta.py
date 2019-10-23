# Questão 14 - Lista 4 (Ítalo)

def validaData(d, m, a):
    
    if a>2019:
        return -1 
    if m==2:
        if d<1 or dia>28:
            return -1
    elif m==1 or m==3 or m==5 or m==7 or m==8 or m==10 or m==12:
        if d<1 or d>31:
            return -1
    else:
        if d<1 or d>30:
            return -1
        
    return 1
    
dia = int(input("Digite o dia: "))
mes = int(input("Digite o mes: "))
ano = int(input("Digite o ano: "))

if validaData(dia, mes, ano)==1:
    print("\nData valida")
else:
    print("\nData invalida")