#include "timer.h"

Timer::Timer()
{
	start = std::chrono::high_resolution_clock::now();
}

double Timer::getTime(){
    std::chrono::duration<double> elapsed = cur - start;
    return elapsed.count();
}

void Timer::update()
{
	cur = std::chrono::high_resolution_clock::now();
}
