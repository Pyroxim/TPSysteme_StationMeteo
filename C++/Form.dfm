object Form1: TForm1
  Left = 0
  Top = 0
  Caption = 'Form1'
  ClientHeight = 243
  ClientWidth = 527
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object Label1: TLabel
    Left = 112
    Top = 24
    Width = 35
    Height = 25
    Caption = '     '
    Color = clRed
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -21
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentColor = False
    ParentFont = False
    Transparent = False
  end
  object Label2: TLabel
    Left = 24
    Top = 72
    Width = 92
    Height = 13
    Caption = 'Temp'#233'rature ('#176'C) :'
    WordWrap = True
  end
  object Label3: TLabel
    Left = 168
    Top = 72
    Width = 104
    Height = 13
    Caption = 'Taux d'#39'humidit'#233' (%) :'
  end
  object Label4: TLabel
    Left = 318
    Top = 72
    Width = 29
    Height = 13
    Caption = 'Pluie :'
  end
  object LabelTemp: TLabel
    Left = 24
    Top = 91
    Width = 3
    Height = 13
  end
  object LabelHumid: TLabel
    Left = 168
    Top = 91
    Width = 3
    Height = 13
  end
  object LabelPluie: TLabel
    Left = 318
    Top = 91
    Width = 3
    Height = 13
  end
  object LabelBDD: TLabel
    Left = 168
    Top = 24
    Width = 4
    Height = 16
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
  end
  object Button1: TButton
    Left = 24
    Top = 24
    Width = 75
    Height = 25
    Caption = 'Affichage'
    TabOrder = 0
    OnClick = Button1Click
  end
  object Timer1: TTimer
    Enabled = False
    OnTimer = Timer1Timer
    Left = 496
  end
end
