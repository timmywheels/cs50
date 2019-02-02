from cs50 import get_string
from student import Student

students = []
# dorms = [] # rather than storing user inputs in two diff arrays, create a struct

for i in range(3):
    name = get_string('name: ')
    dorm = get_string('dorm: ')
    # students.append(name)

    s = Student(name, dorm)
    students.append(s)

    # print(students) # returns mem loc

for student in students:
    print(f'{student.name} lives in {student.dorm}')
