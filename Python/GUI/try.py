#!/usr/bin/python3.5
print("Starting simulation....")

from tkinter import *
from random import randint

root = Tk()
root.resizable(False, False)

# PLAYAREA SIZE
HEIGHT = 500
WIDTH = HEIGHT // 2
TILE_SIZE = 25

playarea = Canvas(root, width=WIDTH, height=HEIGHT, bg='yellow')
playarea.grid(column=21, row=21, columnspan=WIDTH // TILE_SIZE, rowspan=HEIGHT // TILE_SIZE)


menuFrame=Frame(root, width=(WIDTH // 2), height=HEIGHT).grid(column=0, row=0, columnspan= (WIDTH // 2) // TILE_SIZE , rowspan= int(HEIGHT / TILE_SIZE))
newGameButton = Button(menuFrame, text='Start', width= 75 , height = 1 * TILE_SIZE)
newGameButton.grid(column=1, row=1,columnspan=3, rowspan= 1)
newTestButton = Button(menuFrame, text='Test', width= 5 * TILE_SIZE, height = 1* TILE_SIZE)
newTestButton.grid(column=0, row=2, columnspan=5, rowspan=1)
root.update()

print(newGameButton.winfo_width())
print(playarea.grid_size())
#print(playarea.grid_info())

root.mainloop()

print("Simulation Ended")
