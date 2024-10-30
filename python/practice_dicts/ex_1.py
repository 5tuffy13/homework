data = {
    "enterprise_1" : {"planned" : 10 ,"actual" : 10},
    "enterprise_2" : {"planned" : 11 ,"actual" : 10},
    "enterprise_3" : {"planned" : 8 ,"actual" : 10},
    "enterprise_4" : {"planned" : 10 ,"actual" : 8},
    "enterprise_5" : {"planned" : 10 ,"actual" : 9},
}
underperf = 0

for name, values in data.items():
    percent =(values["actual"]/values["planned"])*100
    if percent <=90:
        underperf+=1
    print(f"{name} : plan completion percentage - {percent}")
print(f"Enterprises that failed to fulfill the plan by 10% or more : {underperf}")
