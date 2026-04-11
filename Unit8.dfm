object Form8: TForm8
  Left = 0
  Top = 0
  Caption = 'Form8'
  ClientHeight = 567
  ClientWidth = 778
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -12
  Font.Name = 'Segoe UI'
  Font.Style = []
  OnShow = FormShow
  TextHeight = 15
  object schecalendar: TMonthCalendar
    Left = 8
    Top = 56
    Width = 295
    Height = 250
    Date = 46073.000000000000000000
    TabOrder = 0
  end
  object mtnglist: TListBox
    Left = 320
    Top = 56
    Width = 445
    Height = 250
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -20
    Font.Name = 'Segoe UI'
    Font.Style = []
    ItemHeight = 28
    ParentFont = False
    TabOrder = 1
  end
  object schedulebtn: TButton
    Left = 320
    Top = 312
    Width = 445
    Height = 33
    Caption = 'SELECT'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -20
    Font.Name = 'Segoe UI'
    Font.Style = []
    ParentFont = False
    TabOrder = 2
    OnClick = schedulebtnClick
  end
  object scheduledmm: TMemo
    Left = 8
    Top = 367
    Width = 757
    Height = 189
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -20
    Font.Name = 'Segoe UI'
    Font.Style = []
    Lines.Strings = (
      '(No meetings scheduled)')
    ParentFont = False
    TabOrder = 3
  end
  object returnbtn: TButton
    Left = 660
    Top = 8
    Width = 105
    Height = 28
    Caption = 'RETURN'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -20
    Font.Name = 'Segoe UI'
    Font.Style = []
    ParentFont = False
    TabOrder = 4
    OnClick = returnbtnClick
  end
  object dateselectbtn: TButton
    Left = 8
    Top = 312
    Width = 296
    Height = 33
    Caption = 'CHECK'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -20
    Font.Name = 'Segoe UI'
    Font.Style = []
    ParentFont = False
    TabOrder = 5
    OnClick = dateselectbtnClick
  end
  object RESTClient1: TRESTClient
    BaseURL = 'http://127.0.0.1:8000/stmeetcheck/Bob'
    Params = <>
    SynchronizedEvents = False
    Left = 456
    Top = 88
  end
  object RESTRequest1: TRESTRequest
    AssignedValues = [rvConnectTimeout, rvReadTimeout]
    Client = RESTClient1
    Params = <>
    Response = RESTResponse1
    SynchronizedEvents = False
    Left = 472
    Top = 104
  end
  object RESTResponse1: TRESTResponse
    Left = 480
    Top = 112
  end
  object RESTResponseDataSetAdapter1: TRESTResponseDataSetAdapter
    Dataset = FDMemTable1
    FieldDefs = <>
    Response = RESTResponse1
    TypesMode = JSONOnly
    Left = 488
    Top = 120
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
    Left = 496
    Top = 128
  end
  object RESTClient2: TRESTClient
    BaseURL = 'http://127.0.0.1:8000/mtngprt/2026-02-06'
    Params = <>
    SynchronizedEvents = False
    Left = 456
    Top = 192
  end
  object RESTRequest2: TRESTRequest
    AssignedValues = [rvConnectTimeout, rvReadTimeout]
    Client = RESTClient2
    Params = <>
    Response = RESTResponse2
    SynchronizedEvents = False
    Left = 472
    Top = 208
  end
  object RESTResponse2: TRESTResponse
    Left = 480
    Top = 216
  end
  object RESTResponseDataSetAdapter2: TRESTResponseDataSetAdapter
    Dataset = FDMemTable2
    FieldDefs = <>
    Response = RESTResponse2
    TypesMode = JSONOnly
    Left = 488
    Top = 224
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
    Left = 496
    Top = 232
  end
  object RESTClient3: TRESTClient
    BaseURL = 
      'http://127.0.0.1:8000/stmeetapp/Ms.B/2026-02-06/8%3A15-8%3A50/Em' +
      'ma'
    Params = <>
    SynchronizedEvents = False
    Left = 400
    Top = 448
  end
  object RESTRequest3: TRESTRequest
    AssignedValues = [rvConnectTimeout, rvReadTimeout]
    Client = RESTClient3
    Params = <>
    Response = RESTResponse3
    SynchronizedEvents = False
    Left = 416
    Top = 464
  end
  object RESTResponse3: TRESTResponse
    Left = 424
    Top = 472
  end
  object RESTClient4: TRESTClient
    BaseURL = 
      'http://127.0.0.1:8000/confirmemail/Emma/2026-02-06/8%3A15-8%3A50' +
      '/ad'
    Params = <>
    SynchronizedEvents = False
    Left = 640
    Top = 136
  end
  object RESTRequest4: TRESTRequest
    AssignedValues = [rvConnectTimeout, rvReadTimeout]
    Client = RESTClient4
    Params = <>
    Response = RESTResponse4
    SynchronizedEvents = False
    Left = 648
    Top = 152
  end
  object RESTResponse4: TRESTResponse
    Left = 656
    Top = 168
  end
  object RESTResponseDataSetAdapter3: TRESTResponseDataSetAdapter
    Dataset = FDMemTable3
    FieldDefs = <>
    Response = RESTResponse4
    TypesMode = JSONOnly
    Left = 664
    Top = 176
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
    Left = 672
    Top = 184
  end
end
