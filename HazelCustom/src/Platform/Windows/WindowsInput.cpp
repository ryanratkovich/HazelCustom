#include "hczpch.h"
#include "WindowsInput.h"

#include "HazelCustom/Application.h"
#include <GLFW/glfw3.h>

namespace HazelCustom
{
    Input* Input::s_Instance = new WindowsInput();

    // Asking GLFW if this key is pressed / held down, if so, return true
    bool WindowsInput::IsKeyPressedImpl(int keycode)
    {
        // Static casted void* to GLFWwindow*
        auto window = static_cast<GLFWwindow*>(Application::Get().GetWindow().GetNativeWindow());
        auto state = glfwGetKey(window, keycode);
        return state == GLFW_PRESS || state == GLFW_REPEAT;
    }

    bool WindowsInput::IsMouseButtonPressedImpl(int button)
    {
        auto window = static_cast<GLFWwindow*>(Application::Get().GetWindow().GetNativeWindow());
        auto state = glfwGetMouseButton(window, button);
        return state == GLFW_PRESS;
    }

    std::pair<float, float> WindowsInput::GetMousePositionImpl()
    {
        auto window = static_cast<GLFWwindow*>(Application::Get().GetWindow().GetNativeWindow());
        double xpos, ypos;
        glfwGetCursorPos(window, &xpos, &ypos);

        return { (float)xpos, (float)ypos }; // Returns as std::pair<float, float>
    }

    float WindowsInput::GetMouseXImpl()
    {
        // Available in C++17 or greater
        auto[x, y] = GetMousePositionImpl();
        return x;
    }

    float WindowsInput::GetMouseYImpl()
    {
        auto[x, y] = GetMousePositionImpl();
        return y;
    }
}