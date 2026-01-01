// Copyright (c) 2025-2026 ZED Interactive

#ifndef TEST_APP_LAYER_H
#define TEST_APP_LAYER_H

#include "purp3d.h"
#include <stdint.h>

class TestAppLayer : public Purp3D::Layer
{
public:
	TestAppLayer();
	virtual ~TestAppLayer();

	virtual void OnEvent(Purp3D::Event& event) override;

	virtual void OnUpdate(float ts) override;
	virtual void OnRender() override;
	virtual void OnImGuiRender() override;

private:
	bool OnKeyPressed(Purp3D::KeyPressedEvent& event);
	bool OnMouseButtonPressed(Purp3D::MouseButtonPressedEvent& event);
	bool OnMouseMoved(Purp3D::MouseMovedEvent& event);
	bool OnWindowClosed(Purp3D::WindowCloseEvent& event);
private:
	float m_Time = 0.0f;
	glm::vec2 m_MousePosition{ 0.0f };
};

#endif