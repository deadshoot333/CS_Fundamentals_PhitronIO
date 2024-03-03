from School import School,ClassRoom,Subject
from Person import Student,Teacher
def main():
    school=School('BMARPC',"Pilkhana")
    nine=ClassRoom('nine')
    school.add_classroom(nine)
    eight=ClassRoom('eight')
    school.add_classroom(eight)
    ten=ClassRoom('ten')
    school.add_classroom(ten)
    
    Student1=Student('Arqam')
    Student2=Student('Abir')
    school.student_admission(Student1,ten)
    school.student_admission(Student2,ten)
    physics_teacher=Teacher('mr.Phy_teacher')
    physics=Subject('physics',physics_teacher)
    ten.add_subjects(physics)
    chemistry_teacher=Teacher('mr.Chem_teacher')
    chemistry=Subject('chemistry',chemistry_teacher)
    ten.add_subjects(chemistry)
    biology_teacher=Teacher('mr.Bio_teacher')
    biology=Subject('biology',biology_teacher)
    ten.add_subjects(biology)
    ten.take_semestar_final(physics)
    print(school)
    print(School.calculate_grade(80))

if __name__=='__main__':
    main()
