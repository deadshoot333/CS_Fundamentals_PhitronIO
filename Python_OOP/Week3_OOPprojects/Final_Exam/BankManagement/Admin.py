from User import User

class Admin(User):
    def __init__(self):
        self.name = None
        self.loan = 0
        self.__balance = 0
        self.type = None
        self.loan_feature = False

    def create_account(self, name, email, type, bank):
        return super().create_account(name, email, type, bank)

    def check_balance_of_bank(self, bank):
        if self.name in bank.admins:
            print(f"The {bank.name} has Total Amount {bank.bank_balance}")
        else:
            print(f"Admin not Found in  {bank.name}")

    def total_loan_amount(self, bank):
        if self.name in bank.admins:
            print(f"The {bank.name} has Total Loan Amount {bank.loan_given}")
        else:
            print(f"Admin not Found in {bank.name}")

    def loan_feature(self, bank, switch):
        if self.name in bank.admins:
            if switch == True:
                bank.give_loan = True
                print(f"Loan Feature is On by Admin: {self.name}")
                bank.activity_log[self.name].append(
                    f"Loan Feature is On by Admin {self.name} "
                )
            else:
                bank.give_loan = False
                print(f"Loan Feature is Off by Admin {self.name}")
                bank.activity_log[self.name].append(
                    f"Loan Feature is Off by Admin {self.name}"
                )
        else:
            print(f"Admin not Found in {bank.name}")
