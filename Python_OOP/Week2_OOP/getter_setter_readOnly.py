class User:
    def __init__(self, name, id, age):
        self.__name = name
        self.__age = age  # here attributes having double underscore is private
        self.id = id

    @property
    def age(self):  
        # Using property decorator a method acts as an attribute it is known as getter function
        return self.__age

    @age.setter  # Using the attribute_name.setter the method acts as setter function it also acts as an attribute
    def age(self, value):
        age = value


User1 = User("Arqam", 202214011, 22)
print(User1.age)
User.age = 15
print(User1.age)
