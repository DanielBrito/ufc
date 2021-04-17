def calc(a, u):
    return a[0] * pow(1-u, 3) + a[1] * 3 * u * pow(1-u, 2) + a[2] * 3 * pow(u, 2) * (1-u) + a[3] * pow(u, 3)

x = [2,5,0,2]
y = [4,1,2,7]

u = 0.3
print("u: " + str(u) + " = ", calc(x, u), calc(y, u), 0)

u = 0.7
print("u: " + str(u) + " = ", calc(x, u), calc(y, u), 0)

print("--------------------------------------------------")

x = [9,3,1,8]
y = [6,3,2,9]

u = 0.2
print("u: " + str(u) + " = ", calc(x, u), calc(y, u), 0)

u = 0.4
print("u: " + str(u) + " = ", calc(x, u), calc(y, u), 0)

u = 0.6
print("u: " + str(u) + " = ", calc(x, u), calc(y, u), 0)

u = 0.8
print("u: " + str(u) + " = ", calc(x, u), calc(y, u), 0)

print("--------------------------------------------------")

x = [5,5,0,1]
y = [7,5,8,2]

u = 0.2
print("u: " + str(u) + " = ", calc(x, u), calc(y, u), 0)

u = 0.4
print("u: " + str(u) + " = ", calc(x, u), calc(y, u), 0)

u = 0.6
print("u: " + str(u) + " = ", calc(x, u), calc(y, u), 0)

u = 0.8
print("u: " + str(u) + " = ", calc(x, u), calc(y, u), 0)