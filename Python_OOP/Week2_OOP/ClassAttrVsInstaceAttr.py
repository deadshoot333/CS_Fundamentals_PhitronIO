class Shop:
    cart=[]
    def __init__(self,buyer):
        self.buyer=buyer
    def add_to_cart(self,item):
        self.cart.append(item)

print("\t---- Class Attribute----")
customer=Shop("Arqam")
customer.add_to_cart("watch")
customer.add_to_cart("phone")
print(f"Buyer is = {customer.buyer} and his/her items are = {customer.cart}")
customer1=Shop("Ayman")
customer1.add_to_cart("Bag")
customer1.add_to_cart("HairClip")
print(f"Buyer is = {customer1.buyer} and his/her items are = {customer1.cart}")
## From The above Code we can see that cart is shared by both objects this is known as Class Attribute.
## To avoid this we have to use Instance Attribute

class Shop2:
    def __init__(self,buyer):
        self.buyer=buyer
        self.cart=[]
    def add_to_cart(self,item):
        self.cart.append(item)
print("\t---- Instance Attribute----")
customer=Shop2("Arqam")
customer.add_to_cart("watch")
customer.add_to_cart("phone")
print(f"Buyer is = {customer.buyer} and his/her items are = {customer.cart}")
customer1=Shop2("Ayman")
customer1.add_to_cart("Bag")
customer1.add_to_cart("HairClip")
print(f"Buyer is = {customer1.buyer} and his/her items are = {customer1.cart}")