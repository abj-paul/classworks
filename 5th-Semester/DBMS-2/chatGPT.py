def frequent_itemsets(transactions, min_support):
    items = {}
    for transaction in transactions:
        for item in transaction[1]:
            if item in items:
                items[item] += 1
            else:
                items[item] = 1

    items = {k: v for k, v in sorted(items.items(), key=lambda item: item[1], reverse=True)}
    frequent_items = {}
    for item in items:
        if items[item] >= min_support:
            frequent_items[item] = items[item]
        else:
            break

    F = [frequent_items]

    while True:
        C = candidate_gen(F[-1])
        if not C:
            break
        counts = {}

        for transaction in transactions:
            t = set(transaction[1].keys())
            for c in C:
                if c.issubset(t):
                    if c in counts:
                        counts[c] += 1
                    else:
                        counts[c] = 1

        frequent_items = {}
        for itemset in counts:
            support = counts[itemset]
            if support >= min_support:
                frequent_items[itemset] = support

        if not frequent_items:
            break

        F.append(frequent_items)

    return F

def candidate_gen(Fk_1):
    Ck = set()
    for f1 in Fk_1:
        for f2 in Fk_1:
            c = f1.union(f2)
            if len(c) == len(f1) + 1:
                Ck.add(c)

    return Ck

transactions = [
    ["TID19",   {"BREAD":3,"COFFEE":2,"SUGER":10}],
    ["TID19",   {"BREAD":5,"COFFEE":2,"SUGER":4}]
]

min_support = 2

frequent_itemsets(transactions, min_support)
