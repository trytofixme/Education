#!/usr/bin/env python
# coding: utf-8

# In[15]:


from random import randint
"""
Для начала будем генерировать клетки 3х3(блоки), 
для этого зададим отдельный класс со своими правилами
"""

class Block(object):
    # Инициализация блока 3х3
    def __init__(self):
        self._block_size = 9
        self._block = [None] * self._block_size
    
    
    # Затем нам нужен геттер и сеттер
    # Геттер для всего блока
    def get_block(self):
        return self._block

    
    # Геттер для заданной позиции(если мы представим блок в виде матрицы 3х3
    # то pos - пара значений (x, y), где x и y лежат от 0 до 2 включительно
    def __getitem__(self, pos):
        if pos[0] in range(3) and pos[1] in range(3):
            return self._block[pos[1] + 3 * pos[0]]
        else:
            raise KeyError('incorrect position')
            return
    
    
    # Теперь определим сеттер
    def __setitem__(self, pos, val):
        if val not in range(1, 10):
            raise ValueError('incorrect value')
            return
        elif val in self._block and val is not None:
            raise ValueError('value already in block')
            return
        else:
            self._block[pos[1] + 3 * pos[0]] = val
    
    
class Sudoku(object):
    def __init__(self):
        self._cell_size = 9
        self._field_size = 81
        self._filename = 'sudoku.pkl'
        self._field = [[5, 3, None, None, 7, None, None, None, None],
                       [6, None, None, 1, 9, 5, None, None, None],
                       [None, 9, 8, None, None, None, None, 6, None],
                       [8, None, None, None, 6, None, None, None, 3],
                       [4, None, None, 8, None, 3, None, None, 1],
                       [7, None, None, None, 2, None, None, None, 6],
                       [None, 6, None, None, None, None, 2, 8, None],
                       [None, None, None, 4, 1, 9, None, None, 5],
                       [None, None, None, None, 8, None, None, 7, 9]]
    
    def possible(self, x, y, n):
        for i in range(0, 9):
            if self._field[y][i] == n:
                return False
        for i in range(0, 9):
            if self._field[x][i] == n:
                return False
        x0 = (x // 3) * 3
        y0 = (y // 3) * 3
        for i in range(0, 3):
            for j in range(0, 3):
                if self._field[y0 + i][x0 + j] == n:
                    return False
        return True
    
    def solver(self):
        for y in range(9):
            for x in range(9):
                if self._field[y][x] is None:
                    for n in range(1, 10):
                        if possible(x, y, n):
                            self._field[y][x] = n
                            solver()
                            self._field[y][x] = None
                return 
        print(self._field)
        
    def get_field(self):
        return self._field
    
    
    def update(self):
        pass
        
    
    def save(self):
        pass
    
    
    def clear(self):
        for block in self._field:
            block = [0] * self._cell_size

sud = Sudoku()
sud.solver()


