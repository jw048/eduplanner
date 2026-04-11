object Form7: TForm7
  Left = 0
  Top = 0
  Caption = 'Form7'
  ClientHeight = 451
  ClientWidth = 636
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -12
  Font.Name = 'Segoe UI'
  Font.Style = []
  TextHeight = 15
  object warningconst: TLabel
    Left = 96
    Top = 8
    Width = 112
    Height = 28
    Caption = 'WARNINGS: '
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -20
    Font.Name = 'Segoe UI'
    Font.Style = []
    ParentFont = False
  end
  object dangerconst: TLabel
    Left = 288
    Top = 8
    Width = 93
    Height = 28
    Caption = 'DANGERS:'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -20
    Font.Name = 'Segoe UI'
    Font.Style = []
    ParentFont = False
  end
  object warning: TLabel
    Left = 208
    Top = 8
    Width = 11
    Height = 28
    Caption = '0'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -20
    Font.Name = 'Segoe UI'
    Font.Style = []
    ParentFont = False
  end
  object danger: TLabel
    Left = 387
    Top = 8
    Width = 11
    Height = 28
    Caption = '0'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -20
    Font.Name = 'Segoe UI'
    Font.Style = []
    ParentFont = False
  end
  object gradesmemo: TMemo
    Left = 24
    Top = 100
    Width = 592
    Height = 333
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'Segoe UI'
    Font.Style = []
    Lines.Strings = (
      '')
    ParentFont = False
    TabOrder = 0
  end
  object startbtn: TButton
    Left = 24
    Top = 45
    Width = 409
    Height = 41
    Caption = 'Press to print grades'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -20
    Font.Name = 'Segoe UI'
    Font.Style = []
    ParentFont = False
    TabOrder = 1
    OnClick = startbtnClick
  end
  object mtbtn: TButton
    Left = 456
    Top = 45
    Width = 160
    Height = 41
    Caption = 'Book Meeting'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -20
    Font.Name = 'Segoe UI'
    Font.Style = []
    ParentFont = False
    TabOrder = 2
    OnClick = mtbtnClick
  end
  object homebtn: TButton
    Left = 469
    Top = 8
    Width = 147
    Height = 25
    Caption = 'HOME'
    TabOrder = 3
    OnClick = homebtnClick
  end
  object RESTClient1: TRESTClient
    BaseURL = 'http://127.0.0.1:8000/tot_gpa/Emma/English'
    Params = <>
    SynchronizedEvents = False
    Left = 64
    Top = 304
  end
  object RESTRequest1: TRESTRequest
    AssignedValues = [rvConnectTimeout, rvReadTimeout]
    Client = RESTClient1
    Params = <>
    Response = RESTResponse1
    SynchronizedEvents = False
    Left = 72
    Top = 312
  end
  object RESTResponse1: TRESTResponse
    Left = 80
    Top = 320
  end
  object RESTResponseDataSetAdapter1: TRESTResponseDataSetAdapter
    Dataset = FDMemTable1
    FieldDefs = <>
    Response = RESTResponse1
    TypesMode = JSONOnly
    Left = 88
    Top = 328
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
    Left = 96
    Top = 336
  end
  object RESTClient2: TRESTClient
    BaseURL = 'http://127.0.0.1:8000/courses/Emma'
    Params = <>
    SynchronizedEvents = False
    Left = 312
    Top = 120
  end
  object RESTRequest2: TRESTRequest
    AssignedValues = [rvConnectTimeout, rvReadTimeout]
    Client = RESTClient2
    Params = <>
    Response = RESTResponse2
    SynchronizedEvents = False
    Left = 328
    Top = 136
  end
  object RESTResponse2: TRESTResponse
    Left = 336
    Top = 144
  end
  object RESTResponseDataSetAdapter2: TRESTResponseDataSetAdapter
    Dataset = FDMemTable2
    FieldDefs = <>
    Response = RESTResponse2
    TypesMode = JSONOnly
    Left = 344
    Top = 152
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
    Left = 352
    Top = 160
  end
  object RESTClient3: TRESTClient
    BaseURL = 'http://127.0.0.1:8000/warningemail/Bob/F/Literature'
    Params = <>
    SynchronizedEvents = False
    Left = 184
    Top = 120
  end
  object RESTRequest3: TRESTRequest
    AssignedValues = [rvConnectTimeout, rvReadTimeout]
    Client = RESTClient3
    Params = <>
    Response = RESTResponse3
    SynchronizedEvents = False
    Left = 200
    Top = 136
  end
  object RESTResponse3: TRESTResponse
    Left = 208
    Top = 144
  end
  object RESTResponseDataSetAdapter3: TRESTResponseDataSetAdapter
    Dataset = FDMemTable3
    FieldDefs = <>
    Response = RESTResponse3
    TypesMode = JSONOnly
    Left = 216
    Top = 152
  end
  object FDMemTable3: TFDMemTable
    FetchOptions.AssignedValues = [evMode]
    FetchOptions.Mode = fmAll
    ResourceOptions.AssignedValues = [rvSilentMode]
    ResourceOptions.SilentMode = True
    UpdateOptions.AssignedValues = [uvUpdateChngFields, uvUpdateMode, uvLockMode, uvLockPoint, uvLockWait, uvRefreshMode, uvFetchGeneratorsPoint, uvCheckRequired, uvCheckReadOnly, uvCheckUpdatable]
    UpdateOptions.LockWait = True
    UpdateOptions.FetchGeneratorsPoint = gpNone
    UpdateOptions.CheckRequired = False
    Left = 224
    Top = 160
  end
  object RESTClient4: TRESTClient
    BaseURL = 'http://127.0.0.1:8000/dangeremail/Bob/F/Science'
    Params = <>
    SynchronizedEvents = False
    Left = 48
    Top = 112
  end
  object RESTRequest4: TRESTRequest
    AssignedValues = [rvConnectTimeout, rvReadTimeout]
    Client = RESTClient4
    Params = <>
    Response = RESTResponse4
    SynchronizedEvents = False
    Left = 64
    Top = 128
  end
  object RESTResponse4: TRESTResponse
    Left = 72
    Top = 136
  end
  object RESTResponseDataSetAdapter4: TRESTResponseDataSetAdapter
    Dataset = FDMemTable4
    FieldDefs = <>
    Response = RESTResponse4
    TypesMode = JSONOnly
    Left = 80
    Top = 144
  end
  object FDMemTable4: TFDMemTable
    FetchOptions.AssignedValues = [evMode]
    FetchOptions.Mode = fmAll
    ResourceOptions.AssignedValues = [rvSilentMode]
    ResourceOptions.SilentMode = True
    UpdateOptions.AssignedValues = [uvUpdateChngFields, uvUpdateMode, uvLockMode, uvLockPoint, uvLockWait, uvRefreshMode, uvFetchGeneratorsPoint, uvCheckRequired, uvCheckReadOnly, uvCheckUpdatable]
    UpdateOptions.LockWait = True
    UpdateOptions.FetchGeneratorsPoint = gpNone
    UpdateOptions.CheckRequired = False
    Left = 88
    Top = 152
  end
end
