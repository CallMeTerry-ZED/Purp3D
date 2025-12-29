#define INCLUDE_ENTRY_POINT
#include "purp3d.h"
#include "testapplayer.h"
#include <cstdio>
#include <sol/sol.hpp>

class TestApp : public Purp3D::Application
{
public:
	TestApp(const Purp3D::ApplicationSpecification& spec) : Application(spec)
	{
		auto* testLayer = PushLayer<TestAppLayer>();
		std::printf("Current layer debug name: %s\n", testLayer->GetName());

		sol::state lua;
		lua.open_libraries(sol::lib::base, sol::lib::math);
		try
		{
			lua.script("print('Hello from Lua!')");
			lua.script("result = 2 + 2");
			int result = lua.get<int>("result");
			PURP_CLIENT_TRACE("The result from Lua is: {0}", result);

			PURP_CLIENT_INFO("Lua scripts executed successfully!");
		}
		catch (const sol::error& err)
		{
			std::cerr << "Lua error: " << err.what() << std::endl;
		}
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