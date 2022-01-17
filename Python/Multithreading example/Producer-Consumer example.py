import threading
import sys
from typing import Deque

"this is the number of threads, making it a function makes it so I can't change it"
def NumOfThreads(): return 5

"These will be used to lock the buffers so multiple threads don't try to write"
mpLock = threading.Lock()
pcLock = threading.Lock()

"The actual buffers, the first just contains numbers"
MPBuffer = Deque()
"The second contains lists"
PCBuffer = Deque()

"these are so the threads know they are done"
numOfArgs = 0
pArgs = 0
cArgs = 0

"main fills the MPBuffer and starts the threads"
def main():
    args = sys.argv[1:]
    "verify that the input is okay"
    while not VerifyInput(args):
        "if the input is not okay, keep looping until they put in a good input"
        print("Input is not acceptable, please only input integers")
        args = [int(x) for x in input("Please renter input: ").split()]
    global numOfArgs, MPBuffer, mpLock
    numOfArgs = len(args)
    "StartThreads() returns a tuple containing the producers and consumers"
    producers, consumers = StartThreads()
    for arg in args:
        "mpLock stops producers from grabbing something while main puts arg on the buffer"
        mpLock.acquire()
        MPBuffer.append(arg)
        mpLock.release()
    for producer in producers:
        producer.join()
    for consumer in consumers:
        consumer.join()
    

def VerifyInput(args):
    """we loop through the input and make sure that all of them can 
    turned into integers"""
    for arg in args:
        try:
            int(arg)
        except:
            return False
    return True


def StartThreads():
    producers = []
    consumers = []
    for i in range(NumOfThreads()):
        "initialize the threads"
        producer = threading.Thread(target=Producer)
        consumer = threading.Thread(target=Consumer)
        "append them to the lists"
        producers.append(producer)
        consumers.append(consumer)
        "start the threads"
        producer.start()
        consumer.start()
    "these will be unpacked when we get back in main"
    return (producers, consumers)

def Producer():
    global MPBuffer, mpLock
    global PCBuffer, pcLock
    global numOfArgs, pArgs
    "this lets all the producers know that there is nothing left to grab"
    while pArgs < numOfArgs:
        "this will keep running as long as MPBuffer has things in it"
        while MPBuffer:   
            num = None
            output = []
            "this stops main from pushing stuff onto the buffer while the produver grabs from it"
            mpLock.acquire()
            num = int(MPBuffer.popleft())
            pArgs += 1
            mpLock.release()

            "this is for formatting later down the line"
            output.append(num)
            "The producer than figures out the factors of the given number"
            "the first is if the number is positive"
            if num >= 1:
                for x in range(1, num + 1):
                    if (num % x) == 0:
                        output.append(x)
            elif num < 0:
                "this is for it is negative"
                for x in range(num, 0):
                    if (num % x) == 0:
                        output.append(x)

            "pcLock stops consumers from grabbing while the producer pushes output onto the buffer"
            pcLock.acquire()
            PCBuffer.append(output)
            pcLock.release()

        
        


def Consumer():
    global PCBuffer, pcLock
    global numOfArgs, cArgs
    "This lets the consumer threads that there is nothing left to print"
    while cArgs < numOfArgs:
        x = None
        while PCBuffer:
            "stops the producers from pushing something onto the buffer while consumer grabs from it"
            pcLock.acquire()
            x = PCBuffer.popleft()
            cArgs += 1
            "we also keep the print in the lock to stop other consumers from trying to print at the same time"
            "this is the formatting I was talking about, end ="" makes it so there isn't a newline at the end"
            print(f"{x[0]}: ", end="")
            "We then print the rest of the list seperated by commas"
            print(*x[1:], sep=",")
            pcLock.release()

if __name__ == "__main__":
    main()
    
