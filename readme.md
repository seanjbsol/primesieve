This is a test benchmarking program to be compiled by the native compiler.

Specifically written to benchmark single core performance in the m1 chip vs other architectures.

I have 2 setups.

1. AMD Ryzen5 3550H with 24GB of ram. 
2. Macbook Air M1 chip 8GB of ram.

I compiled the source using clang++ on the mac, and under WSL2 on the AMD using gcc, 57 and in visual studio with vc (though I had to add an additional library and remove some of the output to get the compiler to compile)

My results:

AMD:
gcc
1. 30.0559 78 iterations
2. 30.1505 79 iterations
3. 30.3115 82 iterations
4. 30.2788 83 iterations

vc++
1. 30.9 3 iterations
2. 30.8957 3 iterations
- I then abandoned this test. I suspect that the IO is slower and, as the sieve sends output to cout this may be slowing down the execution on windows.

Mac:

1. 30.0274 301 iterations
2. 30.0896 265 iterations
3. 30.0239 278 iterations
4. 30.0383 277 iterations

The binary sizes:

AMD GCC 19920
AMD VC++ 14848
Mac clang++ 59954

I'm not sure why the compiled file is so much larger on the mac than the other two compiled versions, but it is certainly the most performant