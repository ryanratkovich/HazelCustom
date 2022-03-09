#pragma once

#include "HazelCustom/Layer.h"

#include "HazelCustom/Events/ApplicationEvent.h"
#include "HazelCustom/Events/KeyEvent.h"
#include "HazelCustom/Events/MouseEvent.h"

namespace HazelCustom
{
    class HAZEL_CUSTOM_API ImGuiLayer : public Layer
    {
    public:
        ImGuiLayer();
        ~ImGuiLayer();

        virtual void OnAttach() override;
        virtual void OnDetach() override;
        virtual void OnImGuiRender() override;

        void Begin();
        void End();

    private:
        float m_Time = 0.0f;
    };
}