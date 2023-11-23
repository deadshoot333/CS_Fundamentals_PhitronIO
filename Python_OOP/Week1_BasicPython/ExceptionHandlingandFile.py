a=int(input())
try:
    b=45/a
except:
    print("Error Occured")
finally:
    print("Programmed Finished")
print("Will be executed")

with open("file.txt","w") as file:
    file.write("Hello World")
with open("file.txt","a") as file:
    file.write("Hi this is computer")
with open("file.txt","r") as file:
    data=file.read()
    print(data)
