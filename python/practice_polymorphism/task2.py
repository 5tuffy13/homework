class USADate:
    def __init__(self, year, month, day):
        self.year = year

        if len(month) == 1:
            self.month = '0' + month
        else:
            self.month = month

        if len(day) == 1:
            self.day = '0' + day
        else:
            self.day = day

    def format(self):
        return f"{self.month}-{self.day}-{self.year}"

    def iso_format(self):
        return f"{self.year}-{self.month}-{self.day}"

class ItalianDate(USADate):
    def __init__(self, year, month, day):
        USADate.__init__(self, year, month, day)

    def format(self):
        return f"{self.day}-{self.month}-{self.year}"

    def iso_format(self):
        return USADate.iso_format(self)

a = USADate('2001', '12', '2')
b = ItalianDate('2001', '12', '21')

print(a.format(), a.iso_format())
print(b.format(), b.iso_format())
