def ge_fw(matrix):
    rows = 0
    columns=0
    for n in range(0,len(matrix[0]),1):
            columns=columns + 1
    for i in matrix:
        rows = rows + 1
    sub=0
    while sub < rows-1:
        tracker=sub
        while True:
            for i in range(sub,len(matrix),1):
                if matrix[i][sub]!=0:
                    break
                else:
                    tracker=tracker+1
            break
        temp=list(matrix[sub])
        matrix[sub]=list(matrix[tracker])
        matrix[tracker]=list(temp)           
        adjuster=list(matrix[sub])
        firstele=adjuster[sub]
        for i in range(sub,columns,1):
            adjuster[i]=adjuster[i]/firstele
        for i in range(sub+1,rows,1):
            if matrix[i][sub]>0:
                while matrix[i][sub]>0:
                    for n in range(sub,columns,1):
                        matrix[i][n]=matrix[i][n]-adjuster[n]
            if matrix[i][sub]<0:
                while matrix[i][sub]<0:
                    for n in range(sub,columns,1):
                        matrix[i][n]=matrix[i][n]+adjuster[n]
        sub=sub+1
    return matrix
def ge_bw(matrix):
    rows = 0
    columns=0
    for n in range(0,len(matrix[0]),1):
            columns=columns + 1
    for i in matrix:
        rows = rows + 1
    sub=0
    while sub < rows-1:
        tracker=sub
        while True:
            for i in range(len(matrix),sub,1):
                if matrix[i][sub]!=0:
                    break
                else:
                    tracker=tracker+1
            break
        temp=list(matrix[sub])
        matrix[sub]=list(matrix[tracker])
        matrix[tracker]=list(temp)           
        adjuster=list(matrix[sub])
        firstele=adjuster[sub]
        for i in range(sub,columns,1):
            adjuster[i]=adjuster[i]/firstele
        for i in range(sub+1,rows,1):
            if matrix[i][sub]>0:
                while matrix[i][sub]>0:
                    for n in range(sub,columns,1):
                        matrix[i][n]=matrix[i][n]-adjuster[n]
            if matrix[i][sub]<0:
                while matrix[i][sub]<0:
                    for n in range(sub,columns,1):
                        matrix[i][n]=matrix[i][n]+adjuster[n]
        sub=sub+1
    return matrix
