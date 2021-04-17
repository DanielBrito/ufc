# Questão 18 - Lista 4 (Ítalo)

def potencia(x, n): 
  
    if x==0 or x==1 or n==1:
        return x
    
    if n==0:
        return 1
    
    if n<0:
        return 1/potencia(x,-n)
    
    val = potencia(x,n//2)
    
    if n%2 ==0:
        return val*val
    
    return val*val*x
    
base = int(input("Digite a base: "))
expoente = int(input("Digite o expoente: "))

print("\nResultado =", potencia(base, expoente))
