from itertools import combinations

def apriori(transactions, support_vector):
    total_result = []
    unique_items = []
    for transaction in transactions:
        for item in transaction[1]:
            if item not in unique_items:
                unique_items.append(item);
    unique_items.sort()
    print("Unique Items: "+str(unique_items))
    print()

    # Candidate Set for 1-itemset = C1
    C1 = {}
    for item in unique_items:
        for transaction in transactions:
            if item in transaction[1]:
                if item in C1.keys():
                    C1[item]+=1
                else: C1[item] = 1
    print("Set of Candidate 1-itemset, C1: \n"+str(C1)+"\n")

    # Set of frequent 1-itemset = L1
    L1 = {}
    for item,count in zip(C1.keys(), C1.values()):
        if count>=support_vector:
            if item in L1: L1[frozenset([item])]+=count
            else: L1[frozenset([item])] = count
    print("Set of frequen 1-itemset, L1: \n"+str(L1)+"\n")

    # Now, we will do the above for itemset 2..n
    Li = {} # Set of frequent i-itemset
    Ci = {} # Set of Candidatge i-itemset

    Li = L1 # Initializing
    Ci = C1

    for item_size in range(2,1000):
        # Join
        old_items = [item for item in Li.keys()]
        new_items = []
        for i in range(0, len(old_items)):
            for j in range(i+1, len(old_items)):
                new_item = old_items[i].union(old_items[j])
                if(len(new_item)==item_size):
                    new_items.append(new_item)
        print("After Join: \n"+str(new_items)+"\n")

        new_items.sort()

        # Count
        Ci = {}
        for item in new_items:
            Ci[item] = 0
            for transaction in transactions:
                temp = set(transaction[1])
                if(item.issubset(temp)):
                    Ci[item]+=1
        print("Candidate Set. C"+str(item_size)+":\n"+str(Ci)+"\n")

        # Pruning
        Li = {}
        for item in Ci:
            if Ci[item] >= support_vector:
                if item in Li:
                    Li[item] += Ci[item]
                else: Li[item] = Ci[item]
        print("Accepted itemset, L"+str(item_size)+":\n"+str(Li)+"\n")

        total_result.append(Li)
        if(len(Li)==0): return total_result
                

# Testing
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
print("Final Answer:\n"+str(apriori(transactions, support_vector=3)))
