from graphics import *
import random

win = GraphWin("ur mom",500,500)

win.setBackground("white")

color=color_rgb(random.randint(0,255),random.randint(0,255),random.randint(0,255))

vertices = []
for i in range(4):                          #do this three times
    x = random.randint(0,500)               # create a random x value
    y = random.randint(0,500)               # create a random y value 
    vertices.append(Point(x,y))    #add the (x,y) point to the vertices
triangle = Polygon(vertices)       #create the triangle
triangle.setFill(color)
triangle.draw(win)

win.getMouse()
win.close()