my_list=[1,2,3,4,5,6,7,8]
# print(my_list)
# print(my_list[1],my_list[-2])
# print(my_list[0:8:1])
# print(my_list[8::-1])
# print(my_list[::])
my_list.append(9)
print(my_list)
my_list.insert(3,11)
print(my_list)
if 10 in my_list:
    my_list.remove(10)
if 11 in my_list:
    my_list.remove(11)
print(my_list)
popped_item=my_list.pop()
print(f"{my_list}\nPopped item is = {popped_item}")
my_list.insert(6,18)  ##insert(index,value)
my_list.sort()
print(my_list)
