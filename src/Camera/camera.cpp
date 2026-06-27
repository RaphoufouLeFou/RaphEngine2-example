#include "camera.hpp"

#include <RaphEngine2/graphics/graphic_api.hpp>
#include <RaphEngine2/inputs/keyboard.hpp>
#include <RaphEngine2/inputs/mouse.hpp>
#include <RaphEngine2/time_utils.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glm/gtx/quaternion.hpp>

float speed = 10;

using namespace raphEngine;
using namespace raphEngine::inputs;

void Camera::Start()
{
    transform_.get_position() = glm::vec3(0, 0, 2.6f);
    transform_.get_rotation() = glm::vec3(0, 0, 0);
}

glm::vec2 lastMousePos = glm::vec2(-1, -1);
bool lastMouseState = false;

void Camera::HandleMouseRotation()
{
    int WindowWidth, WindowHeight;
    WindowWidth = graphics::GraphicApi::res_x;
    WindowHeight = graphics::GraphicApi::res_y;

    glm::vec2 mousePos = Mouse::GetMousePos();

    if (Mouse::IsMouseButtonPressed(Mouse::MouseButton::RIGHT)
        && Mouse::IsMouseOnScreen() && Mouse::IsWindowFocused())
    {
        glm::vec2 MiddleScreen = glm::vec2(WindowWidth / 2, WindowHeight / 2);
        if (!lastMouseState)
            mousePos = MiddleScreen;
        glm::vec2 delta = mousePos - MiddleScreen;
        glm::vec3& rot = transform_.get_rotation();
        rot.x -= delta.y * 0.1f;
        rot.z -= delta.x * 0.1f;
        Mouse::SetMouseVisibility(false);
        Mouse::SetMousePosition(MiddleScreen.x, MiddleScreen.y);
        lastMouseState = true;
    }
    else
    {
        Mouse::SetMouseVisibility(true);
        if (lastMouseState)
            Mouse::SetMousePosition(lastMousePos.x, lastMousePos.y);
        lastMousePos = mousePos;
        lastMouseState = false;
    }
}

void Camera::Update()
{
    HandleMouseRotation();

    glm::vec3& pos = transform_.get_position();
    const glm::vec3& rot = transform_.get_rotation();

    glm::mat4 RotationMat = glm::toMat4(glm::quat(glm::radians(rot)));
    glm::vec3 movement = glm::vec3(0);

    float multiplier = 1;

    if (Key::IsKeyPressed(Key::KeyCode::KEY_LEFT_SHIFT))
        multiplier = 15;
    if (Key::IsKeyPressed(Key::KeyCode::KEY_LEFT_CONTROL))
        multiplier = 0.1f;

    if (Key::IsKeyPressed(Key::KeyCode::KEY_W))
        movement.y += speed * multiplier * Time::deltaTime;
    if (Key::IsKeyPressed(Key::KeyCode::KEY_S))
        movement.y -= speed * multiplier * Time::deltaTime;
    if (Key::IsKeyPressed(Key::KeyCode::KEY_D))
        movement.x += speed * multiplier * Time::deltaTime;
    if (Key::IsKeyPressed(Key::KeyCode::KEY_A))
        movement.x -= speed * multiplier * Time::deltaTime;

    glm::vec3 direction = glm::vec3(RotationMat * glm::vec4(movement, 1));

    pos += direction;
}
