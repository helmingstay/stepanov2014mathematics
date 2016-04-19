source('config.R')

## sieve
n.max <- 1e3; 
#odds <- ((1:n.max)*2-1); 
#primes <- odds[sieve(n.max)]


## count primes
nn = 10^(1:5); 
mm = unlist( lapply(nn, sieve))
ll = data.frame(nn,mm)
xyplot(mm ~ (2*nn+1), ll, 
    scales=list(log=F), type=c('l','g')
)
