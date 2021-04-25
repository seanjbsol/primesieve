// C++ program to print all primes smaller than or equal to
// n using Sieve of Eratosthenes
#include <iostream>
#include <chrono>
#include <ctime>
// included to support gcc compiler
#include <cstring>

void SieveOfEratosthenes(int n)
{
	// Create a boolean array "prime[0..n]" and initialize
	// all entries it as true. A value in prime[i] will
	// finally be false if i is Not a prime, else true.
	bool prime[n+1];
	memset(prime, true, sizeof(prime));

	for (int p=2; p*p<=n; p++)
	{
		// If prime[p] is not changed, then it is a prime
		if (prime[p] == true)
		{
			// Update all multiples of p
			for (int i=p*2; i<=n; i += p)
				prime[i] = false;
		}
	}

	// Print all prime numbers
	for (int p=2; p<=n; p++)
	if (prime[p])
		std::cout << p << " ";
}

// Driver Program to test above function
int main()
{
	auto start = std::chrono::system_clock::now();
	auto current = std::chrono::system_clock::now();
	std::chrono::duration<double> duration = (current - start);
    // Some computation here
	int l = 0;
	while (duration.count() <= 30.0) {
		l++;
		int n = 1000000; 
		std::cout << "Following are the prime numbers smaller than or equal to " << n << std::endl;
		SieveOfEratosthenes(n);
		current = std::chrono::system_clock::now();
		duration = current - start;
	}
    std::time_t end_time = std::chrono::system_clock::to_time_t(current);

    std::cout << std::endl << "finished computation at " << std::ctime(&end_time) << std::endl
              << "elapsed time: " << duration.count() << std::endl << "Number of itersations: " << l << std::endl;


	return 0;
}

