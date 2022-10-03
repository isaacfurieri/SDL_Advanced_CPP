
#include "ControlsState.h"

bool ControlsState::OnEnter()
{
    m_movementText.Load("Assets/Fonts/game_over.ttf", 200);
    m_movementText.SetColor(255, 0, 0, 255);
    m_movementText.SetDimension(300, 150);
    m_movementText.SetText("Movements WASD");

    m_spellText.Load("Assets/Fonts/game_over.ttf", 200);
    m_spellText.SetColor(255, 0, 0, 255);
    m_spellText.SetDimension(600, 150);
    m_spellText.SetText("Shoot Fireball: MOUSE LEFT");

    m_buttons.push_back(Button("ArrowLeft"));
    m_buttons.push_back(Button("ArrowUp"));
    m_buttons.push_back(Button("ArrowDown"));
    m_buttons.push_back(Button("ArrowRight"));
    m_buttons.push_back(Button("Return"));

    m_spell.Load("Assets/Images/Character/fireBall.png");
    m_spell.SetImageDimension(8, 1, 800, 100);
    m_spell.SetSpriteDimension(150, 150);
    m_spell.IsAnimated(true);
    m_spell.IsAnimationLooping(true);
    m_spell.SetAnimationVelocity(1.5f);

    //m_buttonPos.x = 100;
    //m_buttonPos.y = 100;

    for (auto& button : m_buttons)
    {
        if (button.GetTag() == "ArrowLeft")
        {
            m_buttonPos.x = 0;
            m_buttonPos.y = 100;
            button.SetPosition(m_buttonPos);
        }
        if (button.GetTag() == "ArrowUp")
        {
            m_buttonPos.x = 50;
            m_buttonPos.y = 50;
            button.SetPosition(m_buttonPos);
        }
        if (button.GetTag() == "ArrowDown")
        {
            m_buttonPos.x = 50;
            m_buttonPos.y = 100;
            button.SetPosition(m_buttonPos);
        }
        if (button.GetTag() == "ArrowRight")
        {
           m_buttonPos.x = 100;
           m_buttonPos.y = 100;
           button.SetPosition(m_buttonPos);
        }
        if (button.GetTag() == "Return")
        {
            m_buttonPos.x = 50;
            m_buttonPos.y = 400;
            button.SetPosition(m_buttonPos);
        }
    }
    return true;
}

bool ControlsState::Render()
{
    m_movementText.Render(200, 25);
    m_spellText.Render(200, 200);

    for (auto& button : m_buttons)
    {
        button.Render();
    }

    m_spell.Render(15, 210, 0.0);

    return true;
}

void ControlsState::OnExit()
{
    m_movementText.Unload();
    m_spellText.Unload();
    for (auto& button : m_buttons)
    {
        button.Shutdown();
    }
}

GameState* ControlsState::Update()
{
    for (auto& button : m_buttons)
    {
        auto tag = button.GetTag();

        button.Update();

        if (button.GetState() == Button::ButtonState::Hover)
        {
        }
        if (button.GetState() == Button::ButtonState::Clicked)
        {
            if (tag == "Return")
            {
                return new MenuState;
            }
        }
    }

    m_spell.Update();

    return this;
}
