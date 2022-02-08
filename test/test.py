listSign = ['+', '-', '*', '/', '*(', ')*', '', '^']

temp = '2+2+2+2+2+2+2+2'
temp = list(temp)

ansMax = 0

for i1 in listSign:
    temp[1] = i1;
    for i2 in listSign:
        temp[3] = i2;
        for i3 in listSign:
            temp[5] = i3;
            for i4 in listSign:
                temp[7] = i4;
                for i5 in listSign:
                    temp[9] = i5;
                    for i6 in listSign:
                        temp[11] = i6;
                        for i7 in listSign:
                            temp[13] = i7;
                            thisStr = ''.join(temp)
                            # print(thisStr)
                            try:
                                ans = eval(thisStr)
                                print(ans)
                                print(thisStr)
                                # if int(ans) == 2022:
                                    # print(ans)
                                    # print(thisStr)
                                ansMax = max(ansMax, ans)
                            except:
                                pass
                            # if thisStr == '2+2+2+2+2+2+2+2'


print(ansMax)