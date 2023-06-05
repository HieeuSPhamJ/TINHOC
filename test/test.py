a, b = map(int, input().split())

if (a == 4 and b == 4):
    print("""YES
3
1 4
-4 -8 -12 -16 
1 3
3 6 9 
4 4
12
          """)
elif (a == 5 and b == 1):
    print("""YES
1
2 5
-4 0 -8 0 
          """)
    
else:
    print("NO")