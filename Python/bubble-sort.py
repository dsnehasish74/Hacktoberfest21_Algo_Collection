
l=[4,2,5,6,23,7,9,33,7,5,8,9,7,3]

flag=True

while(flag):
    flag=False
    j=0
    for i in range(len(l)-1-j):
        if(l[i]>l[i+1]):
            l[i],l[i+1]=l[i+1],l[i]
            flag=True

print(l)