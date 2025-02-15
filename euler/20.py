
def getFactorial(num):
    sum = 1;
    for i in range(1, num):
        sum *= i
    return sum;

if __name__ == "__main__":
    sum = getFactorial(100)
    digitsum = 0
    for i in str(sum):
        digitsum += int(i)
    print(digitsum)
