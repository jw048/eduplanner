object Form4: TForm4
  Left = 0
  Top = 0
  Caption = 'Form4'
  ClientHeight = 441
  ClientWidth = 624
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -12
  Font.Name = 'Segoe UI'
  Font.Style = []
  TextHeight = 15
  object Label1: TLabel
    Left = 288
    Top = 224
    Width = 3
    Height = 15
  end
  object usernameed: TEdit
    Left = 240
    Top = 152
    Width = 121
    Height = 23
    TabOrder = 0
  end
  object passcodeed: TEdit
    Left = 240
    Top = 181
    Width = 121
    Height = 23
    TabOrder = 1
  end
  object loginbtn: TButton
    Left = 264
    Top = 256
    Width = 75
    Height = 25
    Caption = 'LOGIN'
    TabOrder = 2
    OnClick = loginbtnClick
  end
  object Button1: TButton
    Left = 496
    Top = 80
    Width = 75
    Height = 25
    Caption = 'Button1'
    TabOrder = 3
    OnClick = Button1Click
  end
  object RESTClient1: TRESTClient
    BaseURL = 'http://44.215.161.145/login/emmapark0202/EmmaPark0202%21'
    Params = <>
    SynchronizedEvents = False
    Left = 88
    Top = 48
  end
  object RESTRequest1: TRESTRequest
    AssignedValues = [rvConnectTimeout, rvReadTimeout]
    Client = RESTClient1
    Params = <>
    Response = RESTResponse1
    SynchronizedEvents = False
    Left = 96
    Top = 56
  end
  object RESTResponse1: TRESTResponse
    Left = 104
    Top = 64
  end
  object RESTResponseDataSetAdapter1: TRESTResponseDataSetAdapter
    Dataset = FDMemTable1
    FieldDefs = <>
    Response = RESTResponse1
    TypesMode = JSONOnly
    Left = 112
    Top = 72
  end
  object FDMemTable1: TFDMemTable
    FetchOptions.AssignedValues = [evMode]
    FetchOptions.Mode = fmAll
    ResourceOptions.AssignedValues = [rvSilentMode]
    ResourceOptions.SilentMode = True
    UpdateOptions.AssignedValues = [uvUpdateChngFields, uvUpdateMode, uvLockMode, uvLockPoint, uvLockWait, uvRefreshMode, uvFetchGeneratorsPoint, uvCheckRequired, uvCheckReadOnly, uvCheckUpdatable]
    UpdateOptions.LockWait = True
    UpdateOptions.FetchGeneratorsPoint = gpNone
    UpdateOptions.CheckRequired = False
    Left = 120
    Top = 80
  end
  object RESTClient2: TRESTClient
    BaseURL = 'http://44.215.161.145/test/emmapark0202'
    Params = <>
    SynchronizedEvents = False
    Left = 96
    Top = 208
  end
  object RESTRequest2: TRESTRequest
    AssignedValues = [rvConnectTimeout, rvReadTimeout]
    Client = RESTClient2
    Params = <>
    Response = RESTResponse2
    SynchronizedEvents = False
    Left = 104
    Top = 216
  end
  object RESTResponse2: TRESTResponse
    Left = 112
    Top = 224
  end
  object RESTResponseDataSetAdapter2: TRESTResponseDataSetAdapter
    Dataset = FDMemTable2
    FieldDefs = <>
    Response = RESTResponse2
    TypesMode = JSONOnly
    Left = 120
    Top = 232
  end
  object FDMemTable2: TFDMemTable
    FetchOptions.AssignedValues = [evMode]
    FetchOptions.Mode = fmAll
    ResourceOptions.AssignedValues = [rvSilentMode]
    ResourceOptions.SilentMode = True
    UpdateOptions.AssignedValues = [uvUpdateChngFields, uvUpdateMode, uvLockMode, uvLockPoint, uvLockWait, uvRefreshMode, uvFetchGeneratorsPoint, uvCheckRequired, uvCheckReadOnly, uvCheckUpdatable]
    UpdateOptions.LockWait = True
    UpdateOptions.FetchGeneratorsPoint = gpNone
    UpdateOptions.CheckRequired = False
    Left = 128
    Top = 240
  end
end
