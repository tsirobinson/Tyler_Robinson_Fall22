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
        		-0.5f, -0.5f, // left  
         		0.5f, -0.5f, // right 
         		0.0f,  0.5f  // top   
    		}; 
		
		unsigned int VBO, VAO;
    		glGenVertexArrays(1, &VAO);
    		glGenBuffers(1, &VBO);
		
		glBindVertexArray(VAO);
		
		glBindBuffer(GL_ARRAY_BUFFER, VBO);
   		glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    		glEnableVertexAttribArray(0);
		
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
