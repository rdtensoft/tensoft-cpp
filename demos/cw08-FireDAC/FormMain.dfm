object Form1: TForm1
  Left = 0
  Top = 0
  ActiveControl = Button1
  Caption = 'Form1'
  ClientHeight = 391
  ClientWidth = 678
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
    Width = 198
    Height = 385
    Align = alLeft
    Caption = 'GroupBox1'
    TabOrder = 0
    object GroupBox2: TGroupBox
      AlignWithMargins = True
      Left = 5
      Top = 25
      Width = 188
      Height = 153
      Margins.Top = 10
      Align = alTop
      Caption = 'FDConnection'
      TabOrder = 0
      object Button1: TButton
        AlignWithMargins = True
        Left = 5
        Top = 18
        Width = 178
        Height = 25
        Align = alTop
        Caption = 'Button1'
        TabOrder = 0
        OnClick = Button1Click
      end
      object Button2: TButton
        AlignWithMargins = True
        Left = 5
        Top = 49
        Width = 178
        Height = 25
        Align = alTop
        Caption = 'Button2'
        TabOrder = 1
        OnClick = Button2Click
      end
      object Button3: TButton
        AlignWithMargins = True
        Left = 5
        Top = 80
        Width = 178
        Height = 25
        Align = alTop
        Caption = 'Button3'
        TabOrder = 2
        OnClick = Button3Click
      end
      object Button4: TButton
        AlignWithMargins = True
        Left = 5
        Top = 111
        Width = 178
        Height = 25
        Align = alTop
        Caption = 'Button4'
        TabOrder = 3
        OnClick = Button4Click
      end
    end
    object GroupBox3: TGroupBox
      AlignWithMargins = True
      Left = 5
      Top = 184
      Width = 188
      Height = 137
      Align = alTop
      Caption = 'FDQuery'
      TabOrder = 1
      object Button5: TButton
        AlignWithMargins = True
        Left = 5
        Top = 18
        Width = 178
        Height = 25
        Align = alTop
        Caption = 'Button5'
        TabOrder = 0
        OnClick = Button5Click
      end
      object Button6: TButton
        AlignWithMargins = True
        Left = 5
        Top = 49
        Width = 178
        Height = 25
        Align = alTop
        Caption = 'Button6'
        TabOrder = 1
        OnClick = Button6Click
        ExplicitLeft = 56
        ExplicitTop = 56
        ExplicitWidth = 75
      end
    end
  end
  object PageControl1: TPageControl
    AlignWithMargins = True
    Left = 207
    Top = 3
    Width = 468
    Height = 385
    Align = alClient
    TabOrder = 1
  end
  object FDConnection1: TFDConnection
    Params.Strings = (
      'ConnectionDef=FB_Demo')
    Left = 248
    Top = 32
  end
  object FDQuery1: TFDQuery
    Connection = FDConnection1
    SQL.Strings = (
      'SELECT * FROM FDQA_PRODUCTS')
    Left = 248
    Top = 96
  end
end
