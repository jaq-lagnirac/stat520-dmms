#include <Rcpp.h>
using namespace Rcpp;

// You can source this function into an R session using the Rcpp::sourceCpp 
// function (or via the Source button on the editor toolbar). Learn
// more about Rcpp at:
//
//   http://www.rcpp.org/
//   http://adv-r.had.co.nz/Rcpp.html
//   http://gallery.rcpp.org/
//

// [[Rcpp::export]]
double mean_cpp(NumericVector vect)
{
  // initializes variables
  unsigned n = vect.size(); // gets size
  double total = 0;
  
  // iterates over vector, aggregates values
  for(unsigned i = 0; i < n; ++i)
  {
    total += vect[i];
  }
  
  // finds and returns average (mean)
  double average = total / n;
  return average;
}


// [[Rcpp::export]]
double median_cpp(NumericVector vect)
{
  unsigned n = vect.size(); // gets size
  NumericVector sorted_vect = vect.sort();

  if (n % 2 == 0) // if length is even
  {
    // get index
    unsigned index_right = n / 2;
    unsigned index_left = index_right - 1;
    
    // find average of two midpoint values and returns it
    double midpoint_right = sorted_vect[index_right];
    double midpoint_left = sorted_vect[index_left];
    double average = (midpoint_right + midpoint_left) / 2;
    return average; // function ends here
  }
  // if length is odd, run the following code:

  // finds midpoint value and returns it
  unsigned index = n / 2;
  return sorted_vect[index];
}


// [[Rcpp::export]]
double min_cpp(NumericVector vect)
{
  NumericVector sorted_vect = vect.sort();
  return sorted_vect[0];
}


// [[Rcpp::export]]
double max_cpp(NumericVector vect)
{
  unsigned last_index = vect.size() - 1;
  NumericVector sorted_vect = vect.sort();
  return sorted_vect[last_index];
}


// [[Rcpp::export]]
double first_quartile_cpp(NumericVector vect)
{
  unsigned n = vect.size();
  NumericVector sorted_vect = vect.sort();
  unsigned midpoint = n / 2;
  
  // finding the first quartile
  if (midpoint % 2 == 0) // if length is even
  {
    // get index
    unsigned index_right = midpoint / 2;
    unsigned index_left = index_right - 1;
    
    // find average of two midpoint values and returns it
    double first_quartile_right = sorted_vect[index_right];
    double first_quartile_left = sorted_vect[index_left];
    double average = (first_quartile_right + first_quartile_left) / 2;
    return average; // function ends here
  }
  // if length is odd, run the following code:
  
  // finds midpoint value and returns it
  unsigned index = midpoint / 2;
  return sorted_vect[index];
}

// [[Rcpp::export]]
double third_quartile_cpp(NumericVector vect)
{
  unsigned n = vect.size();
  NumericVector sorted_vect = vect.sort();
  unsigned midpoint = n / 2;

  if ((n - midpoint) % 2 == 0)
  {
    // get index
    unsigned index_left = (midpoint / 2) + midpoint - 1;
    unsigned index_right = index_left + 1;
    
    // find average of two midpoint values and returns it
    double third_quartile_right = sorted_vect[index_right];
    double third_quartile_left = sorted_vect[index_left];
    double average = (third_quartile_right + third_quartile_left) / 2;
    return average; // function ends here
  }

  unsigned index = (midpoint / 2) + midpoint;
  return sorted_vect[index];
}


// [[Rcpp::export]]
NumericVector fivenum_cpp(NumericVector vect)
{
  NumericVector return_vect = NumericVector::create(min_cpp(vect),
                                                    first_quartile_cpp(vect),
                                                    median_cpp(vect),
                                                    third_quartile_cpp(vect),
                                                    max_cpp(vect));
  return return_vect;
}

// You can include R code blocks in C++ files processed with sourceCpp
// (useful for testing and development). The R code will be automatically 
// run after the compilation.
//

/*** R
# stat520_seminar1.cpp successfully loaded!
*/
