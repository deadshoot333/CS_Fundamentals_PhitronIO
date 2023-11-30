def print_item(*nums):
    for item in nums:
        print(item)
def print_Kargs(**my_Dictionary):
    for key,value in my_Dictionary.items():
        print(f"{key}-->{value}")
print_item(1,2,3,4)
my_dictionary={
    "Name": "ABC",
    "city": "Dhaka",
}
print_Kargs(**my_dictionary)
