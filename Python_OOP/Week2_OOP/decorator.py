import math
# def timer(function):
#     print("Timer Started")
#     function()
#     print("Timer Ended")

# @timer
# def get_factorial():
#     print("factorial Started")

 # Here without sending using inner function like implementation we used timer function as
# decorator. So timer function takes get_factorial function as a parameter 
def timerFactorial(function):
        def inner(n):
            print("Timer Started")
            function(n)
            print("Timer Ended")
        return inner

@timerFactorial
def Get_factorial(n):
    print("factorial Started")
    result=math.factorial(n)
    print(f"Factorial is = {result}")
    print("Factorial ended")

Get_factorial(5)
