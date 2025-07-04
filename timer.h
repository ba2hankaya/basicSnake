#ifndef TIMER_H
#define TIMER_H

#include <chrono>

class Timer
{
	private:
		std::chrono::time_point<std::chrono::high_resolution_clock> start;
		std::chrono::time_point<std::chrono::high_resolution_clock> cur;
	public:
		Timer();
		double getTime() const;
		void update();
};

#endif
