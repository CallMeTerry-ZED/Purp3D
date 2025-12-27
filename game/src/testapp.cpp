#include "purp3d.h"
#include <cstdio>

class TestApp : public Purp3D::Application
{
public:
	TestApp()
	{
		std::printf("Sandbox created\n");
	}

	~TestApp()
	{
		std::printf("Sandbox destroyed\n");
	}
};

Purp3D::Application* Purp3D::CreateApplication()
{
	return new TestApp();
}