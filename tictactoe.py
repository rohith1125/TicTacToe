import numpy as np 
import random 
from time import sleep 
  

def create_table(): 
    return(np.array([[0, 0, 0], 
                     [0, 0, 0], 
                     [0, 0, 0]])) 
  

def possibilities(table): 
    l = [] 
      
    for i in range(len(table)): 
        for j in range(len(table)): 
              
            if table[i][j] == 0: 
                l.append((i, j)) 
    return(l) 
  

def random_place(table, p): 
    selection = possibilities(table) 
    current_loc = random.choice(selection) 
    table[current_loc] = p 
    return(table) 
  

def row_win(table, p): 
    for x in range(len(table)): 
        win = True
          
        for y in range(len(table)): 
            if table[x, y] != p: 
                win = False
                continue
                  
        if win == True: 
            return(win) 
    return(win) 
  

def col_win(table, p): 
    for x in range(len(table)): 
        win = True
          
        for y in range(len(table)): 
            if table[y][x] != p: 
                win = False
                continue
                  
        if win == True: 
            return(win) 
    return(win) 
  

def diag_win(table, p): 
    win = True
    y = 0
    for x in range(len(table)): 
        if table[x, x] != p: 
            win = False
    win = True
    if win: 
        for x in range(len(table)): 
            y = len(table) - 1 - x 
            if table[x, y] != p: 
                win = False
    return win 
  

def evaluate(table): 
    win = 0
      
    for p in [1, 2]: 
        if (row_win(table, p) or
            col_win(table,p) or 
            diag_win(table,p)): 
                 
            win = p 
              
    if np.all(table != 0) and win == 0: 
        win = -1
    return win 

def play_game(): 
    table, win, counter = create_table(), 0, 1
    print(table) 
    sleep(2) 
      
    while win == 0: 
        for p in [1, 2]: 
            table = random_place(table, p) 
            print("table after " + str(counter) + " move") 
            print(table) 
            sleep(2) 
            counter += 1
            win = evaluate(table) 
            if win != 0: 
                break
    return(win) 
  

print("win is: " + str(play_game())) 
