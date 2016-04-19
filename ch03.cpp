#include <Rcpp.h>
#include <vector>
#include <stdexcept>

// v = 2 * i - 1
// i = (v + 1 )/2
// v^2 = 4i^2 - 4i + 1
// v^2 = (2i -1)(2i-1)
// v^2 = (2i -1)(2i-1)
//i_v2 = 2i^2 -2i +1
 
// [[Rcpp::export]]
int sieve(int nmax) {
//Rcpp::LogicalVector sieve(int nmax) {
    using std::size_t;
    // is_prime by index, starting with 1
    std::vector<size_t> marks(nmax, 1);
    std::partial_sum(marks.begin(), marks.end(), marks.begin());
    // prime the sieve, value = 3
    size_t head(0);
    size_t head_sq(3);
    size_t factor(3);
    while (head_sq < nmax) {
        // not prime, advance
        if (marks[head]) {
            size_t marker(head_sq);
            // mark all factors as not prime
            while (true) {
                marks[marker] = 0;
                marker += factor;
                if (marker >= nmax ) break;
                // std::cout << "## " << marker << ", " << head <<"\n";
            }
        }
        // advance
        head++;
        factor = head + head + 3;
        head_sq = 2*head * (head+3)+3;
    }
    int nprime = nmax - std::count(marks.begin(), marks.end(), 0);
    //Rcpp::LogicalVector marks(nprime, true);
    return(nprime);
}
