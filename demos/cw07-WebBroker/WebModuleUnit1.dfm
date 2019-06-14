object WebModule1: TWebModule1
  OldCreateOrder = False
  Actions = <
    item
      Default = True
      Name = 'DefaultHandler'
      PathInfo = '/'
      OnAction = WebModule1DefaultHandlerAction
    end>
  Height = 230
  Width = 415
  object Sqlite_demoConnection: TFDConnection
    Params.Strings = (
      'ConnectionDef=SQLite_Demo')
    Connected = True
    LoginPrompt = False
    Left = 92
    Top = 63
  end
  object CustomersTable: TFDQuery
    Active = True
    Connection = Sqlite_demoConnection
    SQL.Strings = (
      'SELECT * FROM Customers')
    Left = 92
    Top = 111
  end
  object DataSetTableProducer1: TDataSetTableProducer
    Columns = <
      item
        FieldName = 'CustomerID'
      end
      item
        FieldName = 'CompanyName'
      end
      item
        FieldName = 'ContactName'
      end
      item
        FieldName = 'ContactTitle'
      end
      item
        FieldName = 'Address'
      end
      item
        FieldName = 'City'
      end
      item
        FieldName = 'Region'
      end
      item
        FieldName = 'PostalCode'
      end
      item
        FieldName = 'Country'
      end
      item
        FieldName = 'Phone'
      end
      item
        FieldName = 'Fax'
      end>
    DataSet = CustomersTable
    Left = 200
    Top = 120
  end
end
