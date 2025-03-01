#include <Rcpp.h>
using namespace Rcpp;

// This is a simple example of exporting a C++ function to R. You can
// source this function into an R session using the Rcpp::sourceCpp 
// function (or via the Source button on the editor toolbar). Learn
// more about Rcpp at:
//
//   http://www.rcpp.org/
//   http://adv-r.had.co.nz/Rcpp.html
//   http://gallery.rcpp.org/
//

// [[Rcpp::export]]
NumericVector fibonacciIterative(int n) {
  NumericVector sequence(n);
  int a = 0, b = 1, next;
  
  for (int i = 0; i < n; i++) {
    sequence[i] = a;
    next = a + b;
    a = b;
    b = next;
  }
  return sequence;
}

void fibonacciRecursiveFunction(NumericVector &sequence, int a, int b, int index, int n) {
  if (index >= n) return;  // Base case: Stop when index reaches n
  
  sequence[index] = a;  // Assign Fibonacci number
  fibonacciRecursiveFunction(sequence, b, a + b, index + 1, n);  // Recursive call
}

// [[Rcpp::export]]
NumericVector fibonacciRecursive(int n) {
  NumericVector sequence(n);
  fibonacciRecursiveFunction(sequence, 0, 1, 0, n);  // Start recursion
  return sequence;
}

// You can include R code blocks in C++ files processed with sourceCpp
// (useful for testing and development). The R code will be automatically 
// run after the compilation.
//

/*** R

*/
