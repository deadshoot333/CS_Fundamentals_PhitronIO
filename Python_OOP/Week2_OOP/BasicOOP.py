class Phone:
    price=1200
    color='blue'
    model="samsung"
    featuers=['camera','speaker','button']
    def call(self):  ## self  is neccessary in python 
        print('Call from Class\n')
    def send_sms(self,phone,sms):  ## self is need here so python can work
        sms=f'sending sms to = {phone} and the message is {sms}\n'
        return sms
my_phone=Phone()
my_phone.call()
get_sms=my_phone.send_sms("RealME","HI from Samsung")
print(get_sms)