#include"purp3d.h"
#include "testapplayer.h"

TestAppLayer::TestAppLayer()
{
	std::printf("Created new TestAppLayer!\n");

	// Create shaders
	m_Shader = Purp3D::Shader::CreateGraphicsShader("shaders/fullscreen.vert.glsl", "shaders/flame.frag.glsl");

	// Create geometry
	glCreateVertexArrays(1, &m_VertexArray);
	glCreateBuffers(1, &m_VertexBuffer);

	struct Vertex
	{
		glm::vec2 Position;
		glm::vec2 TexCoord;
	};

	Vertex vertices[] = {
		{ {-1.0f, -1.0f }, { 0.0f, 0.0f } },  // Bottom-left
		{ { 3.0f, -1.0f }, { 2.0f, 0.0f } },  // Bottom-right
		{ {-1.0f,  3.0f }, { 0.0f, 2.0f } }   // Top-left
	};

	glNamedBufferData(m_VertexBuffer, sizeof(vertices), vertices, GL_STATIC_DRAW);

	// Bind the VBO to VAO at binding index 0
	glVertexArrayVertexBuffer(m_VertexArray, 0, m_VertexBuffer, 0, sizeof(Vertex));

	// Enable attributes
	glEnableVertexArrayAttrib(m_VertexArray, 0); // position
	glEnableVertexArrayAttrib(m_VertexArray, 1); // uv

	// Format: location, size, type, normalized, relative offset
	glVertexArrayAttribFormat(m_VertexArray, 0, 2, GL_FLOAT, GL_FALSE, static_cast<GLuint>(offsetof(Vertex, Position)));
	glVertexArrayAttribFormat(m_VertexArray, 1, 2, GL_FLOAT, GL_FALSE, static_cast<GLuint>(offsetof(Vertex, TexCoord)));

	// Link attribute locations to binding index 0
	glVertexArrayAttribBinding(m_VertexArray, 0, 0);
	glVertexArrayAttribBinding(m_VertexArray, 1, 0);
}

TestAppLayer::~TestAppLayer()
{
	glDeleteVertexArrays(1, &m_VertexArray);
	glDeleteBuffers(1, &m_VertexBuffer);

	glDeleteProgram(m_Shader);
}

void TestAppLayer::OnEvent(Purp3D::Event& event)
{
	std::printf("{%s}\n", event.GetName());

	Purp3D::EventDispatcher dispatcher(event);
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
	glUseProgram(m_Shader);

	// Uniforms
	glUniform1f(0, m_Time);

	glm::vec2 framebufferSize = Purp3D::Application::Get().GetFramebufferSize();
	glUniform2f(1, framebufferSize.x, framebufferSize.y);

	glUniform2f(2, m_FlamePosition.x, m_FlamePosition.y);

	glViewport(0, 0, static_cast<GLsizei>(framebufferSize.x), static_cast<GLsizei>(framebufferSize.y));

	// Render
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);

	glBindFramebuffer(GL_FRAMEBUFFER, 0);
	glBindVertexArray(m_VertexArray);
	glDrawArrays(GL_TRIANGLES, 0, 3);
}

bool TestAppLayer::OnMouseButtonPressed(Purp3D::MouseButtonPressedEvent& event)
{
	glm::vec2 framebufferSize = Purp3D::Application::Get().GetFramebufferSize();
	float aspectRatio = framebufferSize.x / framebufferSize.y;
	glm::vec2 normalizedMousePos = (m_MousePosition / framebufferSize) * 2.0f - 1.0f;
	normalizedMousePos.x *= aspectRatio;
	normalizedMousePos.y *= -1.0f;
	normalizedMousePos.y += 0.7f;

	m_FlamePosition = -normalizedMousePos;

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