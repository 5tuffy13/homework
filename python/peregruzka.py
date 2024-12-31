from functools import singledispatchmethod

class Negator:
    @singledispatchmethod
    def __init__(self, arg):
        raise NotImplementedError("Cannot negate a")
    @__init__.register(int | float)
    def neg(self, arg):
        self.arg = arg * (-1)

    @__init__.register(bool)
    def neg(self, arg):
        self.arg = not arg
    def __str__(self):
        return f'{self.arg}'
        
a=10
b = -5
c = True
print(Negator(a),Negator(b),Negator(c))
