#pragma once
namespace Game {
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	
	int rr[2][24];

	public ref class PublicData {
	public:
		static property PictureBox^ MainThis;
		static property Label^ Info;
		static property bool isWhiteMove;
		static property bool isWhiteWin;
	};
}