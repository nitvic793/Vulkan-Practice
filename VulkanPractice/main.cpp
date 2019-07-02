#include <iostream>
#include "TriangleApp.h"

int RunApp()
{
	TriangleApp app;
	try
	{
		app.Run();
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
		return EXIT_FAILURE;
	}

	return EXIT_SUCCESS;
}

int main()
{
	return RunApp();
}