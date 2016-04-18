source('config.R')

## sieve
n.max <- 1e3; 
odds <- ((1:n.max)*2-1); 
primes <- odds[sieve(n.max)]

