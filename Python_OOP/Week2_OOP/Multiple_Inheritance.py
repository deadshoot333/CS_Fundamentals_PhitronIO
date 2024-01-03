class Family:
    def __init__(self,address):
        self.address=address

class School:
    def __init__(self,ID):
        self.ID=ID

class Club:
    def __init__(self,game):
        self.game=game

class Student(Family,School,Club):
    def __init__(self,address,ID,game,name):
        self.name=name
        Family.__init__(self,address)
        School.__init__(self,ID)
        Club.__init__(self,game)

me=Student("Lalbagh","202214011","Cricket","Arqam")
print(me.game)