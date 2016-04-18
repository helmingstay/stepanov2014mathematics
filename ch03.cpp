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
Rcpp::LogicalVector sieve(int nmax) {
    using std::size_t;
    // is_prime by index, starting with 1
    Rcpp::LogicalVector marks(nmax, true);
    // prime the sieve, value = 3
    int head(1);
    while (head*head < nmax) {
        // not prime, advance
        if (!marks[head]) head++;
        int marker(head);
        // mark all factors as not prime
        while (true) {
            marker += (2*head+1);
            if (marker >= nmax ) break;
            marks[marker] = false;
            // std::cout << "## " << marker << ", " << head <<"\n";
        }
        // advance
        head++;
    }
    return(marks);
}
