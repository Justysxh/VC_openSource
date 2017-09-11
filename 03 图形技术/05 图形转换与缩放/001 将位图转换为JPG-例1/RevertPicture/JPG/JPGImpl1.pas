unit JPGImpl1;

{$WARN SYMBOL_PLATFORM OFF}

interface

uses
  Windows, ActiveX, Classes, Controls, Graphics, Menus, Forms, StdCtrls,
  ComServ, StdVCL, AXCtrls, JPGXControl1_TLB,jpeg;

type
  TJPG = class(TActiveXControl, IJPG)
  private
    { Private declarations }
    FDelphiControl: TButton;
    FEvents: IJPGEvents;
    FFileName: WideString;
    FQuality: SYSINT;
    procedure ClickEvent(Sender: TObject);
    procedure KeyPressEvent(Sender: TObject; var Key: Char);
  protected
    { Protected declarations }
    procedure DefinePropertyPages(DefinePropertyPage: TDefinePropertyPage); override;
    procedure EventSinkChanged(const EventSink: IUnknown); override;
    procedure InitializeControl; override;
    function DrawTextBiDiModeFlagsReadingOnly: Integer; safecall;
    function Get_AlignDisabled: WordBool; safecall;
    function Get_Cancel: WordBool; safecall;
    function Get_Caption: WideString; safecall;
    function Get_Default: WordBool; safecall;
    function Get_DoubleBuffered: WordBool; safecall;
    function Get_DragCursor: Smallint; safecall;
    function Get_DragMode: TxDragMode; safecall;
    function Get_Enabled: WordBool; safecall;
    function Get_Font: IFontDisp; safecall;
    function Get_Visible: WordBool; safecall;
    function Get_VisibleDockClientCount: Integer; safecall;
    function Get_WordWrap: WordBool; safecall;
    function IsRightToLeft: WordBool; safecall;
    function UseRightToLeftReading: WordBool; safecall;
    function UseRightToLeftScrollBar: WordBool; safecall;
    procedure _Set_Font(var Value: IFontDisp); safecall;
    procedure InitiateAction; safecall;
    procedure Set_Cancel(Value: WordBool); safecall;
    procedure Set_Caption(const Value: WideString); safecall;
    procedure Set_Default(Value: WordBool); safecall;
    procedure Set_DoubleBuffered(Value: WordBool); safecall;
    procedure Set_DragCursor(Value: Smallint); safecall;
    procedure Set_DragMode(Value: TxDragMode); safecall;
    procedure Set_Enabled(Value: WordBool); safecall;
    procedure Set_Font(const Value: IFontDisp); safecall;
    procedure Set_Visible(Value: WordBool); safecall;
    procedure Set_WordWrap(Value: WordBool); safecall;
    procedure SetSubComponent(IsSubComponent: WordBool); safecall;
    function Get_BmpFile: WideString; safecall;
    function Get_Quality: SYSINT; safecall;
    procedure Set_BmpFile(const Value: WideString); safecall;
    procedure Set_Quality(Value: SYSINT); safecall;
    procedure BmpToJPG(const FileName: WideString); safecall;
  end;

implementation

uses ComObj;

{ TJPG }

procedure TJPG.DefinePropertyPages(DefinePropertyPage: TDefinePropertyPage);
begin
  {TODO: Define property pages here.  Property pages are defined by calling
    DefinePropertyPage with the class id of the page.  For example,
      DefinePropertyPage(Class_JPGPage); }
end;

procedure TJPG.EventSinkChanged(const EventSink: IUnknown);
begin
  FEvents := EventSink as IJPGEvents;
end;

procedure TJPG.InitializeControl;
begin
  FDelphiControl := Control as TButton;
  FDelphiControl.OnClick := ClickEvent;
  FDelphiControl.OnKeyPress := KeyPressEvent;
end;

function TJPG.DrawTextBiDiModeFlagsReadingOnly: Integer;
begin
  Result := FDelphiControl.DrawTextBiDiModeFlagsReadingOnly;
end;

function TJPG.Get_AlignDisabled: WordBool;
begin
  Result := FDelphiControl.AlignDisabled;
end;

function TJPG.Get_Cancel: WordBool;
begin
  Result := FDelphiControl.Cancel;
end;

function TJPG.Get_Caption: WideString;
begin
  Result := WideString(FDelphiControl.Caption);
end;

function TJPG.Get_Default: WordBool;
begin
  Result := FDelphiControl.Default;
end;

