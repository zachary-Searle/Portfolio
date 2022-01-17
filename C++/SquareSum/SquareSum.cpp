#include <vector>
#include <algorithm>
#include <cmath>
#include <iostream>
#include <sstream>
#include <iterator>

bool checkIfSquare (int x, int y){
  int temp = x + y;
  int root = std::sqrt (temp);
  if (root * root == temp){
      return true;
  }
  return false;
}

std::vector<int> recursiveHelper (int n, std::vector<int> squareSum){
  int end = *(squareSum.end () - 1);
  for (int i = 1; i <= n; i++){
      if (std::find (squareSum.begin (), squareSum.end (), i) == squareSum.end ()){
	    if (checkIfSquare (end, i)){
	      squareSum.push_back (i);
	      squareSum = recursiveHelper (n, squareSum);
	      if (squareSum.size () == n)
		    return squareSum;
	      else
		    squareSum.pop_back ();
	    }
	  }
  }
  return squareSum;
}


std::vector<int> squareSumsRow (int n){
  std::vector < int >squareSum;
  for (int i = 1; i <= n; i++){
      squareSum.push_back (i);
      squareSum = recursiveHelper (n, squareSum);
    if (squareSum.size () == n)
	  return squareSum;
    else{
      squareSum.clear ();
	}
  }
  return squareSum;
}

int main (int argc, char *argv[]){
  for (int i = 1; i < argc; i++){
      std::string str (argv[i]);
      std::istringstream myStrm (str);
      int val;
      myStrm >> val;
      std::vector < int >result = squareSumsRow (val);
      if (!result.empty ()){
	    std::transform (std::begin (result), std::prev (std::end (result)),
			  std::ostream_iterator < size_t > (std::cout, ", "),
			  [](const int &val){return val;});
	    std::cout << val << ": " << result.back () << std::endl;
	  }else{
	    std::cout << val << ": no solution found" << std::endl;
	  }
    }
}
