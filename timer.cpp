#include "timer.h"

Timer::Timer()
{
	start = std::chrono::high_resolution_clock::now();
}

int Timer::getTime(){

	int elapsed = (long int)std::chrono::duration_cast<std::chrono::seconds>(cur - start).count();
	return elapsed;
}

void Timer::update()
{
	cur = std::chrono::high_resolution_clock::now();
}
