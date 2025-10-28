#CSC111-03 Fall 2022
#Program 8 - Checkerboard
#Bella Goodman
from graphics import *

def drawSquare(x, y, color):
    vertices = []
    vertices.append(Point(x,y))
    vertices.append(Point(x,y+59))
    vertices.append(Point(x+59,y+59))
    vertices.append(Point(x+59,y))
    square = Polygon(vertices)    
    square.setFill(color)
    square.draw(win)
    
win = GraphWin("A Game of Checkers",480,480)
win.setBackground("white")

redd = color_rgb(255,0,0)
whitee = color_rgb(255,255,255)

color = redd

for x in range (0,480,60):
    for y in range(0,480,60):
        print(x,"  ",y)
        drawSquare(x,y,color)
        if color == redd:
            color = whitee
        else:
            color = redd
            
    if color == redd:
        color = whitee
    else:
        color = redd


win.getMouse()
win.close()


