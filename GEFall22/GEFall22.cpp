#include "Coda.h"

class GameDisplay
{
public:
	void DrawDisplay(int hp) {

		//Render player HP
		int xCoord{ 980 };
		int idx = hp - 1;
		while (idx >= 0) {

			xCoord -= m_Hearts[idx].GetWidth();
			Coda::Renderer::Draw(m_Hearts[idx], xCoord, 720, 1);
			idx--;
		}

		//Render Player score
		int xCoord2{ 20 };
		for (int i = 0; i < m_Points.size(); i++) {
			xCoord2 += m_Points[i].GetWidth();
			Coda::Renderer::Draw(m_Points[i], xCoord2, 720, 1);
		}
	}

	void LoseHeart() {
		m_Hearts.pop_back();
	}

	void AddPoint() {
		m_Points.push_back(Coda::Picture{ "Assets/Textures/score.png" });
	}

private:
	std::vector<Coda::Picture> m_Hearts{
		Coda::Picture("Assets/Textures/heart.png"),
		Coda::Picture("Assets/Textures/heart.png"),
		Coda::Picture("Assets/Textures/heart.png")
	};

	std::vector<Coda::Picture> m_Points{};
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

		for (int i = 0; i < m_Stars.size(); i++) {
			m_Stars[i].SetCoord(m_StarPos[i][0], m_StarPos[i][1], 1);
		}


	}

	void OnUpdate() override {

		Coda::Renderer::Draw(m_Background, 0, 0, 1);

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

		//Render enemies and check for collision
		for (int i = 0; i < m_Enemies.size(); i++) {
			m_Enemies[i].Draw();
			if (m_Character.OverlapsWith(m_Enemies[i])) {
				m_Character.ChangeHP(-1);
				m_Character.SetCoord(200, 100, 1);
				m_GameDisplay.LoseHeart();
				CODA_LOG("Collided with enemy.");
			}
		}

		//Render stars and check for collision
		for (int i = 0; i < m_Stars.size(); i++) {
			m_Stars[i].Draw();
			if (m_Character.OverlapsWith(m_Stars[i])) {
				m_Stars.erase(m_Stars.begin() + i);
				m_Score++;
				m_GameDisplay.AddPoint();
				CODA_LOG("Collected star.");
			}
		}

		m_GameDisplay.DrawDisplay(m_Character.GetHP());

	}

	virtual bool CheckGameOver() override {
		if (m_Character.GetHP() < 1 || m_Score >= 3) {
			CODA_LOG("GAME OVER.");
			Coda::Renderer::Draw(m_GameOver, 300, 200, 1);
			return true;
		}

		return false;
		
	}

private:
	Coda::Picture m_Background{ "Assets/Textures/background.png" };
	Coda::Picture m_GameOver{ "Assets/Textures/game_over.png" };
	Coda::Unit m_Character{ "Assets/textures/character.png", 3 };

	std::vector<Coda::Unit> m_Stars{
		Coda::Unit{"Assets/Textures/star.png", 1},
		Coda::Unit{"Assets/Textures/star.png", 1},
		Coda::Unit{"Assets/Textures/star.png", 1}
	};

	std::vector<Coda::Unit> m_Enemies{
		Coda::Unit{"Assets/Textures/enemy.png", 1},
		Coda::Unit{"Assets/Textures/enemy.png", 1},
		Coda::Unit{"Assets/Textures/enemy.png", 1},
		Coda::Unit{"Assets/Textures/enemy.png", 1}
	};

	std::vector<std::vector<int>> m_StarPos{
		{400, 300},
		{750, 500},
		{0, 600}
	};

	std::vector<std::vector<int>> m_EnemyPos{
		{30, 300},
		{650, 300},
		{700, 20},
		{400, 450}
	};

	int m_Speed{ 30 };

	int m_Score{ 0 };
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
		case CODA_KEY_ESCAPE:
			Coda::CodaWindow::CloseWindow();
		}
	}
};



START_CODA_GAME(Fall22Game)