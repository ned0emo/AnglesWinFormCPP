#include "Data.h"

namespace Game {
	public ref class CheckerMove : System::Windows::Forms::PictureBox {
	public:
		CheckerMove() {
			InitMove();
		}

		void InitMove() {
			BackColor = Color::Aqua;
			Size = System::Drawing::Size(80, 80);
			TabIndex = 3;
			TabStop = false;
			Location = Point(700, 700);
		}
	};


	public ref class CheckersControl : PictureBox {
	public:
		int flag = 1, I, X, Y;
		bool isBlack;
		CheckersControl() {
			InitButton();
		}
		CheckersControl(bool _isBlack, int x, int y) {
			X = x;
			Y = y;
			isBlack = _isBlack;
			InitButton();
		}

	private: 
		PictureBox ^N, ^W, ^E, ^S;

		void InitButton() {
			N = gcnew CheckerMove();
			S = gcnew CheckerMove();
			E = gcnew CheckerMove();
			W = gcnew CheckerMove();

			N->Click += gcnew EventHandler(this, &CheckersControl::NMoveClick);
			S->Click += gcnew EventHandler(this, &CheckersControl::SMoveClick);
			E->Click += gcnew EventHandler(this, &CheckersControl::EMoveClick);
			W->Click += gcnew EventHandler(this, &CheckersControl::WMoveClick);

			Location = System::Drawing::Point(X, Y);
			Size = Drawing::Size(80, 80);
			BackColor = Color::Transparent;
			if (isBlack)
				ImageLocation = L"Black.png";
			else
				ImageLocation = L"White.png";
			this->SizeMode = PictureBoxSizeMode::StretchImage;
			this->Click += gcnew EventHandler(this, &CheckersControl::OnClick);
		}
	
		System::Void NMoveClick(System::Object^  sender, System::EventArgs^  e) {
			Location = N->Location;
			rr[0][I] = N->Location.X;
			rr[1][I] = N->Location.Y;
			if (!N->TabIndex) {
				UpdateAll(1);
			}
			else {
				UpdateAll(0);
				ClickOn(1);
			}
		}
		System::Void SMoveClick(System::Object^  sender, System::EventArgs^  e) {
			Location = S->Location;
			rr[0][I] = S->Location.X;
			rr[1][I] = S->Location.Y;
			if (!S->TabIndex) {
				UpdateAll(1);
			}
			else {
				UpdateAll(0);
				ClickOn(1);
			}
		}
		System::Void WMoveClick(System::Object^  sender, System::EventArgs^  e) {
			Location = W->Location;
			rr[0][I] = W->Location.X;
			rr[1][I] = W->Location.Y;
			if (!W->TabIndex) {
				UpdateAll(1);
			}
			else {
				UpdateAll(0);
				ClickOn(1);
			}
		}
		System::Void EMoveClick(System::Object^  sender, System::EventArgs^  e) {
			Location = E->Location;
			rr[0][I] = E->Location.X;
			rr[1][I] = E->Location.Y;
			if (!E->TabIndex) {
				UpdateAll(1);
			}
			else {
				UpdateAll(0);
				ClickOn(1);
			}
		}
	
		int CheckWin() {
			int WhiteComplete = 0, BlackComplete = 0;
			for (int i = 0; i < 12; i++) {
				if (rr[0][i] < 338 || rr[1][i] > 170) {
					break;
				}
				WhiteComplete++;
			}
			for (int i = 12; i < 24; i++) {
				if (rr[0][i] > 254 || rr[1][i] < 422) {
					break;
				}
				BlackComplete++;
			}
			if (WhiteComplete == 12) return 2;
			else if (BlackComplete == 12) return 1;
			return 0;
		}
	
		void UpdateAll(bool isEndMove) {
			if (isEndMove) {
				if (PublicData::isWhiteMove) {
					PublicData::isWhiteMove = 0;
					PublicData::Info->Text = L"Ход черных";
				}
				else {
					PublicData::isWhiteMove = 1;
					PublicData::Info->Text = L"Ход белых";
				}
				PublicData::MainThis->TabIndex = 1;
				Click -= gcnew EventHandler(this, &CheckersControl::StopMove);
				Click -= gcnew EventHandler(this, &CheckersControl::OffClick);
				Click += gcnew EventHandler(this, &CheckersControl::OnClick);
				BackColor = Color::Transparent;
				Update();
				if (CheckWin() == 2) {
					PublicData::isWhiteWin = 1;
					PublicData::MainThis->Visible = false;
				}
				else if (CheckWin()) {
					PublicData::isWhiteWin = 0;
					PublicData::MainThis->Visible = false;
				}
			}
			this->N->TabIndex = 1;
			this->S->TabIndex = 1;
			this->W->TabIndex = 1;
			this->E->TabIndex = 1;
			this->N->Location = System::Drawing::Point(700, 700);
			this->S->Location = System::Drawing::Point(700, 700);
			this->W->Location = System::Drawing::Point(700, 700);
			this->E->Location = System::Drawing::Point(700, 700);
			this->N->Update();
			this->S->Update();
			this->W->Update();
			this->E->Update();
		}
	private: void ClickOn(bool isSecMove) {
		if (!isSecMove) {
			this->Click -= gcnew System::EventHandler(this, &CheckersControl::OnClick);
			this->Click += gcnew System::EventHandler(this, &CheckersControl::OffClick);
			PublicData::MainThis->TabIndex = 0;
		}
		else {
			this->Click -= gcnew System::EventHandler(this, &CheckersControl::StopMove);
			this->Click -= gcnew System::EventHandler(this, &CheckersControl::OffClick);
			this->Click += gcnew System::EventHandler(this, &CheckersControl::StopMove);
		}
		this->BackColor = System::Drawing::Color::OrangeRed;
		int x = this->Location.X;
		int y = this->Location.Y;
		int n = 0, s = 0, w = 0, ee = 0, c = 0;
		for (int i = 0; i < 24; i++) {
			if (rr[0][i] == x && rr[1][i] == y) {
				I = i;
			}
			if (rr[0][i] == x - 84 && rr[1][i] == y) {
				n++;
				if (x < 168)
					n++;
				else
					for (int j = 0; j < 24; j++) {
						if (rr[0][j] == x - 168 && rr[1][j] == y) {
							n++;
						}
					}
			}
			if (rr[0][i] == x + 84 && rr[1][i] == y) {
				s++;
				if (x > 504)
					s++;
				else
					for (int j = 0; j < 24; j++) {
						if (rr[0][j] == x + 168 && rr[1][j] == y) {
							s++;
						}
					}
			}
			if (rr[0][i] == x && rr[1][i] == y - 84) {
				w++;
				if (y < 168)
					w++;
				else
					for (int j = 0; j < 24; j++) {
						if (rr[0][j] == x && rr[1][j] == y - 168) {
							w++;
						}
					}
			}
			if (rr[0][i] == x && rr[1][i] == y + 84) {
				ee++;
				if (y > 504)
					ee++;
				else
					for (int j = 0; j < 24; j++) {
						if (rr[0][j] == x && rr[1][j] == y + 168) {
							ee++;
						}
					}
			}
		}
		if (!n && x > 84 && !isSecMove) {
			this->N->TabIndex = n;
			this->N->Location = System::Drawing::Point(x - 84, y);
			this->N->Update(); c++;
		}
		else
			if (n == 1) {
				this->N->Location = System::Drawing::Point(x - 168, y);
				this->N->Update(); c++;
			}
		if (!s && x < 588 && !isSecMove) {
			this->S->TabIndex = s;
			this->S->Location = System::Drawing::Point(x + 84, y);
			this->S->Update(); c++;
		}
		else
			if (s == 1) {
				this->S->Location = System::Drawing::Point(x + 168, y);
				this->S->Update(); c++;
			}
		if (!w && y > 84 && !isSecMove) {
			this->W->TabIndex = w;
			this->W->Location = System::Drawing::Point(x, y - 84);
			this->W->Update(); c++;
		}
		else
			if (w == 1) {
				this->W->Location = System::Drawing::Point(x, y - 168);
				this->W->Update(); c++;
			}
		if (!ee && y < 588 && !isSecMove) {
			this->E->TabIndex = ee;
			this->E->Location = System::Drawing::Point(x, y + 84);
			this->E->Update(); c++;
		}
		else
			if (ee == 1) {
				this->E->Location = System::Drawing::Point(x, y + 168);
				this->E->Update(); c++;
			}
		/*if (!c&&isSecMove) {
			if (Data::isWhiteMove) Data::isWhiteMove = 0;
			else Data::isWhiteMove = 1;
			UpdateAll(1);
		}*/
	}
	private: System::Void OffClick(System::Object^  sender, System::EventArgs^  e) {
		PublicData::MainThis->TabIndex = 1;
		this->Click -= gcnew System::EventHandler(this, &CheckersControl::OffClick);
		this->Click += gcnew System::EventHandler(this, &CheckersControl::OnClick);
		this->BackColor = Color::Transparent;
		UpdateAll(0);
	}
	private: System::Void OnClick(System::Object^  sender, System::EventArgs^  e) {
		if (PublicData::MainThis->TabIndex) {
			if (flag) {
				flag--;
				PublicData::MainThis->Controls->Add(this->N);
				PublicData::MainThis->Controls->Add(this->S);
				PublicData::MainThis->Controls->Add(this->E);
				PublicData::MainThis->Controls->Add(this->W);
			}
			if (PublicData::isWhiteMove && !isBlack) {
				ClickOn(0);
			}
			else
				if (!PublicData::isWhiteMove && isBlack) {
					ClickOn(0);
				}
		}
	}
	private: System::Void StopMove(System::Object^  sender, System::EventArgs^  e) {
		UpdateAll(1);
	}
	};
}