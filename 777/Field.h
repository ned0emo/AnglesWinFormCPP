#pragma once
namespace MyField {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	int f[8][8] = { { 0, 0, 0, 0, 2, 2, 2, 2 },
					{ 0, 0, 0, 0, 2, 2, 2, 2 },
					{ 0, 0, 0, 0, 2, 2, 2, 2 },
					{ 0, 0, 0, 0, 0, 0, 0, 0 },
					{ 0, 0, 0, 0, 0, 0, 0, 0 },
					{ 1, 1, 1, 1, 0, 0, 0, 0 },
					{ 1, 1, 1, 1, 0, 0, 0, 0 },
					{ 1, 1, 1, 1, 0, 0, 0, 0 } };

	public ref class SelectWhite : System::Windows::Forms::PictureBox {
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  label1;

	public:
		SelectWhite() {
			InitButton();
		}

		void InitButton() {
			this->BackColor = System::Drawing::Color::Transparent;
			this->ImageLocation = L"White.png";
			this->SizeMode = PictureBoxSizeMode::StretchImage;
			SelectWhite::Click += gcnew System::EventHandler(this, &SelectWhite::OnClick);
		}
	private: System::Void OnClick(System::Object^  sender, System::EventArgs^  e) {
		
	}
	private: System::Void InitializeComponent() {
		this->label2 = (gcnew System::Windows::Forms::Label());
		(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this))->BeginInit();
		this->SuspendLayout();
		// 
		// label2
		// 
		this->label2->AutoSize = true;
		this->label2->ForeColor = System::Drawing::Color::Red;
		this->label2->Location = System::Drawing::Point(0, 0);
		this->label2->Name = L"label2";
		this->label2->Size = System::Drawing::Size(100, 23);
		this->label2->TabIndex = 0;
		this->label2->Text = L"label2";
		this->label2->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
		this->label2->Click += gcnew System::EventHandler(this, &SelectWhite::label2_Click);
		(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this))->EndInit();
		this->ResumeLayout(false);

	}
	
	private: System::Void label2_Click(System::Object^  sender, System::EventArgs^  e) {
	}
	};

	public ref class SelectBlack : System::Windows::Forms::PictureBox {
	public:
		SelectBlack() {
			InitButton();
		}

		void InitButton() {
			this->BackColor = System::Drawing::Color::Transparent;
			this->ImageLocation = L"White.png";
			this->SizeMode = PictureBoxSizeMode::StretchImage;
			SelectBlack::Click += gcnew System::EventHandler(this, &SelectBlack::OnClick);
		}
	private: System::Void OnClick(System::Object^  sender, System::EventArgs^  e) {

	}
	};

	public ref class Field : System::Windows::Forms::Form{
	public:
		bool isPVE;
		int W, H;
		Field(bool a, int w, int h) {
			isPVE = a;
			W = w;
			H = h;
			InitializeComponent();
		}
	protected:
		~Field(){
			if (components)			{
				delete components;
			}
		}
	private: 
		System::Windows::Forms::PictureBox^  FieldPic;
		System::Windows::Forms::PictureBox^  MainMenu;
		System::Windows::Forms::Button^  HideButton;
		SelectWhite ^w1, ^w2, ^w3, ^w4, ^w5, ^w6, ^w7, ^w8, ^w9, ^w10, ^w11, ^w12,
			^b1, ^b2, ^b3, ^b4, ^b5, ^b6, ^b7, ^b8, ^b9, ^b10, ^b11, ^b12;
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		void InitializeComponent(void){

		}
		#pragma endregion
	private: System::Void HideButton_Click(System::Object^  sender, System::EventArgs^  e) {
		Application::Exit();
		this->WindowState = System::Windows::Forms::FormWindowState::Minimized;
	}
	private: System::Void FieldPic_MouseClick(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
		
	}
	};
}
