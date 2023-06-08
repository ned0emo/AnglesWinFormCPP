#pragma once
#include "Control.h"
#include "Data.h"

namespace Game {
	public ref class MyForm : public System::Windows::Forms::Form{
	public:
		MyForm(void){
			InitializeComponent();

			PublicData::Info = this->Info;
			PublicData::MainThis = this->Field;
		}

	protected:
		~MyForm(){
			if (components)
				delete components;
		}

	private: 
		System::Windows::Forms::PictureBox ^MainMenu, ^Field, ^Back;
		System::Windows::Forms::Button ^SaveButton, ^LoadButton, ^ExitButton, ^NewGameButton, ^HideButton;
		System::Windows::Forms::Label^ Congrat;
		System::Windows::Forms::Label^ Info;
		CheckersControl ^w1, ^w2, ^w3, ^w4, ^w5, ^w6, ^w7, ^w8, ^w9, ^w10, ^w11, ^w12;
		CheckersControl ^b1, ^b2, ^b3, ^b4, ^b5, ^b6, ^b7, ^b8, ^b9, ^b10, ^b11, ^b12;
		System::ComponentModel::Container ^components;

		int prevMouseX;
		int prevMouseY;

#pragma region Windows Form Designer generated code
		void InitializeComponent(void){
			this->Field = (gcnew System::Windows::Forms::PictureBox());
			this->MainMenu = (gcnew System::Windows::Forms::PictureBox());
			this->Info = (gcnew System::Windows::Forms::Label());
			this->SaveButton = (gcnew System::Windows::Forms::Button());
			this->LoadButton = (gcnew System::Windows::Forms::Button());
			this->ExitButton = (gcnew System::Windows::Forms::Button());
			this->NewGameButton = (gcnew System::Windows::Forms::Button());
			this->HideButton = (gcnew System::Windows::Forms::Button());
			this->Back = (gcnew System::Windows::Forms::PictureBox());
			this->Congrat = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Field))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->MainMenu))->BeginInit();
			this->MainMenu->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Back))->BeginInit();
			this->Back->SuspendLayout();
			this->SuspendLayout();
			// 
			// Field
			// 
			this->Field->ImageLocation = L"FieldHD.jpg";
			this->Field->Location = System::Drawing::Point(24, 24);
			this->Field->Name = L"Field";
			this->Field->Size = System::Drawing::Size(672, 672);
			this->Field->TabIndex = 1;
			this->Field->TabStop = false;
			this->Field->VisibleChanged += gcnew System::EventHandler(this, &MyForm::Tmp);
			// 
			// MainMenu
			// 
			this->MainMenu->Controls->Add(this->Info);
			this->MainMenu->ImageLocation = L"menu.png";
			this->MainMenu->Location = System::Drawing::Point(0, 0);
			this->MainMenu->Name = L"MainMenu";
			this->MainMenu->Size = System::Drawing::Size(1280, 720);
			this->MainMenu->TabIndex = 0;
			this->MainMenu->TabStop = false;
			this->MainMenu->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::MainMenu_MouseDown);
			this->MainMenu->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::MainMenu_MouseUp);
			// 
			// Info
			// 
			this->Info->BackColor = System::Drawing::Color::Transparent;
			this->Info->Font = (gcnew System::Drawing::Font(L"Verdana", 24, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->Info->ForeColor = System::Drawing::Color::OrangeRed;
			this->Info->Location = System::Drawing::Point(725, 500);
			this->Info->Name = L"Info";
			this->Info->Size = System::Drawing::Size(530, 200);
			this->Info->TabIndex = 0;
			this->Info->Text = L" ";
			this->Info->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// SaveButton
			// 
			this->SaveButton->BackColor = System::Drawing::Color::OrangeRed;
			this->SaveButton->Cursor = System::Windows::Forms::Cursors::Default;
			this->SaveButton->FlatAppearance->BorderSize = 0;
			this->SaveButton->FlatAppearance->MouseDownBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(128)), static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->SaveButton->FlatAppearance->MouseOverBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(96)), static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->SaveButton->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->SaveButton->Font = (gcnew System::Drawing::Font(L"Verdana", 24, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->SaveButton->Location = System::Drawing::Point(725, 335);
			this->SaveButton->Name = L"SaveButton";
			this->SaveButton->Size = System::Drawing::Size(530, 70);
			this->SaveButton->TabIndex = 1;
			this->SaveButton->Text = L"Сохранить";
			this->SaveButton->UseVisualStyleBackColor = false;
			this->SaveButton->Click += gcnew System::EventHandler(this, &MyForm::SaveButton_Click);
			// 
			// LoadButton
			// 
			this->LoadButton->BackColor = System::Drawing::Color::OrangeRed;
			this->LoadButton->FlatAppearance->BorderSize = 0;
			this->LoadButton->FlatAppearance->MouseDownBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(128)), static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->LoadButton->FlatAppearance->MouseOverBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(96)), static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->LoadButton->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->LoadButton->Font = (gcnew System::Drawing::Font(L"Verdana", 24, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->LoadButton->Location = System::Drawing::Point(725, 411);
			this->LoadButton->Name = L"LoadButton";
			this->LoadButton->Size = System::Drawing::Size(530, 70);
			this->LoadButton->TabIndex = 1;
			this->LoadButton->Text = L"Продолжить";
			this->LoadButton->UseVisualStyleBackColor = false;
			this->LoadButton->Click += gcnew System::EventHandler(this, &MyForm::LoadButton_Click);
			// 
			// ExitButton
			// 
			this->ExitButton->BackColor = System::Drawing::Color::OrangeRed;
			this->ExitButton->FlatAppearance->BorderSize = 0;
			this->ExitButton->FlatAppearance->MouseDownBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(128)), static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->ExitButton->FlatAppearance->MouseOverBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(96)), static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->ExitButton->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->ExitButton->Font = (gcnew System::Drawing::Font(L"Verdana", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->ExitButton->Location = System::Drawing::Point(1220, 25);
			this->ExitButton->Name = L"ExitButton";
			this->ExitButton->Size = System::Drawing::Size(35, 35);
			this->ExitButton->TabIndex = 1;
			this->ExitButton->Text = L"X";
			this->ExitButton->UseVisualStyleBackColor = false;
			this->ExitButton->Click += gcnew System::EventHandler(this, &MyForm::ExitButton_Click);
			// 
			// NewGameButton
			// 
			this->NewGameButton->BackColor = System::Drawing::Color::OrangeRed;
			this->NewGameButton->FlatAppearance->BorderSize = 0;
			this->NewGameButton->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->NewGameButton->Font = (gcnew System::Drawing::Font(L"Verdana", 24, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->NewGameButton->Location = System::Drawing::Point(725, 196);
			this->NewGameButton->Name = L"NewGameButton";
			this->NewGameButton->Size = System::Drawing::Size(530, 70);
			this->NewGameButton->TabIndex = 6;
			this->NewGameButton->Text = L"Новая игра";
			this->NewGameButton->UseVisualStyleBackColor = false;
			this->NewGameButton->Click += gcnew System::EventHandler(this, &MyForm::NewGameButton_Click);
			// 
			// HideButton
			// 
			this->HideButton->BackColor = System::Drawing::Color::OrangeRed;
			this->HideButton->FlatAppearance->BorderSize = 0;
			this->HideButton->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->HideButton->Font = (gcnew System::Drawing::Font(L"Verdana", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->HideButton->Location = System::Drawing::Point(1175, 25);
			this->HideButton->Name = L"HideButton";
			this->HideButton->Size = System::Drawing::Size(35, 35);
			this->HideButton->TabIndex = 5;
			this->HideButton->Text = L"___";
			this->HideButton->TextAlign = System::Drawing::ContentAlignment::BottomCenter;
			this->HideButton->UseVisualStyleBackColor = false;
			this->HideButton->Click += gcnew System::EventHandler(this, &MyForm::HideButton_Click_1);
			// 
			// Back
			// 
			this->Back->BackColor = System::Drawing::Color::DimGray;
			this->Back->Controls->Add(this->Congrat);
			this->Back->Location = System::Drawing::Point(20, 20);
			this->Back->Name = L"Back";
			this->Back->Size = System::Drawing::Size(680, 680);
			this->Back->TabIndex = 4;
			this->Back->TabStop = false;
			// 
			// Congrat
			// 
			this->Congrat->BackColor = System::Drawing::Color::Transparent;
			this->Congrat->Font = (gcnew System::Drawing::Font(L"Verdana", 48, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->Congrat->Location = System::Drawing::Point(0, 0);
			this->Congrat->Name = L"Congrat";
			this->Congrat->Size = System::Drawing::Size(680, 680);
			this->Congrat->TabIndex = 0;
			this->Congrat->Text = L" ";
			this->Congrat->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1280, 720);
			this->Controls->Add(this->Field);
			this->Controls->Add(this->Back);
			this->Controls->Add(this->HideButton);
			this->Controls->Add(this->SaveButton);
			this->Controls->Add(this->LoadButton);
			this->Controls->Add(this->ExitButton);
			this->Controls->Add(this->NewGameButton);
			this->Controls->Add(this->MainMenu);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Name = L"MyForm";
			this->TopMost = true;
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Field))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->MainMenu))->EndInit();
			this->MainMenu->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Back))->EndInit();
			this->Back->ResumeLayout(false);
			this->ResumeLayout(false);

		}
		#pragma endregion
		private: System::Void Tmp(System::Object^  sender, System::EventArgs^  e) {
			this->Field->VisibleChanged -= gcnew System::EventHandler(this, &MyForm::Tmp);
			this->Field->VisibleChanged += gcnew System::EventHandler(this, &MyForm::Field_VisibleChanged);
		}
		private: System::Void Field_VisibleChanged(System::Object^  sender, System::EventArgs^  e) {
			if(PublicData::isWhiteWin)
				this->Congrat->Text = L"Победил игрок за белые шашки!";
			else
				this->Congrat->Text = L"Победил игрок за черные шашки!";
			this->Field->VisibleChanged -= gcnew System::EventHandler(this, &MyForm::Field_VisibleChanged);
			this->Field->VisibleChanged += gcnew System::EventHandler(this, &MyForm::Tmp);
		}
		private: System::Void ExitButton_Click(System::Object^  sender, System::EventArgs^  e) {
			Application::Exit();
		}
		private: System::Void HideButton_Click(System::Object^  sender, System::EventArgs^  e) {
			this->WindowState = System::Windows::Forms::FormWindowState::Minimized;
		}
		private: System::Void SaveButton_Click(System::Object^  sender, System::EventArgs^  e) {
			IO::StreamWriter^ sw = gcnew IO::StreamWriter("777.txt");
			for(int i = 0;i<2;i++)
				for (int j = 0; j < 24; j++) {
					sw->WriteLine(rr[i][j]);
				}
			sw->WriteLine((int)PublicData::isWhiteMove);
			sw->Close();
		}
		private: System::Void LoadButton_Click(System::Object^  sender, System::EventArgs^  e) {
			this->Field->Visible = true;
			this->Field->Controls->Clear();
			System::IO::StreamReader^ sr = gcnew IO::StreamReader("777.txt");
			String^ num;
			for (int i = 0; i < 2; i++) {
				for (int j = 0; j < 24; j++) {
				num = sr->ReadLine();
				rr[i][j] = Int32::Parse(num);
				}
			}
			num = sr->ReadLine();
			PublicData::isWhiteMove = Int32::Parse(num);
			sr->Close();
			if (PublicData::isWhiteMove) {
				Info->Text = L"Ход белых";
			}
			else
				Info->Text = L"Ход черных";
			AddChecker();
		}
		private: System::Void NewGameButton_Click(System::Object^  sender, System::EventArgs^  e) {
			Field->Visible = true;
			Field->Controls->Clear();
			System::IO::StreamReader^ sr = gcnew IO::StreamReader("NewGame.txt");
			String^ num;
			for (int i = 0; i < 2; i++) {
				for (int j = 0; j < 24; j++) {
					num = sr->ReadLine();
					rr[i][j] = Int32::Parse(num);
				}
			}
			num = sr->ReadLine();
			PublicData::isWhiteMove = Int32::Parse(num);
			sr->Close();
			Info->Text = L"Ход белых";
			AddChecker();
		}
		private: void AddChecker() {
			this->w1 = (gcnew CheckersControl(0, rr[0][0], rr[1][0])); this->w2 = gcnew CheckersControl(0, rr[0][1], rr[1][1]);
			this->w3 = (gcnew CheckersControl(0, rr[0][2], rr[1][2])); this->w4 = (gcnew CheckersControl(0, rr[0][3], rr[1][3]));
			this->w5 = (gcnew CheckersControl(0, rr[0][4], rr[1][4])); this->w6 = (gcnew CheckersControl(0, rr[0][5], rr[1][5]));
			this->w7 = (gcnew CheckersControl(0, rr[0][6], rr[1][6])); this->w8 = (gcnew CheckersControl(0, rr[0][7], rr[1][7]));
			this->w9 = (gcnew CheckersControl(0, rr[0][8], rr[1][8])); this->w10 = (gcnew CheckersControl(0, rr[0][9], rr[1][9]));
			this->w11 = (gcnew CheckersControl(0, rr[0][10], rr[1][10])); this->w12 = (gcnew CheckersControl(0, rr[0][11], rr[1][11]));
			this->b1 = (gcnew CheckersControl(1, rr[0][12], rr[1][12])); this->b2 = (gcnew CheckersControl(1, rr[0][13], rr[1][13]));
			this->b3 = (gcnew CheckersControl(1, rr[0][14], rr[1][14])); this->b4 = (gcnew CheckersControl(1, rr[0][15], rr[1][15]));
			this->b5 = (gcnew CheckersControl(1, rr[0][16], rr[1][16])); this->b6 = (gcnew CheckersControl(1, rr[0][17], rr[1][17]));
			this->b7 = (gcnew CheckersControl(1, rr[0][18], rr[1][18])); this->b8 = (gcnew CheckersControl(1, rr[0][19], rr[1][19]));
			this->b9 = (gcnew CheckersControl(1, rr[0][20], rr[1][20])); this->b10 = (gcnew CheckersControl(1, rr[0][21], rr[1][21]));
			this->b11 = (gcnew CheckersControl(1, rr[0][22], rr[1][22])); this->b12 = (gcnew CheckersControl(1, rr[0][23], rr[1][23]));

			this->Field->Controls->Add(this->w1); this->Field->Controls->Add(this->w2);
			this->Field->Controls->Add(this->w3); this->Field->Controls->Add(this->w4);
			this->Field->Controls->Add(this->w5); this->Field->Controls->Add(this->w6);
			this->Field->Controls->Add(this->w7); this->Field->Controls->Add(this->w8);
			this->Field->Controls->Add(this->w9); this->Field->Controls->Add(this->w10);
			this->Field->Controls->Add(this->w11); this->Field->Controls->Add(this->w12);
			this->Field->Controls->Add(this->b1); this->Field->Controls->Add(this->b2);
			this->Field->Controls->Add(this->b3); this->Field->Controls->Add(this->b4);
			this->Field->Controls->Add(this->b5); this->Field->Controls->Add(this->b6);
			this->Field->Controls->Add(this->b7); this->Field->Controls->Add(this->b8);
			this->Field->Controls->Add(this->b9); this->Field->Controls->Add(this->b10);
			this->Field->Controls->Add(this->b11); this->Field->Controls->Add(this->b12);
		}
private: System::Void MainMenu_MouseDown(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
	prevMouseX = e->X;
	prevMouseY = e->Y;
	this->MainMenu->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::MainMenu_MouseMove);
}
private: System::Void MainMenu_MouseUp(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
	this->MainMenu->MouseMove -= gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::MainMenu_MouseMove);
}
private: System::Void MainMenu_MouseMove(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
	this->Location = System::Drawing::Point(Control::MousePosition.X - prevMouseX, Control::MousePosition.Y - prevMouseY);
}
private: System::Void HideButton_Click_1(System::Object^ sender, System::EventArgs^ e) {
	this->WindowState = FormWindowState::Minimized;
}
};
}