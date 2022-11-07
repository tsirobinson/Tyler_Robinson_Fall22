#include "pch.h"

#include "CodaApp.h"
#include "CodaUtil.h"
#include "CodaWindow.h"


namespace Coda {
	void CodaApp::OnUpdate() {

	}

	void CodaApp::Run() {
		CODA_LOG("Coda running...");

		CodaWindow::Init();
		CodaWindow::GetWindow()->Create(600, 400, "TestWindow");
		//CodaWindow gameWindow;
		//gameWindow.Create(600, 400, "Test window");
		
		float vertices[] = {
			//positions  //texture coords
        		-0.5f, -0.5f, 0.0f, 0.0f, // bottom-left  
         		0.5f, -0.5f, 1.0f, 0.0f, // bottom-right
         		-0.5f,  0.5f, 0.0f, 1.0f, // top-left 
			0.5f, 0.5f, 1.0f, 1.0f//top-right
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
		glBufferData(GL_ELEMENT_BUFFER, sizeof(indices), GL_STATIC_DRAW);
		
		//Describe attribute pointer 0 (positions)
    		glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 4 * sizeof(float), (void*)0);
    		glEnableVertexAttribArray(0);
		
		//Describe attribute pointer 1 (texture coordinates)
		glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 4 * sizeof(float), (void*)(2*sizeof(float)));
    		glEnableVertexAttribArray(1);
		
		/////////// SHADERS /////////
		
		const char *vertexShaderSource = "#version 330 core\n"
		    "layout (location = 0) in vec3 aPos;\n"
		    "void main()\n"
		    "{\n"
		    "   gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
		    "}\0";
		const char *fragmentShaderSource = "#version 330 core\n"
		    "out vec4 FragColor;\n"
		    "void main()\n"
		    "{\n"
		    "   FragColor = vec4(1.0f, 0.5f, 0.2f, 1.0f);\n"
		    "}\n\0";
		
		unsigned int vertexShader = glCreateShader(GL_VERTEX_SHADER);
		glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
		glCompileShader(vertexShader);
		    
		int success;
		char infoLog[512];
		glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
		if (!success){
			glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
			std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << std::endl;
		}
		
		unsigned int fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
		glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
		glCompileShader(fragmentShader);
		glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);
    		if (!success) {
       			glGetShaderInfoLog(fragmentShader, 512, NULL, infoLog);
        		std::cout << "ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n" << infoLog << std::endl;
    		}	
		
		unsigned int shaderProgram = glCreateProgram();
	    	glAttachShader(shaderProgram, vertexShader);
	    	glAttachShader(shaderProgram, fragmentShader);
	    	glLinkProgram(shaderProgram);
		
		glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);
	    	if (!success) {
			glGetProgramInfoLog(shaderProgram, 512, NULL, infoLog);
			std::cout << "ERROR::SHADER::PROGRAM::LINKING_FAILED\n" << infoLog << std::endl;
	    	}
	    	glDeleteShader(vertexShader);
	    	glDeleteShader(fragmentShader);
		
		////////// TEXTURES //////////

		while (true) {
			processInput(window);
			
			glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        		glClear(GL_COLOR_BUFFER_BIT);
			
			glUseProgram(shaderProgram);
        		glBindVertexArray(VAO);
        		glDrawArrays(GL_TRIANGLES, 0, 3);
			
			CodaWindow::GetWindow()->SwapBuffers();
			glfwPollEvents();
			//gameWindow.SwapBuffers();

			OnUpdate();
		}

	
	}
}
