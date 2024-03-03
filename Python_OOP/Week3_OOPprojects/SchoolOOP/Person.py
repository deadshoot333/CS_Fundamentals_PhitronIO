import random
from School import School

class Person:
    def __init__(self,name) -> None:
        self.name=name

class Teacher(Person):
    def __init__(self,name):
        super().__init__(name)
    
    def teach(self):
        pass

    def take_exam(self,subject,students):
        for student in students:
            marks=random.randint(0,100)
    def evaluate_exam(self):
        marks=random.randint(0,100)
        return marks  
class Student(Person):
    def __init__(self, name) -> None:
        super().__init__(name)
        self.classroom=None
        self.__id=None
        self.subjects=[]
        self.marks={}
        self.subject_grade={}
        self.grade=None
    def calculate_final_grade(self):
        sum=0
        for grade in self.subject_grade.values():
            point=School.grade_to_value(grade)
            sum+=point
            print(f'{self.name}: {grade} {point}')
        avg=sum/len(self.subject_grade)
        self.grade=School.value_to_grade(avg)
        print(f'{self.name} Final Grade: {self.grade} with point {avg}')
    @property
    def id(self):
        return self.__id
    @id.setter
    def id(self,value):
        self.__id=value 
