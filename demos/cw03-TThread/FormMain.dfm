object Form1: TForm1
  Left = 0
  Top = 0
  Caption = 'Form1'
  ClientHeight = 353
  ClientWidth = 715
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
    AlignWithMargins = True
    Left = 3
    Top = 3
    Width = 166
    Height = 347
    Align = alLeft
    Caption = 'GroupBox1'
    TabOrder = 0
    object Button1: TButton
      AlignWithMargins = True
      Left = 5
      Top = 18
      Width = 156
      Height = 25
      Align = alTop
      Caption = 'Button1'
      TabOrder = 0
      OnClick = Button1Click
    end
  end
  object GroupBox2: TGroupBox
    AlignWithMargins = True
    Left = 175
    Top = 3
    Width = 537
    Height = 347
    Align = alClient
    Caption = 'GroupBox2'
    TabOrder = 1
  end
end
