#include "Time.h"

namespace en
{
	void Time::tick()
	{
		clock_duration duration = clock::now() - _starttimepoint;
		time = duration.count() / (float) clock_duration::period::den;

		duration = clock::now() - _frametimepoint;
		ci_time = duration.count() / (float)clock_duration::period::den;

		_frametimepoint = clock::now();
	}
}