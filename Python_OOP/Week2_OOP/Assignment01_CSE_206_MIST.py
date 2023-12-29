from math import ceil, floor


class Student:
    Student_Id=""
    Course_Code=""
    Attendense_Class=0
    Marks_of_3CT=[0,0,0]
    Marks_of_MID=0
    Marks_of_Final=0
    Marks_of_Attendence=0
    Marks_of_Performance=0
    Marks_of_Best2CT=0
    Marks_Total=0
    def __init__(self,id,Attendense_Class,Marks_of_3CT,Marks_of_MID,Marks_of_Final):
        self.Student_Id=id
        self.Attendense_Class=Attendense_Class
        self.Marks_of_3CT=Marks_of_3CT
        self.Marks_of_MID=Marks_of_MID
        self.Marks_of_Final=Marks_of_Final

    def Calc_Attendense(self):
        self.Marks_of_Attendence=round(self.Attendense_Class/42*15,2) ## round is needed for precision
        print(f"Marks Attendence = {self.Marks_of_Attendence}")
    
    def Calc_perf(self):
        self.Marks_of_Performance=round((self.Marks_of_MID/30*15-(42-self.Attendense_Class)),2)
        if self.Marks_of_Performance<0:
            self.Marks_of_Performance=0
        print(f"Marks Performance= {self.Marks_of_Performance}")
    
    def Calc_best2CT(self):
        sum=0
        for items in self.Marks_of_3CT:
            sum=round(sum+items*1.5,2)
        min_ct=min(self.Marks_of_3CT)*1.5
        self.Marks_of_Best2CT=sum-min_ct
        print(f"Marks Best 2 CT = {self.Marks_of_Best2CT}")
    
    def Calc_Grade(self):
        self.Marks_Total=self.Marks_of_Attendence+self.Marks_of_Best2CT+self.Marks_of_MID+self.Marks_of_Performance+self.Marks_of_Final
        if self.Marks_Total>=240 and self.Marks_Total<=300:
            print(f"Result for Student Id: {self.Student_Id} is = A")
        elif self.Marks_Total>=200 and self.Marks_Total<240:
            print(f"Result for Student Id: {self.Student_Id} is = B")
        elif self.Marks_Total>=160 and self.Marks_Total<200:
            print(f"Result for Student Id: {self.Student_Id} is = C")
        elif self.Marks_Total>=120 and self.Marks_Total<160:
            print(f"Result for Student Id: {self.Student_Id} is = D")
        elif self.Marks_Total<120:
            print(f"Result for Student Id: {self.Student_Id} is = F")
        else :
            print(f"Result for Student Id: {self.Student_Id} is = E")
    def Calc_All(self):
        self.Calc_Attendense()
        self.Calc_best2CT()
        self.Calc_perf()
        self.Calc_Grade()
        print(f"Total Marks of {self.Student_Id} is = {self.Marks_Total} ") 
###Main

n=int(input("Enter the numbers of Student = "))
students=[]
for i in range(0,n):
    id=input("Enter Student ID = ")
    cpy_CT_marks=[]
    for j in range(1,4):
        ct=int(input((f"Enter CT-{j} Marks = ")))
        cpy_CT_marks.append(ct)
    mid=int(input("Enter mid marks = "))
    classAttend=int(input("Enter Attendend Class = "))
    Final=int(input("Enter Marks of Final = "))
    students.append(Student(id,classAttend,cpy_CT_marks,mid,Final))
    students[i].Calc_All()

###


