class Student:
    def __init__(self,name,id):
        self.name=name
        self.id=id
    def printInfo(self):
        print(f'Name: {self.name}\nID: {self.id}\n')

class Student_L1(Student):
    def __init__(self,name,id,CT,MID):
        self.CT=CT
        self.MID=MID
        super().__init__(name,id)

class Student_L4(Student_L1):
    def __init__(self,name,id,CT,MID,Thesis):
        self.Thesis=Thesis
        super().__init__(name,id,CT,MID)

##Main

s1=Student("Arqam","202214011")
s2=Student_L1("Arqam","202214011",15,18)
s3=Student_L4("Arqam","202214011",16,17,27)
s3.printInfo()
