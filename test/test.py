def count(nn, n, m):
    a = b = 0
    m = int(m)
    for i in nn:
        if int(i[n]) < m:
            a += 1
        if int(i[n]) > m:
            b += 1
    return a == b

def main():
    with open("APPLES.inp", "r") as f:
        n = f.readlines()
    nn = [n[i].split() for i in range(1, len(n))]
    for i in range(len(nn)):
        for j in range(i+1, len(nn)):
            if nn[i][0] == nn[j][0]:
                if count(nn, 0, nn[i][0]):
                    with open("APPLES.out", "w") as f:
                        f.write(f"{i+1} {j+1}")
                    return
            elif nn[i][1] == nn[j][1]:
                if count(nn, 1, nn[i][1]):
                    with open("APPLES.out", "w") as f:
                        f.write(f"{i+1} {j+1}")
                    return
                
if __name__ == "__main__":
    main()