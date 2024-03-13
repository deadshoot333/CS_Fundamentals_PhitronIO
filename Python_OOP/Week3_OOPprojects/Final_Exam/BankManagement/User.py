from Bank import Bank


class User:
    def __init__(self):
        self.__balance = 0
        self.name = None
        self.email = None
        self.type = None
        self.loan = 0

    def create_account(self, name, email, type, bank):
        self.name = name
        self.email = email
        self.type = type
        if type == "user":
            # print("--------User Account created--------")
            bank.users[self.name] = self
            bank.activity_of_user[self.name] = [(f"---User Account created---\n")]
        elif type == "admin":
            print("--------Admin Account created--------")
            bank.admins[self.name] = self

    def deposit(self, amount, bank):
        if self.name in bank.users:
            self.__balance += amount
            bank.bank_balance += amount
            print(
                f"Deposit Succeed for account {self.name} and Balance is :{self.__balance}"
            )
            bank.activity_of_user[self.name].append(
                f"---{self.name} Deposited {amount} BDT in his/her account.---\n"
            )
        else:
            print(f"{self.name} not found")

    @property
    def balance(self):
        return self.__balance

    def transfer(self, to_send, bank, amount, to_send_bank):
        if self.name in bank.users and to_send.name in to_send_bank.users:
            if self.__balance - amount >= 0:
                self.__balance -= amount
                to_send.__balance += amount
                bank.activity_of_user[self.name].append(
                    f"---{self.name} transfared {amount} to {to_send.name} of {to_send_bank.name}"
                )
                to_send_bank.activity_of_user[to_send.name].append(
                    f"---{to_send.name} recived {amount} from {self.name} of {bank.name}"
                )
            else:
                print(f"{bank.name} is bankcrupt")
                return
        else:
            print("User not found :(")

    def take_loan(self, loan_amount, bank):
        if self.name in bank.users:
            if bank.give_loan == True:
                if self.loan * 2 <= self.balance:
                    self.loan += loan_amount
                    bank.bank_balance -= loan_amount
                    bank.loan_given += loan_amount
                    print(
                        f"User: {self.name} has got {loan_amount}  Loan from {bank.name}"
                    )
                    bank.activity_log[self.name].append(
                        f"{self.name} Took {loan_amount}  Loan from {bank.name}"
                    )
                else:
                    print(f"User: {self.name} is not eligible to take loan now")
            else:
                print(f"Loan Feature is OFF in {bank.name}")
        else:
            print(f"No Account Found for user : {self.name} in {bank.name}")

    def show_transactions(self, bank):
        for i in bank.activity_of_user[self.name]:
            print(i)
