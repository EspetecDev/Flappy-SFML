#pragma once

namespace Fuet {

	class State {
	
	public:

		virtual void Init() = 0;
		
		virtual void HandleInput() = 0;
		virtual void Update(float dt) = 0;
		// dt : time difference, allows to draw
		// independently from the frame rate
		virtual void Draw(float dt) = 0;

		virtual void Pause(){ }
		virtual void Resume() { }
	};
}