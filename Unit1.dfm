object Form1: TForm1
  Left = 0
  Top = 0
  Caption = 'Form1'
  ClientHeight = 614
  ClientWidth = 728
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object GroupBox1: TGroupBox
    Left = 24
    Top = 40
    Width = 225
    Height = 89
    Caption = 'Way'
    TabOrder = 0
    object RadioButton1: TRadioButton
      Left = 56
      Top = 24
      Width = 113
      Height = 17
      Caption = '4 Way'
      TabOrder = 0
    end
    object RadioButton2: TRadioButton
      Left = 56
      Top = 47
      Width = 113
      Height = 17
      Caption = '8 Way'
      TabOrder = 1
    end
  end
  object Button3: TButton
    Left = 24
    Top = 289
    Width = 225
    Height = 25
    Caption = 'Load Maze'
    TabOrder = 1
    OnClick = Button3Click
  end
  object GroupBox2: TGroupBox
    Left = 24
    Top = 352
    Width = 225
    Height = 161
    Caption = 'Auto'
    TabOrder = 2
    object Button4: TButton
      Left = 24
      Top = 72
      Width = 177
      Height = 57
      Caption = 'Find a tour'
      TabOrder = 0
      OnClick = Button4Click
    end
  end
  object GroupBox3: TGroupBox
    Left = 24
    Top = 153
    Width = 225
    Height = 105
    Caption = 'Gride SIze'
    TabOrder = 3
    object Label3: TLabel
      Left = 24
      Top = 32
      Width = 41
      Height = 13
      Caption = 'Grid Size'
    end
    object Button1: TButton
      Left = 24
      Top = 69
      Width = 177
      Height = 25
      Caption = 'Refresh Maze'
      TabOrder = 0
      OnClick = Button1Click
    end
    object Edit3: TEdit
      Left = 80
      Top = 26
      Width = 121
      Height = 21
      TabOrder = 1
      Text = 'size'
    end
  end
  object PageControl1: TPageControl
    Left = 255
    Top = 40
    Width = 465
    Height = 529
    ActivePage = TabSheet1
    TabOrder = 4
    object TabSheet1: TTabSheet
      Caption = 'Memo'
      object Memo1: TMemo
        Left = -4
        Top = -2
        Width = 461
        Height = 488
        Lines.Strings = (
          'Memo1')
        TabOrder = 0
      end
    end
    object TabSheet5: TTabSheet
      Caption = 'String Grid'
      ImageIndex = 4
      object StringGrid1: TStringGrid
        Left = -4
        Top = 0
        Width = 461
        Height = 401
        TabOrder = 0
        OnDrawCell = StringGrid1DrawCell
      end
    end
  end
  object OpenDialog1: TOpenDialog
    Left = 64
    Top = 528
  end
end
