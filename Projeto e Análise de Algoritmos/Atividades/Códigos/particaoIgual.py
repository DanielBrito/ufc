def particao(A):
  for i in range(len(A)):
    soma_esq = 0
        
    for j in range(i):
      soma_esq += A[j]
 
    soma_dir = 0
        
    for j in range(i, len(A)):
      soma_dir += A[j]
 
    if soma_esq == soma_dir:
      return [A[:i], A[i:]]
 
  return -1