object Form1: TForm1
  Left = 0
  Top = 0
  Caption = 'Form1'
  ClientHeight = 211
  ClientWidth = 418
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object Button1: TButton
    Left = 8
    Top = 8
    Width = 145
    Height = 25
    Caption = 'Server Start'
    TabOrder = 0
    OnClick = Button1Click
  end
  object Button2: TButton
    Left = 8
    Top = 39
    Width = 145
    Height = 25
    Caption = 'Client Send Broadcast'
    TabOrder = 1
    OnClick = Button2Click
  end
  object Memo1: TMemo
    Left = 159
    Top = 8
    Width = 251
    Height = 195
    Lines.Strings = (
      'Memo1')
    TabOrder = 2
  end
  object IdUDPServer1: TIdUDPServer
    Bindings = <>
    DefaultPort = 0
    OnUDPRead = IdUDPServer1UDPRead
    Left = 72
    Top = 80
  end
  object IdUDPClient1: TIdUDPClient
    Port = 0
    Left = 72
    Top = 136
  end
end
