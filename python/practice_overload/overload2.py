from datetime import date, datetime

class BirthInfo:
    def __init__(self, birth_date):
        if isinstance(birth_date, date):
            self.birth_date = birth_date
        elif isinstance(birth_date, str):
            try:
                self.birth_date = date.fromisoformat(birth_date)
            except ValueError:
                raise TypeError("The argument of the provided type is not supported.")
        elif isinstance(birth_date, (list, tuple)) and len(birth_date) == 3:
            try:
                self.birth_date = date(*birth_date)
            except (TypeError, ValueError):
                raise TypeError("The argument of the provided type is not supported.")
        else:
            raise TypeError("The argument of the provided type is not supported.")
    
    @property
    def age(self):
        today = date.today()
        age = today.year - self.birth_date.year
        if (today.month, today.day) < (self.birth_date.month, self.birth_date.day):
            age -= 1
        return age

birthinfo1 = BirthInfo(date(2024, 1, 1))
birthinfo2 = BirthInfo("2020-05-15")
birthinfo3 = BirthInfo([1990, 12, 31])
birthinfo4 = BirthInfo((2000, 1, 1))

print(birthinfo1.age)
print(birthinfo2.age)   
print(birthinfo3.age)
print(birthinfo4.age)
