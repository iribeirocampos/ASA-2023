import pulp

_input = input().split()
info = [int(x) for x in _input]

toys_cap = []
# PULP VARIABLES
x = []
funcao_objetivo = []
restricao_global = []
restricao = []


def get_min(lista):
    limites = []
    for toy in lista:
        limites.append(int(toys_cap[int(toy) - 1]))
    return int(min(limites))


prob = pulp.LpProblem("", pulp.LpMaximize)

for i in range(0, info[0] + info[1]):
    toy_info = input().split()

    if len(toy_info) == 2:
        toys_cap.append(int(toy_info[1]))
        x.append(
            pulp.LpVariable(
                name=f"x{i+1}", lowBound=0, cat="Integer", upBound=int(toy_info[1])
            )
        )
        restricao_global.append(x[i])
        restricao.append(x[i])
    else:
        x.append(
            pulp.LpVariable(
                name=f"x{i+1}",
                lowBound=0,
                cat="Integer",
                upBound=get_min(toy_info[:3]),
            )
        )
        restricao_global.append(3 * x[i])
        for toy in toy_info[:3]:
            restricao[int(toy) - 1] += x[i]
    funcao_objetivo += (
        x[i] * int(toy_info[0]) if len(toy_info) == 2 else x[i] * int(toy_info[3])
    )


index = 0
for restricao in restricao:
    prob += pulp.lpSum(restricao) <= toys_cap[index]
    index += 1
prob += pulp.lpSum(restricao_global) <= info[2]
prob += pulp.lpSum(funcao_objetivo)

status = prob.solve(pulp.GLPK(msg=0))
print(pulp.value(prob.objective))
