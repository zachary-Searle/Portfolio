This is a simple producer/consumer example in python. It takes a list of integers from command line and figures out the factors of that number.
It validates the input to make sure that the user has given integers only. The number of threads can be changed by changing the number in NumOfThreads()
It is broken down into three parts; Main, Producer, and Consumer.
Main:
	Gets input from command line
	Validates input, if input is bad, get new input
	Starts the threads
	Pushes inputs into a buffer for Producers
Producers:
	Pulls numbers off of MPBuffer
	Figures out the factors of the number and stores them in a list
	Pushes list of numbers onto PCBuffer
Consumers:
	Pulls list of numbers off PCBuffer
	Prints the list of numbers
