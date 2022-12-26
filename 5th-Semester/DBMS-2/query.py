def confidence(A, B, transactions):
    lob = union(A,B)
    lob_count = 0
    hor = A
    hor_count = 0
    
    for transaction in transactions:
        for item in transaction:
            if set(lob).issubset(set(item)):
                lob_count += 1
            if set(hor).issubset(set(item)):
                hor_count +=1
    confidence = (lob_count/hor_count)*100
    print(str(A)+"==>"+str(B)+" confidence is: "+str(confidence)+"%")
                

def union(A,B):
    lob = []
    for item in A:
        if item not in lob:
            lob.append(item)
    for item in B:
        if item not in lob:
            lob.append(item)
    return lob
        

transactions = [
        ['T100',['I1','I2','I5']],
        ['T200',['I2','I4']],
        ['T300',['I2','I3']],
        ['T400',['I1','I2','I4']],
        ['T500',['I1','I3']],
        ['T600',['I2','I3']],
        ['T700',['I1','I3']],
        ['T800',['I1','I2','I3','I5']],
        ['T900',['I1','I2','I3']]
        ]

confidence(["I2","I1"],["I3"], transactions)
confidence(["I3"],["I2","I1"], transactions)
