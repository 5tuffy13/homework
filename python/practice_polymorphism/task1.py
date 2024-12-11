letters = ['a', 'b', 'c', 'd', 'e', 'f', 'g', 'h']
digits = ['1', '2', '3', '4', '5', '6', '7', '8']

class ChessPiece:
    def __init__(self, horizontal, vertical):
        if horizontal in letters and vertical in digits:
            self.horizontal = horizontal
            self.vertical = vertical

    def can_move(self, hor, ver):
        pass

class King(ChessPiece):
    def __init__(self, horizontal, vertical):
        ChessPiece.__init__(self, horizontal, vertical)

    def can_move(self, hor, ver):
        if abs(letters.index(self.horizontal) - letters.index(hor)) <= 1 and \
           abs(digits.index(self.vertical) - digits.index(ver)) <= 1:
            return 'Correct'
        else:
            return 'Incorrect'

class Knight(ChessPiece):
    def __init__(self, horizontal, vertical):
        ChessPiece.__init__(self, horizontal, vertical)

    def can_move(self, hor, ver):
        if (abs(letters.index(self.horizontal) - letters.index(hor)) == 2 and \
            abs(digits.index(self.vertical) - digits.index(ver)) == 1) or \
           (abs(letters.index(self.horizontal) - letters.index(hor)) == 1 and \
            abs(digits.index(self.vertical) - digits.index(ver)) == 2):
            return 'Correct'
        else:
            return 'Incorrect'

start_king = King('e', '1')
a = input('Letter: ')
b = input('Digit: ')
print(start_king.can_move(a, b))

start_knight = Knight('b', '1')
c = input('Letter: ')
d = input('Digit: ')
print(start_knight.can_move(c, d))
