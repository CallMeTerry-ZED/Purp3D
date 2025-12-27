#ifndef ENTRYPOINT_H
#define ENTRYPOINT_H

#ifdef PURP_PLATFORM_WINDOWS

extern Purp3D::Application* Purp3D::CreateApplication();

int main(int argc, char** argv)
{
	Purp3D::Application* app = Purp3D::CreateApplication();
	app->Run();
	delete app;
	return 0;
}

#endif

#endif