unit GIFImpl1;

{$WARN SYMBOL_PLATFORM OFF}

interface

uses
  Windows, ActiveX, Classes, Controls, Graphics, Menus, Forms, StdCtrls,
  ComServ, StdVCL, AXCtrls, GIFXControl1_TLB,GIFImage,ExtCtrls;

type
  TGIF = class(TActiveXControl, IGIF)
  private
    { Private declarations }
    FDelphiControl: TButton;
    FEvents: IGIFEvents;
    FBmpFile: WideString;
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
    procedure SaveToFile(const FileName: WideString); safecall;
    function Get_BmpFile: WideString; safecall;
    procedure Set_BmpFile(Value: WideString); safecall;  function IGIF.Get_BmpFile = IGIF_Get_BmpFile;
    procedure IGIF.Set_BmpFile = IGIF_Set_BmpFile;
    function IGIF_Get_BmpFile: WideString; safecall;
    procedure IGIF_Set_BmpFile(const Value: WideString); safecall;
  end;

implementation

uses ComObj;

{ TGIF }

procedure TGIF.DefinePropertyPages(DefinePropertyPage: TDefinePropertyPage);
begin
  {TODO: Define property pages here.  Property pages are defined by calling
    DefinePropertyPage with the class id of the page.  For example,
      DefinePropertyPage(Class_GIFPage); }
end;

procedure TGIF.EventSinkChanged(const EventSink: IUnknown);
begin
  FEvents := EventSink as IGIFEvents;
end;

procedure TGIF.InitializeControl;
begin
  FDelphiControl := Control as TButton;
  FDelphiControl.OnClick := ClickEvent;
  FDelphiControl.OnKeyPress := KeyPressEvent;
end;

function TGIF.DrawTextBiDiModeFlagsReadingOnly: Integer;
begin
  Result := FDelphiControl.DrawTextBiDiModeFlagsReadingOnly;
end;

function TGIF.Get_AlignDisabled: WordBool;
begin
  Result := FDelphiControl.AlignDisabled;
end;

function TGIF.Get_Cancel: WordBool;
begin
  Result := FDelphiControl.Cancel;
end;

function TGIF.Get_Caption: WideString;
begin
  Result := WideString(FDelphiControl.Caption);
end;

function TGIF.Get_Default: WordBool;
begin
  Result := FDelphiControl.Default;
end;

function TGIF.Get_DoubleBuffered: WordBool;
begin
  Result := FDelphiControl.DoubleBuffered;
end;

function TGIF.Get_DragCursor: Smallint;
begin
  Result := Smallint(FDelphiControl.DragCursor);
end;

function TGIF.Get_DragMode: TxDragMode;
begin
  Result := Ord(FDelphiControl.DragMode);
end;

function TGIF.Get_Enabled: WordBool;
begin
  Result := FDelphiControl.Enabled;
end;

function TGIF.Get_Font: IFontDisp;
begin
  GetOleFont(FDelphiControl.Font, Result);
end;

function TGIF.Get_Visible: WordBool;
begin
  Result := FDelphiControl.Visible;
end;

function TGIF.Get_VisibleDockClientCount: Integer;
begin
  Result := FDelphiControl.VisibleDockClientCount;
end;

function TGIF.Get_WordWrap: WordBool;
begin
  Result := FDelphiControl.WordWrap;
end;

function TGIF.IsRightToLeft: WordBool;
begin
  Result := FDelphiControl.IsRightToLeft;
end;

function TGIF.UseRightToLeftReading: WordBool;
begin
  Result := FDelphiControl.UseRightToLeftReading;
end;

function TGIF.UseRightToLeftScrollBar: WordBool;
begin
  Result := FDelphiControl.UseRightToLeftScrollBar;
end;

procedure TGIF._Set_Font(var Value: IFontDisp);
begin
  SetOleFont(FDelphiControl.Font, Value);
end;

procedure TGIF.ClickEvent(Sender: TObject);
begin
  if FEvents <> nil then FEvents.OnClick;
end;

procedure TGIF.InitiateAction;
begin
  FDelphiControl.InitiateAction;
end;

procedure TGIF.KeyPressEvent(Sender: TObject; var Key: Char);
var
  TempKey: Smallint;
begin
  TempKey := Smallint(Key);
  if FEvents <> nil then FEvents.OnKeyPress(TempKey);
  Key := Char(TempKey);
end;

procedure TGIF.Set_Cancel(Value: WordBool);
begin
  FDelphiControl.Cancel := Value;
end;

procedure TGIF.Set_Caption(const Value: WideString);
begin
  FDelphiControl.Caption := TCaption(Value);
end;

procedure TGIF.Set_Default(Value: WordBool);
begin
  FDelphiControl.Default := Value;
end;

procedure TGIF.Set_DoubleBuffered(Value: WordBool);
begin
  FDelphiControl.DoubleBuffered := Value;
end;

procedure TGIF.Set_DragCursor(Value: Smallint);
begin
  FDelphiControl.DragCursor := TCursor(Value);
end;

procedure TGIF.Set_DragMode(Value: TxDragMode);
begin
  FDelphiControl.DragMode := TDragMode(Value);
end;

procedure TGIF.Set_Enabled(Value: WordBool);
begin
  FDelphiControl.Enabled := Value;
end;

procedure TGIF.Set_Font(const Value: IFontDisp);
begin
  SetOleFont(FDelphiControl.Font, Value);
end;

procedure TGIF.Set_Visible(Value: WordBool);
begin
  FDelphiControl.Visible := Value;
end;

procedure TGIF.Set_WordWrap(Value: WordBool);
begin
  FDelphiControl.WordWrap := Value;
end;

procedure TGIF.SetSubComponent(IsSubComponent: WordBool);
begin
  FDelphiControl.SetSubComponent(IsSubComponent);
end;

procedure TGIF.SaveToFile(const FileName: WideString);
var
  gif: TGIFImage;
  img1: TImage;
begin
  img1 := TImage.Create(NIL);
  img1.Picture.LoadFromFile(FBmpFile);
  gif := TGIFImage.Create();
  gif.Assign(img1.Picture.Bitmap);
  gif.Compression := gcLZW;
  gif.AspectRatio := 200;
  gif.SaveToFile(FileName);
  gif.Free;
  img1.Free;
end;

function TGIF.Get_BmpFile: WideString;
begin
  Result := FBmpFile;
end;

procedure TGIF.Set_BmpFile(Value: WideString);
begin
  FBmpFile := Value;
end;

function TGIF.IGIF_Get_BmpFile: WideString;
begin
  Result := FBmpFile;
end;

procedure TGIF.IGIF_Set_BmpFile(const Value: WideString);
begin
  FBmpFile := Value;
end;

initialization
  TActiveXControlFactory.Create(
    ComServer,
    TGIF,
    TButton,
    Class_GIF,
    1,
    '',
    0,
    tmApartment);
end.
