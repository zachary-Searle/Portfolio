import threading

def main():
    threads = []
    results = [None] * 10
    for i in range(10):
        curThread = threading.Thread ( target=ThreadStuff, args=(i, results))
        curThread.start()
        threads.append(curThread)
    for thread in threads:
        thread.join()
    for num in results:
        print(num)
    


def ThreadStuff(threadID, results):
    print("I'm in thread: ", threadID)
    results[threadID] = threadID + 1
    print("Returning: ", threadID)


if __name__ == "__main__":
    main()