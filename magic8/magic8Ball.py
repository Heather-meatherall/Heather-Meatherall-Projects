import random
from tqdm import tqdm
import time

#list of outcomes
outcomes = ["it is certain", "it is decidedly so", "Without a doubt", " Yes definitely", "You may rely on it",
            "As I see it, yes", "Most likely", "Outlook good", "Yes", "Signs point to yes",
            "Reply hazy, try again", "Ask again later", "Better not tell you now", "Cannot predict now", "Concentrate and ask again",
            "Don't count on it", "My reply is no", "My sources say no", "Outlook not so good", "Very doubtful"]

print("Hello! Welcome to Magic 8 Ball!")
answer = str(input("Would you like to know the future? "))

#continue giving an outcome until user inputs anything other than yes
while answer == "yes" or answer == "Yes":
    question = str(input("Please enter a yes or no question: "))
    outcome = random.randint(0,19) #picks a random number between 0 and 19

    #loading bar
    for i in tqdm (range (100), desc="Shaking..."):
        time.sleep(0.01)

    #prints the outcome from the list corresponding to the number rolled
    print(outcomes[outcome])

    #gets a value for answer avrrible from user 
    answer = str(input("Would you like to ask another question? "))

print("Have a good day!")