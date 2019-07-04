#include <iostream>
#include "VulkanApp.h"

int RunApp()
{
	VulkanApp app;
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