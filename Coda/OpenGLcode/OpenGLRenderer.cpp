#include "pch.h"
#include "OpenGLRenderer.h"
#include "CodaWindow.h"
#include "glad/glad.h"

namespace Coda {
	OpenGLRenderer::OpenGLRenderer() {
		glEnable(GL_BLEND);
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	}

	void OpenGLRenderer::Draw(Picture& picture, int x, int y, int z, Shader& shader) {
		float vertices[] = {
			//positions  //texture coords
			(float)x, (float)y, (float)z, 0.0f, 0.0f, // bottom-left  
			(float)(x + picture.GetWidth()), (float)y, (float)z, 1.0f, 0.0f, // bottom-right
			(float)x, (float)(y + picture.GetHeight()), (float)z, 0.0f, 1.0f, // top-left 
			(float)(x + picture.GetWidth()), (float)(y + picture.GetHeight()), (float)z, 1.0f, 1.0f//top-right
		};

		unsigned int indices[] = {
			0, 1, 2, //first triangle (bottom left, bottom right, top left)
			1, 2, 3 //second triangle (bottom right, top left, top right)
		};
		
		unsigned int VBO, VAO, EBO;
		glGenVertexArrays(1, &VAO);
		glGenBuffers(1, &VBO);
		glGenBuffers(1, &EBO);
		
		glBindVertexArray(VAO);
		
		glBindBuffer(GL_ARRAY_BUFFER, VBO);
		glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
		
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

		//Describe attribute pointer 0 (positions)
		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)0);
		glEnableVertexAttribArray(0);

		//Describe attribute pointer 1 (texture coordinates)
		glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)(3 * sizeof(float)));
		glEnableVertexAttribArray(1);

		picture.Activate();
		shader.Activate();

		int width{ CodaWindow::GetWindow()->GetWidth() };
		int height{ CodaWindow::GetWindow()->GetHeight() };
		shader.ProvideFloatValues("screenSize", { (float)width, (float)height});

		glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);

	}

	void OpenGLRenderer::Clear() {
		glClearColor(0.0f, 0.5f, 0.0f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);
	}
}