// Copyright (c) 2025-2026 ZED Interactive

#include"purp3d.h"
#include "testapplayer.h"

TestAppLayer::TestAppLayer() : Layer("TestAppLayer")
{
	std::printf("Created new TestAppLayer!\n");
}

TestAppLayer::~TestAppLayer()
{

}

void TestAppLayer::OnEvent(Purp3D::Event& event)
{
	Purp3D::EventDispatcher dispatcher(event);

	dispatcher.Dispatch<Purp3D::KeyPressedEvent>([this](Purp3D::KeyPressedEvent& e) { return OnKeyPressed(e); });
	dispatcher.Dispatch<Purp3D::MouseButtonPressedEvent>([this](Purp3D::MouseButtonPressedEvent& e) { return OnMouseButtonPressed(e); });
	dispatcher.Dispatch<Purp3D::MouseMovedEvent>([this](Purp3D::MouseMovedEvent& e) { return OnMouseMoved(e); });
	dispatcher.Dispatch<Purp3D::WindowCloseEvent>([this](Purp3D::WindowCloseEvent& e) { return OnWindowClosed(e); });
}

void TestAppLayer::OnUpdate(float ts)
{
	m_Time += ts;
}

void TestAppLayer::OnRender()
{

}

void TestAppLayer::OnImGuiRender()
{
	ImGui::Begin("Test App Layer");
	ImGui::Text("Hello there from Purp3D");
	ImGui::End();
}

bool TestAppLayer::OnKeyPressed(Purp3D::KeyPressedEvent& event)
{

	return false;
}

bool TestAppLayer::OnMouseButtonPressed(Purp3D::MouseButtonPressedEvent& event)
{
	glm::vec2 framebufferSize = Purp3D::Application::Get().GetFramebufferSize();
	float aspectRatio = framebufferSize.x / framebufferSize.y;
	glm::vec2 normalizedMousePos = (m_MousePosition / framebufferSize) * 2.0f - 1.0f;
	normalizedMousePos.x *= aspectRatio;
	normalizedMousePos.y *= -1.0f;
	normalizedMousePos.y += 0.7f;

	return false;
}

bool TestAppLayer::OnMouseMoved(Purp3D::MouseMovedEvent& event)
{
	m_MousePosition = { event.MouseX, event.MouseY };

	return false;
}

bool TestAppLayer::OnWindowClosed(Purp3D::WindowCloseEvent& event)
{
	std::printf("Window Closed!\n");

	return false;
}