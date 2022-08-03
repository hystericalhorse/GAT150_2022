#ifndef _LOGGER_H
#define _LOGGER_H

namespace en
{
	class Logger
	{
	public:
		Logger() = default;
		~Logger() = default;

		void Log(const char* format, ...);

	private:


	};

	extern Logger __logger;
}

#endif // _LOGGER_H