from graphics import *
import random

win = GraphWin("ur mom",800,800) # open the window and give it the name in the quotations

win.setBackground("white") # what color is our background? use this to change the diamond background color.
for i in range(1000):  #how many circles are we making?
    x=random.randint(200,600) #where is the circle on the x axis? its a random value between 200 and 600
    y=random.randint(200,600) #on the y axis it is also a random value between 200 and 600
    z=random.randint(1,100) #where is it on the z axis?THIS WILL ALTER THE WIDTH OF OUR CIRCLE! ITS LIKE AN IMAGE THAT GETS CLOSER AND BIGGER
    point=Point(x,y)
    circle=Circle(point,z)
    color=color_rgb(random.randint(0,255), #pick a color between 0 and 255 for red
                    random.randint(0,255), #between 0 and 255 for green
                    random.randint(0,255)) #between 0 and 255 for blue
    circle.setFill(color) #fill it with the color, make sure 
    circle.draw(win)
    
    
win.getMouse()
win.getCircle()