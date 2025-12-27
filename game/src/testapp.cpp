#include "purp3d.h"
#include <cstdio>

class TestApp : public Purp3D::Application
{
public:
	TestApp(const Purp3D::ApplicationSpecification& spec) : Application(spec)
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
	Purp3D::ApplicationSpecification spec;
	spec.Name = "Untitled Game";
	spec.WindowSpec.Width = 1280;
	spec.WindowSpec.Height = 720;

	return new TestApp(spec);
}