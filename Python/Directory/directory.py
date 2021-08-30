#!/usr/bin/python3.7
# filename : directory.py 

from datetime import datetime

###### declare root list#####
root = []


##########declare classes###############
class Item:
    def __init__(self, name, parentdir, permissions):
        self.name = name
        self.parentdir = parentdir
        self.permissions = permissions


class Directory(Item):  
    def __init__(self, name, parentdir, permissions):
        self.UpdDate = datetime.now()
        self.dir = []
        Item.__init__(self, name, parentdir, permissions)


class File(Item):
    def __init__(self, name, parentdir, permissions, size):
      self.size = size
      Item.__init__(self, name, parentdir, permissions)


######################function calls for each case#######################
def command1():
    fname = input("    Please enter File name or quit: ")
    if fname == "quit":
        return
    pdname = input("    Please enter Directory name or quit: ")
    if pdname == "quit":
        return
    if any(obj.name == pdname for obj in root) == False:
        print("    ERROR: Parent Directory does not exist.")
        return
    faccess = input("    Please enter access permissions using format rwx or quit: ")
    if faccess == "quit":
        return
    size = input("    Please enter size(1-Small, 2-Medium, 3-Large: ")
    for obj in root:
        if obj.name == pdname: 
            obj.dir.append(File(fname, pdname, faccess, size))
            print("    Created File: " + obj.name + "/" + fname)
    print(" ")
    random = input("    ")
    return


def command2():
    dname = input("    Please enter Directory name or quit: ")
    if dname == "quit":
        return
    pname = input("    Please enter parent directory name or quit: ")
    if pname == "quit":
        return    
    if (any(obj.name == pname for obj in root) == False) and (pname != "root"):
        print("    ERROR: Parent Directory does not exist.")
        return
    access = input("    Please enter access permissions using format rwx or quit: ")
    if access == "quit":
        return  
    root.append(Directory(dname, pname, access))
    print("    Created Directory: " + dname)


def command3():
     ford = input("    File or Directory?: ")
     if ford == "file":
         frname = input("    Please enter file name or quit: ")
         if frname == "quit":
            return
         pname = input("    Please enter parent directory name or quit: ")
         if pname == "quit":
            return
         if (any(obj.name == pname for obj in root) == False) and (pname != "root"):
            print("    ERROR: Parent Directory does not exist.")
            return
         for obj in root:
            if obj.name == pname: 
                for rm in obj.dir:
                    if rm.name == frname:
                        obj.dir.remove(rm)
     elif ford == "directory":
         pname = input("    Please enter parent directory name or quit: ")
         if pname == "quit":
            return
         if (any(obj.name == pname for obj in root) == False) and (pname != "root"):
            print("    ERROR: Parent Directory does not exist.")
            return
         for obj in root:
            if obj.name == pname:
                root.remove(obj)
     print( "     " + pname + "/" + frname + " deleted")
         




def command4():
    for obj in root: 
        print("     " + obj.name)
        for fill in obj.dir:
            print("         " + fill.name)


######################main driver of code######################
exit = 0
startup = """
    Welcome to Python's Filesystem
    -------------------------------
    """
print(startup)

while exit != -1:

    ######main menu#######
    MainMenu = """
    Main Menu
    1. Create File
    2. Create Directory
    3. Remove a file/directory
    4. Display File System
    5. Exit
    """
    print(MainMenu)


    ###setup vars### 
    command = input("    Choice: ")


    #####handle case 1: create file######
    if command == "1":
        command1()


    #####handle case 2: create directory#####
    elif command == "2":
        command2()
            
        
    #####handle case 3: remove file/directory######
    elif command == "3":
        command3()


    ######handle case 4: Display file system########
    elif command == "4":
        command4()


    #####handle case 5: exit#####
    elif command == "5":
        exitString = """
    Goodbye! 
    -------------------------------
        """
        print(exitString)
        exit = -1


    #### error message if invalid command####
    else:
        print("    ERROR! Try again")
    
