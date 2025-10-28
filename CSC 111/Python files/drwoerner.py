import math
def circleArea(radius:float):
    a = radius**2
    a = a * math.pi
    return a
def squareArea(side:float):
    a = side**2
    return a
def rectangleArea(length:float, width:float):
    a = length*width
    return a
def triangleArea(base:float, height:float):
    a = base*height
    a = a/2
    return a

print(circleArea(1), "\n")
print(squareArea(2), "\n")
print(rectangleArea(3,2), "\n")
print(triangleArea(3,2), "\n")