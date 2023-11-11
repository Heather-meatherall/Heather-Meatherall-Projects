import random
import tkinter as tk
from PIL import Image, ImageTk

x = 1390
cycle = 0
check = 1
idleNum = [1,2,3,4]
peekNum = [6,7,8,9]
sleepNum = [11,12,13,14,15]
eventNum = random.randrange(1,3,1)

#Image arrays
idle = []
peek = []
sleep = []
wakeUp = []
goSleep = []

impath = 'C:\\Users\\Owner\\projects\\FoxDesktop\\'

#transfer random number to event
def event(cycle, check, eventNum, x):
   #1,2,3,4 = idle event
    if eventNum in idleNum:
      check = 0
      window.after(500,update,cycle,check,eventNum,x)
    
    # 5 = to sleep
    elif eventNum == 5:
       check = 1
       window.after(400,update,cycle,check,eventNum,x)

    # 6,7,8,9 = sleep event
    elif eventNum in sleepNum:
       check = 2
       window.after(1000,update,cycle,check,eventNum,x)
    
    # 10 =  wake up event
    elif eventNum == 10:
       check = 3
       window.after(400,update,cycle,check,eventNum,x)

    # 11,12,13,14,15 = peak event
    elif eventNum in peekNum:
       check = 4
       window.after(1000,update,cycle,check,eventNum,x)

          
# cycles through the array (each frame of the gif)
def runGif(cycle,frames,eventNum,first,last):
 if cycle < len(frames)-1:
  cycle+=1
 else:
  cycle = 0
  eventNum = random.randrange(first,last+1,1)
 return cycle,eventNum

def update(cycle, check, eventNum, x):
    #idle
    if check == 0:
      frame = idle[cycle]
      cycle, eventNum = runGif(cycle, idle, eventNum,1,9)
    
    #go to sleep
    elif check == 1:
       frame = goSleep[cycle]
       cycle, eventNum = runGif(cycle, goSleep, eventNum,11,11)

    #sleep
    elif check == 2:
       frame = sleep[cycle]
       cycle, eventNum = runGif(cycle, sleep, eventNum,10,15)
    
    #wake up
    elif check == 3:
       frame = wakeUp[cycle]
       cycle, eventNum = runGif(cycle, wakeUp, eventNum,1,1)
    
    #peek
    elif check == 4:
       frame = peek[cycle]
       cycle, eventNum = runGif(cycle, peek, eventNum,1,9)
    window.geometry('90x95+'+str(x)+'-30')
    
    label.configure(image=frame)
    window.after(1,event,cycle,check,eventNum,x)

window = tk.Tk()

#resize images
image1 = Image.open(impath + 'gifsFrames\\foxidle1.png')
image1 = image1.resize((100,100))
img1 = ImageTk.PhotoImage(image1)

image2 = Image.open(impath + 'gifsFrames\\foxidle2.png')
image2 = image2.resize((100,100))
img2 = ImageTk.PhotoImage(image2)

image3 = Image.open(impath + 'gifsFrames\\foxpeek1.png')
image3 = image3.resize((100,100))
img3 = ImageTk.PhotoImage(image3)

image4 = Image.open(impath + 'gifsFrames\\foxsleep1.png')
image4 = image4.resize((100,100))
img4 = ImageTk.PhotoImage(image4)

image5 = Image.open(impath + 'gifsFrames\\foxsleep2.png')
image5 = image5.resize((100,100))
img5 = ImageTk.PhotoImage(image5)

image6 = Image.open(impath + 'gifsFrames\\foxsleep3.png')
image6 = image6.resize((100,100))
img6 = ImageTk.PhotoImage(image6)

image7 = Image.open(impath + 'gifsFrames\\transition.png')
image7 = image7.resize((100,100))
img7 = ImageTk.PhotoImage(image7)

image8 = Image.open(impath + '\gifsFrames\\foxpeek2.png')
image8 = image8.resize((100,100))
img8 = ImageTk.PhotoImage(image8)

# put gif frames to an array
# idle

idle.append(img1)
idle.append(img2)
idle.append(img1)
   
# sleep
sleep.append(img4)
sleep.append(img5)
sleep.append(img6)
sleep.append(img4)

# wake up
wakeUp.append(img4)
wakeUp.append(img7)
wakeUp.append(img1)

# go to sleep
goSleep.append(img1)
goSleep.append(img7)
goSleep.append(img4)

# peek
peek.append(img1)
peek.append(img3)
peek.append(img8)
peek.append(img3)
peek.append(img1)

# window configuration
window.config(highlightbackground='black')

window.overrideredirect(True)
window.wm_attributes('-topmost', True)
window.wm_attributes('-transparentcolor','#00bf63')

label = tk.Label(window,bd=0)
label.pack()

window.after(5,update,cycle,check,eventNum,x)
window.mainloop() 