function TJPG.Get_DoubleBuffered: WordBool;
begin
  Result := FDelphiControl.DoubleBuffered;
end;

function TJPG.Get_DragCursor: Smallint;
begin
  Result := Smallint(FDelphiControl.DragCursor);
end;

function TJPG.Get_DragMode: TxDragMode;
begin
  Result := Ord(FDelphiControl.DragMode);
end;

function TJPG.Get_Enabled: WordBool;
begin
  Result := FDelphiControl.Enabled;
end;

function TJPG.Get_Font: IFontDisp;
begin
  GetOleFont(FDelphiControl.Font, Result);
end;

function TJPG.Get_Visible: WordBool;
begin
  Result := FDelphiControl.Visible;
end;

function TJPG.Get_VisibleDockClientCount: Integer;
begin
  Result := FDelphiControl.VisibleDockClientCount;
end;

function TJPG.Get_WordWrap: WordBool;
begin
  Result := FDelphiControl.WordWrap;
end;

function TJPG.IsRightToLeft: WordBool;
begin
  Result := FDelphiControl.IsRightToLeft;
end;

function TJPG.UseRightToLeftReading: WordBool;
begin
  Result := FDelphiControl.UseRightToLeftReading;
end;

function TJPG.UseRightToLeftScrollBar: WordBool;
begin
  Result := FDelphiControl.UseRightToLeftScrollBar;
end;

procedure TJPG._Set_Font(var Value: IFontDisp);
begin
  SetOleFont(FDelphiControl.Font, Value);
end;

procedure TJPG.ClickEvent(Sender: TObject);
begin
  if FEvents <> nil then FEvents.OnClick;
end;

procedure TJPG.InitiateAction;
begin
  FDelphiControl.InitiateAction;
end;

procedure TJPG.KeyPressEvent(Sender: TObject; var Key: Char);
var
  TempKey: Smallint;
begin
  TempKey := Smallint(Key);
  if FEvents <> nil then FEvents.OnKeyPress(TempKey);
  Key := Char(TempKey);
end;

procedure TJPG.Set_Cancel(Value: WordBool);
begin
  FDelphiControl.Cancel := Value;
end;

procedure TJPG.Set_Caption(const Value: WideString);
begin
  FDelphiControl.Caption := TCaption(Value);
end;

procedure TJPG.Set_Default(Value: WordBool);
begin
  FDelphiControl.Default := Value;
end;

procedure TJPG.Set_DoubleBuffered(Value: WordBool);
begin
  FDelphiControl.DoubleBuffered := Value;
end;

procedure TJPG.Set_DragCursor(Value: Smallint);
begin
  FDelphiControl.DragCursor := TCursor(Value);
end;

procedure TJPG.Set_DragMode(Value: TxDragMode);
begin
  FDelphiControl.DragMode := TDragMode(Value);
end;

procedure TJPG.Set_Enabled(Value: WordBool);
begin
  FDelphiControl.Enabled := Value;
end;

procedure TJPG.Set_Font(const Value: IFontDisp);
begin
  SetOleFont(FDelphiControl.Font, Value);
end;

procedure TJPG.Set_Visible(Value: WordBool);
begin
  FDelphiControl.Visible := Value;
end;

procedure TJPG.Set_WordWrap(Value: WordBool);
begin
  FDelphiControl.WordWrap := Value;
end;

procedure TJPG.SetSubComponent(IsSubComponent: WordBool);
begin
  FDelphiControl.SetSubComponent(IsSubComponent);
end;

function TJPG.Get_BmpFile: WideString;
begin
  Result := FFileName;
end;

function TJPG.Get_Quality: SYSINT;
begin
  Result := FQuality;
end;

procedure TJPG.Set_BmpFile(const Value: WideString);
begin
  FFileName := Value;
end;

procedure TJPG.Set_Quality(Value: SYSINT);
begin
  FQuality := Value;
end;

procedure TJPG.BmpToJPG(const FileName: WideString);
var
  jpg: TJPEGImage;
  bmp: TBitmap;
begin
  jpg := TJPEGImage.Create();
  bmp := TBitmap.Create();
  bmp.LoadFromFile(FFileName);
  jpg.Assign(bmp);
  jpg.CompressionQuality := FQuality;
  jpg.Compress;
  jpg.SaveToFile(FileName);
  bmp.Free;
  jpg.Free;
end;



initialization
  TActiveXControlFactory.Create(
    ComServer,
    TJPG,
    TButton,
    Class_JPG,
    1,
    '',
    0,
    tmApartment);
end.
