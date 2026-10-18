class Rectangle:
    def __init__(self, w, h):
        self.width = w
        self.height = h

    def get_info(self):
        return f"가로 길이: {self.width}, 세로 길이: {self.height}"

    def get_area(self):
        return f"직사각형의 넓이: {self.width * self.height}"


w = int(input())
h = int(input())
rect = Rectangle(w, h)
print(rect.get_info())
print(rect.get_area())
