# function is a first class object


def double_decker():
    print("Inside of a double decker")

    def inside_function():
        print("Inside of inside function")
        return 500
    return inside_function
def do_something(work):
    print("Work Started")
    # print(work)#in a function we can send anything as a parameter even a function.Here a non-function parameter is printed
    work()
    print("Work Ended")
def coding():
    print("I am Coding")
# double_decker()
# print(double_decker)
print(double_decker()())
# do_something(2)
do_something(coding)