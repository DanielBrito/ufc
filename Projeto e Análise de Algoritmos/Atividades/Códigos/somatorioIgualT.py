def somatorioIgualT(a, n, soma):
    
  sub = ([[False for i in range(soma+1)] for i in range(n+1)])
  
  for i in range(n+1):
    sub[i][0] = True
    
  for i in range(1, soma+1):
    sub[0][i]= False
      
  for i in range(1, n+1):
    for j in range(1, soma+1):
        
      if j < a[i-1]:
        sub[i][j] = sub[i-1][j]
        
      if j >= a[i-1]:
        sub[i][j] = (sub[i-1][j] or sub[i-1][j - a[i-1]])
  
  return sub[n][soma]