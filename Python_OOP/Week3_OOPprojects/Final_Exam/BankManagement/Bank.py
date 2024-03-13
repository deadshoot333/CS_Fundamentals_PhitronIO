class Bank:
    def __init__(self,name):
        self.name=name
        self.users={}
        self.admins={}
        self.activity_of_user={}
        self.__bank_balance=0
        self.give_loan=False
        self.loan_given=0
    @property
    def bank_balance(self):
        return self.__bank_balance
    @bank_balance.setter
    def bank_balance(self,amount):
        self.__bank_balance+=amount
    
    

    