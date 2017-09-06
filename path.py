import curses
import time

infinity = 100000
GRID1 = [['x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x'],
         ['x','0','0','0','x','0','0','0','0','0','x','0','0','0','x','0','0','0','0','0','x'],
         ['x','x','x','0','x','0','0','0','0','0','x','0','0','0','0','0','0','0','0','0','x'],
         ['x','0','0','0','x','0','0','0','0','0','x','0','x','0','0','0','0','0','0','0','x'],
         ['x','0','0','0','x','x','0','x','x','0','x','0','x','0','x','x','0','x','0','0','x'],
         ['x','x','0','x','x','0','0','0','x','0','x','0','x','0','x','0','0','x','0','0','x'],
         ['x','0','0','0','0','0','0','0','x','0','x','0','x','0','x','0','x','x','x','0','x'],
         ['x','0','x','x','x','x','x','x','x','0','x','x','0','0','x','0','0','0','0','0','x'],
         ['x','0','0','0','0','x','0','0','0','0','x','0','x','0','x','0','0','x','x','x','x'],
         ['x','x','x','x','0','x','0','x','0','0','x','0','x','0','x','0','0','0','0','0','x'],
         ['x','0','0','0','0','x','0','x','0','0','x','0','x','0','x','0','0','0','0','0','x'],
         ['x','0','0','0','0','x','0','x','x','x','x','0','x','0','x','0','0','x','0','0','x'],
         ['x','0','0','x','x','x','0','0','0','0','0','0','x','0','x','0','0','x','0','0','x'],
         ['x','0','0','0','0','x','0','0','0','0','0','0','x','0','x','0','0','x','0','0','x'],
         ['x','x','x','0','0','x','0','0','0','0','0','0','x','0','x','0','0','0','0','0','x'],
         ['x','0','0','0','0','x','x','x','x','x','0','0','x','0','x','x','x','x','0','0','x'],
         ['x','0','0','0','x','0','x','0','0','x','0','0','x','0','x','x','T','x','0','0','x'],
         ['x','0','x','x','x','0','0','0','0','x','0','0','x','0','x','x','0','x','x','0','x'],
         ['x','0','0','x','0','0','x','0','0','x','0','0','x','0','x','0','0','0','x','0','x'],
         ['x','0','0','x','0','0','0','x','0','x','x','x','x','0','x','0','x','0','x','0','x'],
         ['x','0','0','0','0','0','x','x','0','0','0','0','0','0','x','0','x','0','0','0','x'],
         ['x','0','0','x','0','0','x','0','0','0','0','0','0','0','x','0','0','0','x','0','x'],
         ['x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x']]


class Maze:
    def __init__(self, stdscr, startpos):
        self.stdscr = stdscr
        self.pos = startpos
        self.resultpath = []
    def move(self, direction):
        if not 'actions' in self.__dict__:
            self.actions = []
        self.actions.append(direction)
    def validPos(self, x, y):
        if x < 0 or y < 0 or y >= len(self.grid) or x >= len(self.grid[0]):
            return False
        if self.grid[y][x] != '0':
            return False
        return True
    def findPath(self):
        pass
    def run(self):
        self.findPath()
        if not 'actions' in self.__dict__:
            return
        for i in self.actions:
            if i == "right" and self.validPos(self.pos['x']+1, self.pos['y']):
                self.pos['x']+=1
            elif i == "left" and self.validPos(self.pos['x']-1, self.pos['y']):
                self.pos['x']-=1
            elif i == "up" and self.validPos(self.pos['x'], self.pos['y']-1):
                self.pos['y']-=1
            elif i == "down" and self.validPos(self.pos['x'], self.pos['y']+1):
                self.pos['y']+=1
            else:
                self.stdscr.refresh()
                self.stdscr.addstr(0, 0, "Invalid pos: {} move {}".format(self.pos, i))
                self.stdscr.refresh()
                break
            self.stdscr.addstr(0, 0, "{}".format(self.pos))
            self.grid[self.pos['y']][self.pos['x']] = 'o'
            for r in range(0, len(self.grid)):
                self.stdscr.addstr(r + 1, 0, "{}".format(self.grid[r]).replace('0','.'))
            time.sleep(0.3)
            self.stdscr.refresh()
            self.grid[self.pos['y']][self.pos['x']] = '0'
        self.stdscr.refresh()
        time.sleep(10)


stdscr = curses.initscr()
curses.noecho()
curses.cbreak()

try:
    startpos = {'x': 1, 'y': 1}
    maze = Maze(stdscr, startpos)
    maze.grid = GRID1
#example solution
    maze.move('right')
    maze.move('right')
    maze.move('down')
    maze.move('down')
    maze.move('left')
    maze.move('left')
    maze.move('down')
    maze.move('down')
    maze.move('down')
    maze.move('down')
    maze.move('down')
    maze.run()
finally:
    curses.echo()
    curses.nocbreak()
    curses.endwin()

