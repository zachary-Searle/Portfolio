This is a c++ program for a square sum solver. What that means is when given a number n it takes numbers
1...n and finds and list where each pair in the list adds to a perfect square. 15 is the smallest number you can do it with
and the answer is [ 9, 7, 2, 14, 11, 5, 4, 12, 13, 3, 6, 10, 15, 1, 8 ] or it can be backwards. As you can see, the first two numbers(9 and 7)
add up to the number 16 which is a perfect square. If we shift over one (7 and 2), these add up to 9 which also a perfect square, so on and so forth.

It solves this using recursive backtracking. squareSumsRow is just a driver and recursiveHelper is the recursive part. It also the main part I want to optimize
as backtracking has a bigO(n!) time complexity. This means that while it's okay at smaller numbers, getting into the 50s makes it take forever. I also need 
to implement input checking so that they user can't pass something in that isn't a number. Another optimization I want to do is to save the combinations
of numbers that do and don't add up to a perfect square. By using std::pair and a map, I could save which pairs of numbers do and don't work together making
it so I don't need to do all the math every time.