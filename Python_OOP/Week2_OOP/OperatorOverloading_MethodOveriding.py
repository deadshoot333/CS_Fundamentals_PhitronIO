class Person:
    def __init__(self, name, age, height, weight, netWorth):
        self.name = name
        self.age = age
        self.height = height
        self.weight = weight
        self.netWorth = netWorth

    def eat(self):
        print("Rice,Lentil,Beef,Chicken")

    def exercise(self):
        raise NotImplementedError

    def ShowNetWorth(self):
        return self.netWorth


class Cricketer(Person):
    def __init__(self, name, age, height, weight, netWorth):
        super().__init__(name, age, height, weight, netWorth)

    def eat(self):
        print("Vegetables,Fruits")

    # eat Method is overrided
    def exercise(self):
        print("Running,Streching,Net-Practice")

    def __add__(self, other):
        return self.age + other.age

    def __mul__(self, other):
        return self.weight + other.weight

    def __gt__(self, other):
        return self.netWorth > other.netWorth

    def __len__(self):
        return self.weight


# this are the examples of operator overloading


person = Person("Arqam", 22, 5.0, 65, 3600)
player1 = Cricketer("Sakib", 38, 5.6, 80, 45e4)
player2 = Cricketer("Mushfiq", 34, 5.1, 70, 25e4)

person.eat()
player1.eat()
player2.eat()

print(player1.ShowNetWorth())
print(player2.ShowNetWorth())
print(person.ShowNetWorth())
player1.exercise()
# person.exercise()    here person exercise is not implmented so it will show error

print(f"Addition overloading-->{player1+player2}")
print(f"Multiplication overloading-->{player1*player2}")
print(f"Greater than overloading-->{player1>player2}")
print(f"Length function overloading-->{len(player1)}")
