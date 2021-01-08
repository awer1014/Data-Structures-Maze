//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
int m,n; //m == height n == width
int maze1[100][100];
int maze2[100][100];


struct position{
	int x,y;
	int dir;
};


int top,maxsize,way;
position *Stack;
int move[2][8] = {
	{-1,-1,0,1,1, 1, 0,-1},
	{ 0, 1,1,1,0,-1,-1,-1}
};


position pop(){
	if (top != -1){
		return Stack[top--];
	}
}


void print() {
	position out;
	int t = top;
	while (top != -1) {
		out = pop();
		maze2[out.x][out.y] = 4;
		Form1->Memo1->Lines->Add("(k,l,dir) = " + IntToStr(out.x) + "," + IntToStr(out.y) + "," +IntToStr(out.dir));
	}
	top = t;
}


void push(position data) {
	if (top != maxsize-1){
		Stack[++top] = data;
	}
}


void path(){
	Stack = new position[maxsize];
	position step;
	int i,j,k,l,d;
	top = -1;
	step.x = 1;
	step.y = 1;
	step.dir =2;
	push(step);
	maze2[1][1] = 3;
	while (top != -1) {
		step = pop();
		i = step.x;
		j = step.y;
		d = step.dir;
		while (d<8) {
			k = i + move[1][d];
			l = j + move[0][d];
			if ((k == m-2)&&(l == n-2)){
				maze2[k][l] = 3;
				step.x = i;
				step.y = j;
				step.dir = d+1;
				if(way == 4){
					step.dir = d+2;
				}
				push(step);
				step.x = k;
				step.y = l;
				step.dir = d+1;
				if (way == 4){
					step.dir = d+2;
				}
				push(step);
				print();

				delete[] Stack;
				return;
			}
			else if(maze1[k][l] == 0 && maze2 [k][l]==0){
				maze2[k][l] = 3;
				step.x = i;
				step.y = j;
				step.dir = d+1;
				if(way == 4){
					step.dir = d+2;
				}
				push(step);
				i = k;
				j = l;
				d = 0;
			}
			else{
				d++;
				if (way = 4){
					d++;
				}
			}
		}
	}
	Form1->Memo1->Lines->Add("This maze have no exit");
}


//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button3Click(TObject *Sender)
{
	FILE *fp;
	AnsiString out;
	int i,j;

	if (OpenDialog1->Execute()){

		out = OpenDialog1->FileName;
		fp = fopen(out.c_str(), "r+");
		fscanf(fp, "%d %d", &m, &n);

		Form1->Memo1->Lines->Add("-------- m="+IntToStr(m)+" n="+IntToStr(n)+" --------");

		for (i=0; i<m; i++){
			for (j=0; j<n; j++){
				fscanf(fp, "%d", &maze1[i][j]);
			}
		}
		for (i=0; i<m; i++){
			out = "";
			for (j=0; j<n; j++){
				out += "  "+IntToStr(maze1[i][j]);
			}
			Form1->Memo1->Lines->Add(out);
		}

		StringGrid1->RowCount = m;
		StringGrid1->ColCount = n;

		for (i=0; i<m; i++){
		   for (j=0; j<n; j++){
				 StringGrid1->Cells[j][i] = maze1[i][j];
		   }
		 }
		fclose(fp);
	}
	else  Memo1->Lines->Add("Nothing happens.");
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button4Click(TObject *Sender)
{
	int i,j;
	for (i=0;i<m;i++){
		for(j=0;j<n;j++){
			maze2[i][j] = maze1[i][j];
		}
	}
	if (RadioButton1->Checked){
		way =4;
	}
	else{
		way = 8;
	}
	maxsize = m*n;
	path();
	for (i=0; i<m; i++) {
		for(j=0; j<n; j++){
			StringGrid1->Cells[j][i] = maze2[i][j];
		}
	}
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender)
{
	int grid_size = StrToInt(Edit3->Text);
	int i;
	for (i=0; i<m; i++){
		StringGrid1->RowHeights[i] = grid_size;
	}
	for(i=0; i<n; i++){
		StringGrid1->ColWidths[i] = grid_size;
	}
}
//---------------------------------------------------------------------------
void __fastcall TForm1::StringGrid1DrawCell(TObject *Sender, int ACol, int ARow, TRect &Rect,
          TGridDrawState State)
{

	String text = StringGrid1->Cells[ACol][ARow];
	if (text == "0") StringGrid1->Canvas->Brush->Color = TColor RGB(250, 245, 135);
	else if (text == "1") StringGrid1->Canvas->Brush->Color = TColor (RGB(176, 36, 132));
	else if (text == "2") StringGrid1->Canvas->Brush->Color = TColor (RGB(180, 180, 80));
	else if (text == "3") StringGrid1->Canvas->Brush->Color = TColor (RGB(65, 105, 225));
	else if (text == "4") StringGrid1->Canvas->Brush->Color = TColor (RGB(8, 46, 84));
	else StringGrid1->Canvas->Brush->Color = TColor RGB(50, 50, 50);
	StringGrid1->Canvas->FillRect(Rect);
}
//---------------------------------------------------------------------------
