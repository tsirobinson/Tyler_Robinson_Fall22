/*
- Included Coda.h
- Inherit a class from CodaApp and override OnUpdate
- Feed the name of your class into START_CODA_GAME macro
*/

#include "Coda.h"

class GEFall22 : public Coda::CodaApp
{
public:
	GEFall22() {
		Coda::CodaWindow::GetWindow()->SetKeyPressedCallback(
			[this](const Coda::KeyPressedEvent& event) {OnKeyPress(event); });
		
		Coda::CodaWindow::GetWindow()->SetKeyReleasedCallback(
			[this](const Coda::KeyReleasedEvent& event) {OnKeyRelease(event); });
	}

	void OnUpdate() override {

	}

private:
	Coda::Picture m_Background{ "Assets/Textures/background.png" };
	Coda::Unit m_Character{ "Assets/Textures/character.png", 1 };
	std::vector<Coda::Unit> m_Targets;
	int m_Speed{ 30 };

	int m_Score{ 0 };
	int m_Frames{ 0 };

	enum class CharState {
		MOVE_LEFT,
		MOVE_RIGHT,
		MOVE_UP,
		MOVE_DOWN,
		STILL
	} m_State{ CharState::STILL };

	void OnKeyPress(const Coda::KeyPressedEvent& event) {
		switch (event.GetKeyCode()) {
		case CODA_KEY_LEFT:
			m_State = CharState::MOVE_LEFT;
			break;
		case CODA_KEY_RIGHT:
			m_State = CharState::MOVE_RIGHT;
			break;
		case CODA_KEY_UP:
			m_State = CharState::MOVE_UP;
			break;
		case CODA_KEY_DOWN:
			m_State = CharState::MOVE_DOWN;
			break;
		}
	}

	void OnKeyRelease(const Coda::KeyReleasedEvent& event) {
		switch (event.GetKeyCode()) {
		case CODA_KEY_LEFT:
			if (m_State == CharState::MOVE_LEFT)
				m_State = CharState::STILL;
			break;
		case CODA_KEY_RIGHT:
			if (m_State == CharState::MOVE_RIGHT)
				m_State = CharState::STILL;
			break;
		case CODA_KEY_UP:
			if (m_State == CharState::MOVE_UP)
				m_State = CharState::STILL;
			break;
		case CODA_KEY_DOWN:
			if (m_State == CharState::MOVE_DOWN)
				m_State = CharState::STILL;
			break;
		}
	}

};

START_CODA_GAME(GEFall22)