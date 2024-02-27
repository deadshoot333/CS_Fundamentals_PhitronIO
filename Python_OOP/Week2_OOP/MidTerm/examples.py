# print(len("MidTERm"))
# print(str(2.5))
# print(len([1, 2, 3]))
# print(str([1, 2]))


# class Student:
#     def __init__(self,id):
#         self.id=id

#     def printInfo(self):
#         print(f"ID: {self.id}")

# class L4Student(Student):

#     def __init__(self, id,thesis):
#         self.thesis=thesis
#         super().__init__(id)

#     def printInfo(self):
#         print(f"ID:{self.id}",end=" ")
#         print(f"Thesis:{self.thesis}",end=" ")
#     def __add__(self,other):
#         return self.thesis+" "+other.thesis

# StudentL1=Student("202214011")
# StudentL4=L4Student("202014011","ML")
# StudentL4_2=L4Student("202014012","OOP")
# print(StudentL4+StudentL4_2)
# StudentL1.printInfo()
# StudentL4.printInfo()


# from math import factorial


# class Test:
#     def __init__(self, a, b, c):
#         self.a = a
#         self.b = b
#         self.c = c

#     def sum(self):
#         return self.a + self.b + self.c

#     def factorial(self):
#         return factorial(self.b)
    
# test=Test(5,5,2)
# print(test.sum())
# print(test.factorial())
class Person:
    def __init__(self, name, age, height, weight) -> None:
        self.name = name
        self.age = age
        self.height = height
        self.weight = weight


class Cricketer(Person):
    def __init__(self, name, age, height, weight) -> None:
        super().__init__(name, age, height, weight)
    def __lt__(self,other):
        return self.age<other.age

Sakib = Cricketer('Sakib', 38, 68, 91)
Mushfiq = Cricketer('Mushfiq', 36, 55, 82)
Mustafiz = Cricketer('Mustafiz', 27, 69, 86)
Riyad = Cricketer('Riyad', 39, 72, 92)
youngestPlayer=min(Sakib,Mushfiq,Mustafiz,Riyad)
print(f"The Youngest Player: {youngestPlayer.name}")
# examples used for mid questions