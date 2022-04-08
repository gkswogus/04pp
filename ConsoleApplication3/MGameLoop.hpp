#pragma once
#include <chrono>
#include <thread>
#include "MConsolUtil.hpp"

using namespace std;

namespace MuSeoun_Engine
{
	class MGameLoop
	{
	private:
		bool _isGameRunning;
		MConsoleRenderer cRenderer;
		int i = 0;
		double time = 0;

	public:
		MGameLoop() 
		{ _isGameRunning = false; }
		~MGameLoop() 
		{
		}

		void Run()
		{
			_isGameRunning = true;
			Initialize();

			while (_isGameRunning)
			{
				Input();
				Update();
				Render();
			}
			Release();
		}
		void Stop()
		{
			_isGameRunning = false;
		}

	private:
		void Initialize()
		{

		}
		void Release()
		{
		}

		void Input()
		{
			/*	if (GetAsyncKeyState(VK_SPACE) & 0x8000 || GetAsyncKeyState(VK_SPACE) & 0x8001)
				{

				}
				else
				{

				}*/

		}
		void Update()
		{

		}
		 
		void Render()
		{
			chrono::system_clock::time_point startRenderTimePoint = chrono::system_clock::now();

			
			cRenderer.MoveCursor(10, 20);
			cRenderer.Clear();

			chrono::duration<double> renderDuration = chrono::system_clock::now() - startRenderTimePoint;
			
			
			
		    i++;
			
			time = time + renderDuration.count();

			if (time >= 1.0f)  
			{
				string fps = "FPS(seconds) : " + to_string(i);
				cRenderer.DrawString(fps);
				time = 0;
				i = 0;
			}
			
			

			//5string fps = "FPS(milliseconds) : " + to_string(renderDuration.count());
			
			

			
			//cRenderer.DrawString(fps);
		}
		
		
	


		////cout << "Rendering speed : " << renderDuration.count() << "sec" << endl;

		//int remainingFrameTime = 100 - (int)(renderDuration.count() * 1000.0);
		//if (remainingFrameTime > 0)
		//	this_thread::sleep_for(chrono::milliseconds(remainingFrameTime));




	};






}
