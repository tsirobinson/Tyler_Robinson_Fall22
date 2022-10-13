#include "pch.h"

#include "CodaWindow.h"

namespace Coda
{
  CodaWindow* CodaWindow::GetWindow(){
    return mInstance;
  }
  void CodaWindow::Create(int width, int height, const std::string& windowName){
    mImplementation->Create(width, height, windowName);
  }
  
  void CodaWindow::SwapBuffers(){
    mImplementation->SwapBuffers();
  }
}
