from cs50 import get_int

def countNumbers(n):
    count = 0
    while n != 0:
        n = int(n / 10)
        count += 1
    if count == 13 or count == 15 or count == 16:
        return True
    else:
        return False

def typeCard(n):
    if n == 34 or n == 37:
        return "AMEX"
    elif n >= 51 and n <= 55:
        return "MASTERCARD"
    elif n >= 40 and n <= 49:
        return "VISA"
    else:
        return "INVALID"

def validateCard(n):
    sum = 0
    type = "INVALID"
    if countNumbers(n):
        first = True
        secund = False
        while n > 10:
            if first and n > 10:
                sum += n % 10
                n = int(n / 10)
                first = False
                secund = True
            if n < 100 and n > 10:
                type = typeCard(n)
            if n < 10:
                break
            if secund and n > 10:
                sum1 = (n % 10) * 2
                if sum1 > 10:
                    sum += sum1 % 10
                    sum += int(sum1 / 10)
                else:
                    sum += sum1
                n = int(n / 10)
                first = True
                secund = False
            if n < 100 and n > 10:
                type = typeCard(n)
            if n < 10:
                break
        if first:
            sum += n % 10
            if (sum % 10) == 0:
                print(type)
            else:
                print("INVALID")
        if secund:
            sum1 = (n % 10) * 2
            if sum1 > 10:
                sum += sum1 % 10
                sum += sum1 / 10
            else:
                sum += sum1
            if (sum % 10) == 0:
                print(type)
            else:
                print("INVALID")
    else:
        print("INVALID")

number = get_int("Number of card: ")
validateCard(number)