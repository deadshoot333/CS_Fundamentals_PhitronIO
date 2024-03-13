from Bank import Bank
from User import User
from Admin import Admin
def main():
    bank1=Bank('Brac Bank')
    admin1=Admin()
    admin1.create_account('Mr.Admin','admin1@gmail.com','Admin'.lower(),bank1)
    User1=User()
    User1.create_account('Mr.ABC','user1@gmail.com','User'.lower(),bank1)
    User1.deposit(1000,bank1)
    bank2=Bank('Trust Bank')
    admin2=Admin()
    admin2.create_account('Mr.Admin2','admin2@gmail.com','Admin'.lower(),bank1)
    User2=User()
    User2.create_account('Mrs.DCE','user2@gmail.com','User'.lower(),bank2)
    User2.deposit(500,bank2)
    User1.transfer(User2,bank1,50,bank2)
    admin1.check_balance_of_bank(bank1)
    User1.take_loan(10,bank1)
if __name__=='__main__':
    main()