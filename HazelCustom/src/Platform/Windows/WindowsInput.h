#pragma once

#include "HazelCustom/Input.h"

namespace HazelCustom 
{
    class WindowsInput : public Input
    {
    protected:
        // Keep using "virtual" keyword because these functions (with or without the keyword)
        // are still virtual functions. This makes the code easier to understand and less ambiguous.
        virtual bool IsKeyPressedImpl(int keycode) override;

        virtual bool IsMouseButtonPressedImpl(int button) override;
        virtual std::pair<float, float> GetMousePositionImpl() override;
        virtual float GetMouseXImpl() override;
        virtual float GetMouseYImpl() override;
    };
}