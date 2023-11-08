def default_args(num1,num2,num3=1):
    return num1+num2+num3

def KArgs(num1,num2,*nums):
    print(num1)
    print(num2)
    print(nums) ##pass nums as a tuple

def Advance_KArgs(first,last,*addition_,**addition_dictionary):
    name=f'{first} {last}'
    print(addition_)
    print(addition_dictionary)
    return name

KArgs(4,5,1,2,3)
df_args=default_args(4,5)
print(df_args)
nameU=Advance_KArgs(last="Bin Almas",first="Arqam",dept="CSE",id="202214011")
print(nameU)


