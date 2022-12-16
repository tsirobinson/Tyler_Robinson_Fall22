#include "Coda.h"

class GameDisplay
{
public:
	void DrawDisplay(int hp) {
		int xCoord{ 980 };

		int idx = hp - 1;
		while (idx >= 0) {

			xCoord -= m_Hearts[idx].GetWidth();
			Coda::Renderer::Draw(m_Hearts[idx], xCoord, 720, 1);
			idx--;
		}
	}

	void LoseHeart() {
		m_Hearts.pop_back();
	}

private:
	std::vector<Coda::Picture> m_Hearts{
		Coda::Picture("Assets/Textures/heart.png"),
		Coda::Picture("Assets/Textures/heart.png"),
		Coda::Picture("Assets/Textures/heart.png")
	};
};

class Fall22Game : public Coda::CodaApp {
public:
	Fall22Game() {
		Coda::CodaWindow::GetWindow()->SetKeyPressedCallback(
			[this](const Coda::KeyPressedEvent& event) {OnKeyPress(event); });
		Coda::CodaWindow::GetWindow()->SetKeyReleasedCallback(
			[this](const Coda::KeyReleasedEvent& event) {OnKeyRelease(event); });

		m_Character.SetCoord(200, 100, 1);

		for (int i = 0; i < m_Enemies.size(); i++) {
			m_Enemies[i].SetCoord(m_EnemyPos[i][0], m_EnemyPos[i][1], 1);
		}


	}

	void OnUpdate() override {
		Coda::Renderer::Draw(m_Background, 0, 0, 1);

		if (m_Character.GetHP() < 1) {
			CODA_LOG("GAME OVER.");
			Coda::Renderer::Draw(m_GameOver, 300, 200, 1);
			//Coda::CodaWindow::CloseWindow();
		}
		else {

			switch (m_State) {
			case CharState::MOVE_LEFT:
				m_Character.ChangeX(-10);
				break;
			case CharState::MOVE_RIGHT:
				m_Character.ChangeX(10);
				break;
			case CharState::MOVE_UP:
				m_Character.ChangeY(10);
				break;
			case CharState::MOVE_DOWN:
				m_Character.ChangeY(-10);
				break;
			}

			m_Character.Draw();

			for (int i = 0; i < m_Enemies.size(); i++) {
				m_Enemies[i].Draw();
				if (m_Character.OverlapsWith(m_Enemies[i])) {
					m_Character.ChangeHP(-1);
					m_Character.SetCoord(200, 100, 1);
					m_GameDisplay.LoseHeart();
					CODA_LOG("Collided with enemy.");
				}
			}

			m_GameDisplay.DrawDisplay(m_Character.GetHP());
		}

	}

private:
	Coda::Picture m_Background{ "Assets/Textures/background.png" };
	Coda::Picture m_GameOver{ "Assets/Textures/game_over.png" };
	Coda::Unit m_Character{ "Assets/textures/character.png", 3 };
	std::vector<Coda::Unit> m_Enemies{
		Coda::Unit{"Assets/Textures/enemy.png", 1},
		Coda::Unit{"Assets/Textures/enemy.png", 1},
		Coda::Unit{"Assets/Textures/enemy.png", 1},
		Coda::Unit{"Assets/Textures/enemy.png", 1}
	};

	std::vector<std::vector<int>> m_EnemyPos{
		{30, 300},
		{300, 600},
		{700, 20},
		{400, 450}
	};

	int m_Speed{ 30 };

	int m_Score{ 30 };
	int m_Frames{ 0 };

	GameDisplay m_GameDisplay;

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
			if (m_State == CharState::MOVE_LEFT)
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
		case CODA_KEY_ESCAPE:
			Coda::CodaWindow::CloseWindow();
		}
	}
};



START_CODA_GAME(Fall22Game)