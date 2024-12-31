class Negator:
    @staticmethod
    def neg(arg):
        if isinstance(arg, (int, float)) and not isinstance(arg, bool):
            return -arg
        elif isinstance(arg, bool):
            return not arg
        else:
            raise TypeError("Аргумент переданного типа не поддерживается")
a=10
b=-5
c=False
print(Negator.neg(a),Negator.neg(b),Negator.neg(c))
