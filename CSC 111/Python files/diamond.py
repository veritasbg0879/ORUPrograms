#CSC111-03 Fall 2022
#Program 7 - Diamond
#Bella Goodman

from graphics import *
import random

win = GraphWin("diamonds are a girls best friend MATERIAL GORL",300,300)

win.setBackground("red")

for i in range (1):
    color=color_rgb(random.randint(254,255),random.randint(254,255),random.randint(254,255))

    vertices = []
    x = 150
    y = 0
    l = 300
    
    vertices.append(Point(x,y))
    vertices.append(Point(l,x))
    vertices.append(Point(x,l))
    vertices.append(Point(y,x))
    
    diamond = Polygon(vertices)           
    diamond.setFill(color)
    diamond.draw(win)

win.getMouse()
win.close()
