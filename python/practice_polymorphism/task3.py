class Father:
    def __init__(self, mood='neutral'):
        self.mood = mood

    def greet(self):
        return "Hello!"

    def be_strict(self):
        self.mood = 'strict'
        return self.mood

class Mother:
    def __init__(self, mood='neutral'):
        Father.__init__(self, mood='neutral')

    def greet(self):
        return "Hi, honey!"

    def be_kind(self):
        self.mood = 'kind'
        return self.mood

class Son:
    def __init__(self, mood='neutral'):
        Father.__init__(self, mood='neutral')

    def greet(self):
        return Father.greet(self)

    def be_strict(self):
        return Father.be_strict(self)

    def be_kind(self):
        return Mother.be_kind(self)

class Daughter:
    def __init__(self, mood='neutral'):
        Father.__init__(self, mood='neutral')

    def greet(self):
        return Mother.greet(self)

    def be_strict(self):
        return Father.be_strict(self)

    def be_kind(self):
        return Mother.be_kind(self)

John = Father()
John_j = Son()
Ann = Mother()
Anny = Daughter()

print(John.greet(), John_j.greet(), Ann.greet(), Anny.greet())
print(John.be_strict(), Ann.be_kind(), John_j.be_strict(), John_j.be_kind(), Anny.be_strict(), Anny.be_kind())
