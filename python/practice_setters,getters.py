    class BankAccount:  # 1 задание
    def __init__(self,balance = 0):
        self.__balance = balance
        
    def get_balance(self):
        return self.__balance
    def deposit(self,amount):
        self.__balance += amount
        return self.__balance
    def withdraw(self,amount):
        if amount>self.__balance:
            raise ValueError("На счете недостаточно средств")
        self.__balance -= amount
        return self.__balance
    def transfer(self,account,amount):
        if account.__balance>self.__balance-amount:
            raise ValueError("На счете недостаточно средств")
        self.__balance -= amount
        account.__balance += amount

Alex = BankAccount(1500)
John = BankAccount(300)
print(Alex.get_balance())
Alex.deposit(500)
Alex.transfer(John,300)
print(Alex.get_balance(),John.get_balance())

class User:  # 2 задание
    def __init__(self, name, age):
        self.name = name
        self.age = age

    @property
    def name(self):
        return self.__name

    @name.setter
    def name(self, value):
        if not isinstance(value, str) or not value.isalpha() or not value:
            raise ValueError("Некорректное имя")
        self.__name = value

    @property
    def age(self):
        return self.__age

    @age.setter
    def age(self, value):
        if not isinstance(value, int) or not (0 <= value <= 110):
            raise ValueError("Некорректный возраст")
        self.__age = value

        
user1 = User('Roman', 17)
print(user1.name, user1.age)
user1.name = 'Igor'
user1.age = 44
print(user1.name, user1.age)



class IPAddress:  # 3 задание
    def __init__(self,ipaddress):
        if isinstance(ipaddress,str):
            self.ipaddress = ipaddress
        else:
            ipaddress = [str(i) for i in ipaddress]
            self.ipaddress = '.'.join(ipaddress)
    def __str__(self):
        return(self.ipaddress)
    def __repr__(self):
        ip_repr = "IPAddress('"+self.ipaddress+"')"
        return(ip_repr)

ip1=IPAddress([255,0,0,244])
print(ip1)
print(repr(ip1))



class Word:  # 4 задание
    def __init__(self, word):
        self.word = word
    def __repr__(self):
        return f"Word('{self.word}')"
    def __str__(self):
        return self.word.capitalize()
    def __eq__(self, other):
        if not isinstance(other, Word):
            return NotImplemented
        return len(self.word) == len(other.word)
    def __lt__(self, other):
        if not isinstance(other, Word):
            return NotImplemented
        return len(self.word) < len(other.word)

word1 = Word("hello")
word2 = Word("world")
word3 = Word("hi")
print(word1)
print(word2)
print(word3)
print(word1 == word2)
print(word1 != word3)
print(word1 > word3)
print(word2 < word1)


class FoodInfo: # 5 задание
    def __init__(self, proteins, fats, carbohydrates):
        self.proteins = proteins
        self.fats = fats
        self.carbohydrates = carbohydrates

    def __repr__(self):
        return f"FoodInfo({self.proteins}, {self.fats}, {self.carbohydrates})"

    def __add__(self, other):
        if not isinstance(other, FoodInfo):
            return NotImplemented
        return FoodInfo(self.proteins + other.proteins,
                        self.fats + other.fats,
                        self.carbohydrates + other.carbohydrates)

    def __mul__(self, n):
        if not isinstance(n, (int, float)):
            return NotImplemented
        return FoodInfo(self.proteins * n, self.fats * n, self.carbohydrates * n)

    def __truediv__(self, n):
        if not isinstance(n, (int, float)):
            return NotImplemented
        return FoodInfo(self.proteins / n, self.fats / n, self.carbohydrates / n)

    def __floordiv__(self, n):
        if not isinstance(n, (int, float)):
            return NotImplemented
        return FoodInfo(self.proteins // n, self.fats // n, self.carbohydrates // n)


food1 = FoodInfo(10, 5, 20)
food2 = FoodInfo(5, 3, 15)

print(food1)
food_sum = food1 + food2
print(food_sum)

food_mul = food1 * 2
print(food_mul)

food_div = food1 / 2
print(food_div)

food_floordiv = food1 // 3
print(food_floordiv)
