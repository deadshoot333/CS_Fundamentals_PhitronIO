class Bank:
    def __init__(self,holderName,deposit,branch):
        self.holderName=holderName
        self.__deposit=deposit  #private variable has double underscore
        self._branch=branch
    def get_diposit(self):
        return self.__deposit

Customer1=Bank("Arqam",1500,"Dhaka")
# print(Customer1.__deposit)
print(Customer1.get_diposit())
print(Customer1._branch) # however we can see this because this putting underscore is just a name convention here