import math
x = input()
for i in range(int(x)):
    y = input()
    thing = False
    if (y[0] == "R" and y[1].isdigit()):
        for k in range(1, len(y)):
            if (y[i].isdigit() == False):
               thing = True
    num1 = ""
    num2 = ""
    if (thing):
        for k in range(1,len(y)):
            if (y[k].isdigit()):
                num1 += y[k]
            else:
                num2 = y[k+1:]
                break
        print("num1",num1, "num2", num2, "\n")
        output = ""
        alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
        inum1 = int(num1)
        inum2 = int(num2)
        while (inum2 >= 0):
            output = alphabet[inum2 % 26] + output
            inum2 = math.floor(inum2/26)
            print("num2",num2)
        print(output, inum1)
    else:
        anum = 0
        times = 0
        index = 0
        for x in range(len(y)):
            if (y[x].isdigit()):
                index = x
        for x in range(index):
            anum = (alphabet.find(y[x]) + 1) * (26 ** times) + anum
        print("R",anum,"C",y[index:])