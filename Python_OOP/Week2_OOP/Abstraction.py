from abc import abstractmethod,ABC 
#abstract base class

class Shape:
    @abstractmethod
    def print(self):
        pass
    @abstractmethod
    def Area(self):
        pass

class Triangle(Shape):
    def __init__(self,base,height):
        self.base=base
        self.height=height
        super().__init__()
    def Area(self):
        return self.base*self.height*0.5
    def print(self):
        print("This is a trinagle")
