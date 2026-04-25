object Form9: TForm9
  Left = 0
  Top = 0
  Caption = 'Form9'
  ClientHeight = 575
  ClientWidth = 1103
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -12
  Font.Name = 'Segoe UI'
  Font.Style = []
  TextHeight = 15
  object Label1: TLabel
    Left = 398
    Top = 31
    Width = 244
    Height = 39
    Caption = 'Freshman Courses'
    Color = clDefault
    Font.Charset = ANSI_CHARSET
    Font.Color = clWindowText
    Font.Height = -27
    Font.Name = 'Noto Sans KR'
    Font.Style = [fsBold]
    ParentColor = False
    ParentFont = False
  end
  object Label2: TLabel
    Left = 72
    Top = 78
    Width = 118
    Height = 27
    Caption = 'Total Credits'
    Font.Charset = ANSI_CHARSET
    Font.Color = clRed
    Font.Height = -19
    Font.Name = 'Noto Sans KR'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object Label3: TLabel
    Left = 101
    Top = 124
    Width = 5
    Height = 30
    Font.Charset = ANSI_CHARSET
    Font.Color = clBlack
    Font.Height = -21
    Font.Name = 'Noto Sans KR'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object Label5: TLabel
    Left = 273
    Top = 124
    Width = 3
    Height = 15
  end
  object Label9: TLabel
    Left = 72
    Top = 200
    Width = 107
    Height = 17
    Caption = '45 credits required'
    Font.Charset = ANSI_CHARSET
    Font.Color = clRed
    Font.Height = -12
    Font.Name = 'Noto Sans KR'
    Font.Style = []
    ParentFont = False
  end
  object Label15: TLabel
    Left = 32
    Top = 400
    Width = 215
    Height = 95
    Caption = 
      '            Freshman Reminders '#13#10'Freshmans are required to take ' +
      'two'#13#10'credits in each of the  following '#13#10'subjects: English, Math' +
      ', Science, '#13#10'World History and PE/Dance'
    Font.Charset = ANSI_CHARSET
    Font.Color = clBlack
    Font.Height = -13
    Font.Name = 'Noto Sans KR Medium'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object GroupBox1: TGroupBox
    Left = 32
    Top = 248
    Width = 217
    Height = 129
    Caption = 'Summer 2026'
    TabOrder = 0
    object Label8: TLabel
      Left = 40
      Top = 24
      Width = 37
      Height = 15
      Caption = 'Course'
    end
    object Label10: TLabel
      Left = 168
      Top = 24
      Width = 32
      Height = 15
      Caption = 'Credit'
    end
    object Label11: TLabel
      Left = 179
      Top = 45
      Width = 6
      Height = 15
      Caption = '0'
    end
    object Label12: TLabel
      Left = 179
      Top = 80
      Width = 6
      Height = 15
      Caption = '0'
    end
    object Label13: TLabel
      Left = 0
      Top = 111
      Width = 159
      Height = 15
      Caption = 'Summer Credits (Maximum 2)'
    end
    object Label14: TLabel
      Left = 179
      Top = 111
      Width = 6
      Height = 15
      Caption = '0'
    end
    object ComboBox1: TComboBox
      Left = 0
      Top = 45
      Width = 144
      Height = 23
      TabOrder = 0
      Text = 'Summer #1 (Optional)'
      OnChange = ComboBox1Change
      Items.Strings = (
        'Academic Literacy'
        'Algebra 1 (A year course)'
        'Art & Design'
        'Business'
        'Computer Programming 1'
        'ELL programming'
        'Intro to Business'
        'Photography 1'
        'World History (A year course)')
    end
    object ComboBox2: TComboBox
      Left = 0
      Top = 82
      Width = 145
      Height = 23
      TabOrder = 1
      Text = 'Summer #2 (Optional)'
      OnChange = ComboBox2Change
      Items.Strings = (
        'Academic Literacy'
        'Algebra 1 (A year course)'
        'Art & Design'
        'Business'
        'Computer Programming 1'
        'ELL programming'
        'Intro to Business'
        'Photography 1'
        'World History (A year course)')
    end
  end
  object GroupBox2: TGroupBox
    Left = 255
    Top = 232
    Width = 398
    Height = 297
    Caption = 'Freshman Fall 2026'
    TabOrder = 1
    object Label16: TLabel
      Left = 128
      Top = 24
      Width = 57
      Height = 15
      Caption = 'Semester 1'
    end
    object GroupBox3: TGroupBox
      Left = 3
      Top = 40
      Width = 62
      Height = 246
      Caption = 'course #'
      TabOrder = 0
      object Label17: TLabel
        Left = 3
        Top = 18
        Width = 55
        Height = 225
        Caption = 
          '       1'#13#10'-----------'#13#10'       2'#13#10'-----------'#13#10'       3'#13#10'--------' +
          '---'#13#10'       4         '#13#10'-----------'#13#10'       5'#13#10'-----------'#13#10'    ' +
          '   6'#13#10'-----------'#13#10'       7'#13#10'-----------'#13#10'       8'
      end
    end
    object GroupBox4: TGroupBox
      Left = 67
      Top = 40
      Width = 118
      Height = 246
      Caption = 'subject'
      TabOrder = 1
      object Label18: TLabel
        Left = 4
        Top = 20
        Width = 72
        Height = 165
        Caption = 
          'English'#13#10#13#10'Math'#13#10#13#10'PE or Dance'#13#10#13#10'Social Studies'#13#10#13#10'Science'#13#10#13#10'L' +
          'unch'
      end
      object ComboBox3: TComboBox
        Left = 4
        Top = 191
        Width = 102
        Height = 23
        TabOrder = 0
        Text = 'Select Subjects'
        Items.Strings = (
          'Business'
          'Computer Science'
          'Music'
          'World Language'
          'ELL'
          'Study Hall')
      end
      object ComboBox4: TComboBox
        Left = 4
        Top = 220
        Width = 103
        Height = 23
        TabOrder = 1
        Text = 'Select Subjects'
        Items.Strings = (
          'Business'
          'Computer Science'
          'Music'
          'World Language'
          'ELL'
          'Study Hall')
      end
    end
    object GroupBox5: TGroupBox
      Left = 191
      Top = 45
      Width = 138
      Height = 249
      Caption = 'Courses'
      TabOrder = 2
      object Label19: TLabel
        Left = 16
        Top = 172
        Width = 33
        Height = 15
        Caption = 'Lunch'
      end
    end
    object ComboBox5: TComboBox
      Left = 200
      Top = 59
      Width = 113
      Height = 23
      TabOrder = 3
      Text = 'Chooses Class'
      OnChange = ComboBox5Change
      Items.Strings = (
        'Freshman English'
        'Freshman English AC'
        'English Language Devlopent')
    end
    object ComboBox6: TComboBox
      Left = 200
      Top = 88
      Width = 113
      Height = 23
      TabOrder = 4
      Text = 'Choose Class'
      Items.Strings = (
        'Algebra 1'
        'Geometry'
        'Geometry AB/BC'
        'Algebra 2'
        'Algebra 2 AB/BC'
        'AP Math Course')
    end
    object ComboBox7: TComboBox
      Left = 199
      Top = 119
      Width = 113
      Height = 23
      TabOrder = 5
      Text = 'Choose Class'
      Items.Strings = (
        'Freshman PE'
        'Dance 1')
    end
    object ComboBox8: TComboBox
      Left = 200
      Top = 151
      Width = 113
      Height = 23
      TabOrder = 6
      Text = 'Choose Class'
      Items.Strings = (
        'World History'
        ''
        'IF WORLD HSTORY was taken over summer'
        'Psychology'
        'World Religion')
    end
    object ComboBox9: TComboBox
      Left = 200
      Top = 180
      Width = 113
      Height = 23
      TabOrder = 7
      Text = 'Choose Class'
      Items.Strings = (
        'Biology'
        'Chemistry')
    end
    object ComboBox10: TComboBox
      Left = 200
      Top = 234
      Width = 113
      Height = 23
      TabOrder = 8
      Text = '<- Select subject'
    end
    object ComboBox11: TComboBox
      Left = 200
      Top = 263
      Width = 113
      Height = 23
      TabOrder = 9
      Text = '<- Select subject'
    end
    object GroupBox10: TGroupBox
      Left = 335
      Top = 40
      Width = 60
      Height = 249
      Caption = 'Credit'
      TabOrder = 10
      object Label21: TLabel
        Left = 5
        Top = 24
        Width = 6
        Height = 15
        Alignment = taCenter
        Caption = '0'
      end
      object Label22: TLabel
        Left = 5
        Top = 53
        Width = 6
        Height = 15
        Alignment = taCenter
        Caption = '0'
      end
      object Label24: TLabel
        Left = 5
        Top = 114
        Width = 6
        Height = 15
        Alignment = taCenter
        Caption = '0'
      end
      object Label23: TLabel
        Left = 5
        Top = 84
        Width = 6
        Height = 15
        Alignment = taCenter
        Caption = '0'
      end
      object Label26: TLabel
        Left = 5
        Top = 173
        Width = 6
        Height = 15
        Alignment = taCenter
        Caption = '0'
      end
      object Label25: TLabel
        Left = 4
        Top = 143
        Width = 6
        Height = 15
        Alignment = taCenter
        Caption = '0'
      end
      object Label27: TLabel
        Left = 4
        Top = 198
        Width = 6
        Height = 15
        Alignment = taCenter
        Caption = '0'
      end
      object Label40: TLabel
        Left = 4
        Top = 226
        Width = 6
        Height = 15
        Alignment = taCenter
        Caption = '0'
      end
    end
  end
  object GroupBox6: TGroupBox
    Left = 671
    Top = 232
    Width = 398
    Height = 297
    Caption = 'Freshman Spring 2027'
    TabOrder = 2
    object Label28: TLabel
      Left = 128
      Top = 24
      Width = 57
      Height = 15
      Caption = 'Semester 2'
    end
    object GroupBox7: TGroupBox
      Left = 3
      Top = 40
      Width = 62
      Height = 254
      Caption = 'course #'
      TabOrder = 0
      object Label29: TLabel
        Left = 3
        Top = 18
        Width = 55
        Height = 225
        Caption = 
          '       1'#13#10'-----------'#13#10'       2'#13#10'-----------'#13#10'       3'#13#10'--------' +
          '---'#13#10'       4         '#13#10'-----------'#13#10'       5'#13#10'-----------'#13#10'    ' +
          '   6'#13#10'-----------'#13#10'       7'#13#10'-----------'#13#10'       8'
      end
    end
    object GroupBox8: TGroupBox
      Left = 67
      Top = 40
      Width = 118
      Height = 254
      Caption = 'subject'
      TabOrder = 1
      object Label30: TLabel
        Left = 12
        Top = 20
        Width = 72
        Height = 165
        Caption = 
          'English'#13#10#13#10'Math'#13#10#13#10'PE or Dance'#13#10#13#10'Social Studies'#13#10#13#10'Science'#13#10#13#10'L' +
          'unch'
      end
      object ComboBox12: TComboBox
        Left = 4
        Top = 191
        Width = 102
        Height = 23
        TabOrder = 0
        Text = 'Select Subjects'
        Items.Strings = (
          'Business'
          'Computer Science'
          'Music'
          'World Language'
          'ELL'
          'Study Hall')
      end
      object ComboBox13: TComboBox
        Left = 4
        Top = 220
        Width = 103
        Height = 23
        TabOrder = 1
        Text = 'Select Subjects'
        Items.Strings = (
          'Business'
          'Computer Science'
          'Music'
          'World Language'
          'ELL'
          'Study Hall')
      end
    end
    object GroupBox9: TGroupBox
      Left = 191
      Top = 40
      Width = 138
      Height = 254
      Caption = 'Courses'
      TabOrder = 2
      object Label31: TLabel
        Left = 16
        Top = 170
        Width = 33
        Height = 15
        Caption = 'Lunch'
      end
    end
    object ComboBox14: TComboBox
      Left = 200
      Top = 59
      Width = 113
      Height = 23
      TabOrder = 3
      Text = 'Chooses Class'
      Items.Strings = (
        'Freshman English'
        'Freshman English AC'
        'English Language Devlopent')
    end
    object ComboBox15: TComboBox
      Left = 200
      Top = 88
      Width = 113
      Height = 23
      TabOrder = 4
      Text = 'Choose Class'
      Items.Strings = (
        'Algebra 1'
        'Geometry'
        'Geometry AB/BC'
        'Algebra 2'
        'Algebra 2 AB/BC'
        'AP Math Course')
    end
    object ComboBox16: TComboBox
      Left = 200
      Top = 118
      Width = 113
      Height = 23
      TabOrder = 5
      Text = 'Choose Class'
      Items.Strings = (
        'Freshman PE'
        'Dance 1')
    end
    object ComboBox17: TComboBox
      Left = 200
      Top = 148
      Width = 113
      Height = 23
      TabOrder = 6
      Text = 'Choose Class'
      Items.Strings = (
        'World History'
        ''
        'IF WORLD HSTORY was taken over summer'
        'Psychology'
        'World Religion')
    end
    object ComboBox18: TComboBox
      Left = 200
      Top = 179
      Width = 113
      Height = 23
      TabOrder = 7
      Text = 'Choose Class'
      Items.Strings = (
        'Biology'
        'Chemistry')
    end
    object ComboBox19: TComboBox
      Left = 200
      Top = 232
      Width = 113
      Height = 23
      TabOrder = 8
      Text = '<- Select subject'
    end
    object ComboBox20: TComboBox
      Left = 200
      Top = 262
      Width = 113
      Height = 23
      TabOrder = 9
      Text = '<- Select subject'
    end
    object GroupBox11: TGroupBox
      Left = 335
      Top = 40
      Width = 60
      Height = 254
      Caption = 'Credit'
      TabOrder = 10
      object Label20: TLabel
        Left = 5
        Top = 23
        Width = 6
        Height = 15
        Alignment = taCenter
        Caption = '0'
      end
      object Label32: TLabel
        Left = 5
        Top = 51
        Width = 6
        Height = 15
        Alignment = taCenter
        Caption = '0'
      end
      object Label33: TLabel
        Left = 4
        Top = 112
        Width = 6
        Height = 15
        Alignment = taCenter
        Caption = '0'
      end
      object Label34: TLabel
        Left = 5
        Top = 82
        Width = 6
        Height = 15
        Alignment = taCenter
        Caption = '0'
      end
      object Label35: TLabel
        Left = 5
        Top = 172
        Width = 6
        Height = 15
        Alignment = taCenter
        Caption = '0'
      end
      object Label36: TLabel
        Left = 5
        Top = 142
        Width = 6
        Height = 15
        Alignment = taCenter
        Caption = '0'
      end
      object Label37: TLabel
        Left = 5
        Top = 197
        Width = 6
        Height = 15
        Alignment = taCenter
        Caption = '0'
      end
      object Label38: TLabel
        Left = 5
        Top = 225
        Width = 6
        Height = 15
        Alignment = taCenter
        Caption = '0'
      end
    end
  end
end
