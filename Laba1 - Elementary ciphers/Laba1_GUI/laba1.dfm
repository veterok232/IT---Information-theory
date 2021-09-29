object frmMain: TfrmMain
  Left = 0
  Top = 0
  BorderIcons = [biSystemMenu]
  BorderStyle = bsSingle
  Caption = 'Laba 1'
  ClientHeight = 600
  ClientWidth = 1000
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -13
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  Position = poDesktopCenter
  PixelsPerInch = 120
  TextHeight = 16
  object lbl1: TLabel
    Left = 8
    Top = 10
    Width = 202
    Height = 24
    Caption = #1048#1089#1093#1086#1076#1085#1086#1077' '#1089#1086#1086#1073#1097#1077#1085#1080#1077':'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -20
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
  end
  object lbl2: TLabel
    Left = 8
    Top = 314
    Width = 206
    Height = 24
    Caption = #1042#1099#1093#1086#1076#1085#1086#1077' '#1089#1086#1086#1073#1097#1077#1085#1080#1077':'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -20
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
  end
  object Label1: TLabel
    Left = 520
    Top = 10
    Width = 56
    Height = 24
    Caption = #1050#1083#1102#1095':'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -20
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
  end
  object sourceMessageField: TMemo
    Left = 8
    Top = 40
    Width = 489
    Height = 257
    Font.Charset = RUSSIAN_CHARSET
    Font.Color = clWindowText
    Font.Height = -18
    Font.Name = 'Times New Roman'
    Font.Style = []
    ParentFont = False
    TabOrder = 0
  end
  object resultMessageField: TMemo
    Left = 8
    Top = 344
    Width = 489
    Height = 248
    Font.Charset = RUSSIAN_CHARSET
    Font.Color = clWindowText
    Font.Height = -18
    Font.Name = 'Times New Roman'
    Font.Style = []
    ParentFont = False
    TabOrder = 1
  end
  object keyField: TMemo
    Left = 520
    Top = 40
    Width = 472
    Height = 257
    Font.Charset = RUSSIAN_CHARSET
    Font.Color = clWindowText
    Font.Height = -18
    Font.Name = 'Times New Roman'
    Font.Style = []
    ParentFont = False
    TabOrder = 2
  end
  object cboxSelectMethod: TComboBox
    Left = 520
    Top = 344
    Width = 472
    Height = 32
    Style = csDropDownList
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -20
    Font.Name = 'Tahoma'
    Font.Style = []
    ItemIndex = 0
    ParentFont = False
    TabOrder = 3
    Text = 'Rail-fence method'
    Items.Strings = (
      'Rail-fence method'
      'Column method'
      'Trailing-grille method'
      'Vigener'#39's method')
  end
  object btnStart: TButton
    Left = 520
    Top = 543
    Width = 472
    Height = 49
    Caption = #1057#1090#1072#1088#1090'!'
    Font.Charset = RUSSIAN_CHARSET
    Font.Color = clWindowText
    Font.Height = -20
    Font.Name = 'Verdana'
    Font.Style = [fsBold, fsItalic]
    ParentFont = False
    TabOrder = 4
    OnClick = btnStartClick
  end
  object rbtnEncrypt: TRadioButton
    Left = 520
    Top = 493
    Width = 225
    Height = 33
    Caption = #1064#1080#1092#1088#1086#1074#1072#1090#1100
    Checked = True
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -20
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
    TabOrder = 5
    TabStop = True
  end
  object rbtnDecrypt: TRadioButton
    Left = 767
    Top = 493
    Width = 225
    Height = 33
    Caption = #1044#1077#1096#1080#1092#1088#1086#1074#1072#1090#1100
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -20
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
    TabOrder = 6
  end
end
