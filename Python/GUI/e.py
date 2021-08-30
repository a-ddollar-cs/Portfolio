#!/usr/bin/python3.5
print("ggg")

from tkinter import *

class Application(Frame):

    def __init__(self, master=None):
        Frame.__init__(self, master=None)
        self.master.rowconfigure(0, weight=1)
        self.master.columnconfigure(0, weight=1)
        self.grid(sticky=N+S+E+W)
        self.event = "<Button-1>"
        event = self.event
        self.__BuildFrames(event)

    def __ButtonHandler(self, event, f, v, r, s, color, i):
        if i == 1:
            f.configure(bg = "red")
            r.set("You picked red")
        elif i == 2:
            f.configure(bg = "blue")
            # s (Label) is a nonType object...so s.config won't work
            color.set('blue') #nothing - and s.color.set is none-type object
            r.set("You picked blue")
        elif i == 3:
            f.configure(bg = "green")
            r.set("You picked green")
        elif i == 4:
            f.configure(bg = "black")
            r.set("You picked black")
        elif i == 5:
            f.configure(bg = "red")
            v.set("Random file")
            r.set("You wish to open a file")

    def __HandlerBlue(self, event):
        print("Frame 1 clicked at", event.x, event.y)

    def __HandlerWhite(self, event):
        print("Frame 2 clicked at", event.x, event.y)

    def __BuildFrames(self, event):

        for x in range(1, 3):
            self.rowconfigure(x, weight=1)

        d = Frame(self, bg="blue")
        Label(self, text="Frame 1", bg="blue").grid(row=1, column=1, sticky=E, pady=50)
        d.grid(row=1, column=1, columnspan=2, sticky=N+S+E+W)
        d.bind(event, self.__HandlerBlue)

        e = Frame(self, bg="white")
        Label(self, text="Frame 2", bg="white").grid(row=2, column=1, sticky=E, pady=50)
        e.grid(row=2, column=1, columnspan=2, sticky=N+S+E+W)
        e.bind(event, self.__HandlerWhite)

        f = Frame(self, bg="red")
        r = StringVar()
        Label(self, textvariable=r, bg="red").grid(row=1, column=4, sticky=S)
        r.set("Frame 3")
        f.grid(row=1, column=3, rowspan=2, columnspan=3, sticky=N+S+E+W)
        self.f = f

        g = Frame(self)
        v = StringVar()
        # color.set('red') unknown color name "PY_VAR2"
        color = "red"
        s = Label(self, text="Open File", bg=color, borderwidth=2).grid(row=2, column=4, sticky=S+E)
        entry_widget = Entry(self, text=v, width=10).grid(row=2, column=5, sticky=S+E)
        # s is a NoneType object
        g.grid(row=2, column=5)

        color = StringVar()
        self.color = color
        self.v = v
        self.r = r
        self.__CreateButtons(event, f, v, r, s, color)
        self.pack()

    def __CreateButtons(self, event, f, v, r, s, color):

        self.button_dict = { 'button1': 'Red', 'button2': 'Blue', 'button3': 'Green', 'button4': 'Black', 'button5': 'Open' }
        for i in range(1, 6):
            for y in self.button_dict.keys():
                label = self.button_dict[y]
                if i == int(y[-1]):
                    y = Button(self, text=label)
                    y.grid(row=3, column=i, ipadx=10, sticky=N+S+E+W)
                    def handler( event, i=i):
                        return self.__ButtonHandler(event, f, v, r, s, color, i)
                    y.bind(event, handler, self)

root = Tk()
app = Application(master=root)
app.pack()
app.mainloop()
print("hello")
