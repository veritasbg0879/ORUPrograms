#This is a better version of the game of life. the other one i ripped from the interweb but this one's all mine baby
import pygame
import random

pygame.init()


black = (0, 0, 0)
one = (191, 130, 236)
two = (255, 192, 203)
three = (202, 202, 255)
four = (255, 255, 255)


width = 800
height = 800
tileSize = 20
gridWidth = width//tileSize
gridHeight = height//tileSize

framesPerSecond = 120

screen = pygame.display.set_mode((width, height))

clock = pygame.time.Clock()

def gen(num): 
    return set([(random.randrange(0, gridHeight), random.randrange(0, gridWidth), random.randint(1, 4)) for x in range(num)])

def valToColor(num):
    if (num == 1):
        color = one
    if (num == 2):
        color = two
    if (num == 3):
        color = three
    if (num == 4):
        color = four
    return color

def colorToVal(color):
    if (color == one):
        num = 1
    if (color == two):
        num = 2
    if (color == three):
        num = 3
    if (color == four):
        num = 4
    return num

def greatestOfFour(num1, num2, num3, num4):
    if (num1 > num2):
        x = num1
    else:
        x = num2
    if (num3 > num4):
        y = num3
    else:
        y = num4
    if (x > y):
        z = x
    else:
        z = y
    return z

def grid(sketch):
    for spot in sketch:
         column, row, state = spot
         origin = (column * tileSize, row * tileSize)
         state = valToColor(spot[2])
         pygame.draw.rect(screen, state, (*origin, tileSize, tileSize))
         

    for row in range(gridHeight):
        pygame.draw.line(screen, black, (0, row * tileSize), (width, row * tileSize))
    for column in range(gridWidth):
        pygame.draw.line(screen, black, (column * tileSize, 0), (column * tileSize, height))

def generations(sketch):
    totalNeighbors = set()
    newSpots = set()

    for spot in sketch:
        neighbors =  neighbours(spot[:2])
        totalNeighbors.update(neighbors)

        liveNeighbors = [n for n in neighbors if any(s[:2] == n for s in sketch)]


        if len(liveNeighbors) in [2,3]:
            newSpots.add(spot)
    
    for neighbor in totalNeighbors:
        if not any(s[:2] == neighbor for s in sketch):
            liveNeighbors = [n for n in neighbours(neighbor) if any(s[:2] == n for s in sketch)]

        if len(liveNeighbors) == 3:
            neighborColors = [s[2] for s in sketch if s[:2] in liveNeighbors]
            newColor = max(set(neighborColors), key=neighborColors.count) 
            newSpots.add((neighbor[0], neighbor[1], newColor))

    return newSpots

def color(spot):
    colorOne = colorTwo = colorThree = colorFour = 0
    for neighbor in neighbours(spot[:2]):
        for s in sketch:
            if s[:2] == neighbor:
                nColor = s[2]
                if (nColor == 1):
                    colorOne += 1
                if (nColor == 2):
                    colorTwo += 1
                if (nColor == 3):
                    colorThree += 1
                if (nColor == 4):
                    colorFour += 1
    newColor = greatestOfFour(colorOne, colorTwo, colorThree, colorFour)
    return valToColor(newColor)




def neighbours(spot):
    x, y = spot
    neighbors = []
    for dx in [-1, 0, 1]:
        for dy in [-1, 0, 1]:
            if dx == 0 and dy == 0:
                continue

            newX = ((x + dx) % 800)
            newY = ((y + dy)% 800)

            neighbors.append((newX, newY))

    return neighbors

def main():
    running = True
    playing = False
    count = 0
    freq = 120

    sketch = set()
    while running:
        clock.tick(framesPerSecond)

        if playing: 
            count += 1

        if count >= freq:
            count = 0
            sketch = generations(sketch)


        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                running = False

            if event.type == pygame.MOUSEBUTTONDOWN:
                 x, y = pygame.mouse.get_pos()
                 column = x//tileSize
                 row = y//tileSize
                 spot = (column, row, random.randint(1, 4))

                 if spot in sketch:
                      sketch.remove(spot)
                 else:
                      sketch.add(spot)

            if event.type == pygame.KEYDOWN:
                 if event.key == pygame.K_SPACE:
                    playing = not playing
                 if event.key == pygame.K_c:
                    sketch = set()
                    playing = False
                    count = 0

                 if event.key == pygame.K_g:
                     sketch = gen(random.randrange(2, 5 * gridWidth))
    
        screen.fill(black)
        grid(sketch)
        pygame.display.update()

    pygame.quit()
if __name__ == "__main__":
    main()