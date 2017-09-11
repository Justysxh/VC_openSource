unit GIFXControl1_TLB;

// ************************************************************************ //
// WARNING                                                                    
// -------                                                                    
// The types declared in this file were generated from data read from a       
// Type Library. If this type library is explicitly or indirectly (via        
// another type library referring to this type library) re-imported, or the   
// 'Refresh' command of the Type Library Editor activated while editing the   
// Type Library, the contents of this file will be regenerated and all        
// manual modifications will be lost.                                         
// ************************************************************************ //

// PASTLWTR : 1.2
// File generated on 2006-12-02 9:40:56 from Type Library described below.

// ************************************************************************  //
// Type Lib: C:\GIF\GIFXControl1.tlb (1)
// LIBID: {6018E0B8-94B6-448F-BC05-2F6C60E42367}
// LCID: 0
// Helpfile: 
// HelpString: GIFXControl1 Library
// DepndLst: 
//   (1) v2.0 stdole, (C:\WINNT\System32\stdole2.tlb)
// ************************************************************************ //
{$TYPEDADDRESS OFF} // Unit must be compiled without type-checked pointers. 
{$WARN SYMBOL_PLATFORM OFF}
{$WRITEABLECONST ON}
{$VARPROPSETTER ON}
interface

uses Windows, ActiveX, Classes, Graphics, OleCtrls, StdVCL, Variants;
  

// *********************************************************************//
// GUIDS declared in the TypeLibrary. Following prefixes are used:        
//   Type Libraries     : LIBID_xxxx                                      
//   CoClasses          : CLASS_xxxx                                      
//   DISPInterfaces     : DIID_xxxx                                       
//   Non-DISP interfaces: IID_xxxx                                        
// *********************************************************************//
const
  // TypeLibrary Major and minor versions
  GIFXControl1MajorVersion = 1;
  GIFXControl1MinorVersion = 0;

  LIBID_GIFXControl1: TGUID = '{6018E0B8-94B6-448F-BC05-2F6C60E42367}';

  IID_IGIF: TGUID = '{4D74B586-FD74-4638-BC38-8058188FFF4E}';
  DIID_IGIFEvents: TGUID = '{1D92C91E-9F2A-4DA8-9304-6494A53CD92E}';
  CLASS_GIF: TGUID = '{832BE334-CA39-4F64-9988-E43C1596A9AC}';

// *********************************************************************//
// Declaration of Enumerations defined in Type Library                    
// *********************************************************************//
// Constants for enum TxDragMode
type
  TxDragMode = TOleEnum;
const
  dmManual = $00000000;
  dmAutomatic = $00000001;

// Constants for enum TxMouseButton
type
  TxMouseButton = TOleEnum;
const
  mbLeft = $00000000;
  mbRight = $00000001;
  mbMiddle = $00000002;

type

// *********************************************************************//
// Forward declaration of types defined in TypeLibrary                    
// *********************************************************************//
  IGIF = interface;
  IGIFDisp = dispinterface;
  IGIFEvents = dispinterface;

// *********************************************************************//
// Declaration of CoClasses defined in Type Library                       
// (NOTE: Here we map each CoClass to its Default Interface)              
// *********************************************************************//
  GIF = IGIF;


// *********************************************************************//
// Declaration of structures, unions and aliases.                         
// *********************************************************************//
  PPUserType1 = ^IFontDisp; {*}


// *********************************************************************//
// Interface: IGIF
// Flags:     (4416) Dual OleAutomation Dispatchable
// GUID:      {4D74B586-FD74-4638-BC38-8058188FFF4E}
// *********************************************************************//
  IGIF = interface(IDispatch)
    ['{4D74B586-FD74-4638-BC38-8058188FFF4E}']
    function Get_Cancel: WordBool; safecall;
    procedure Set_Cancel(Value: WordBool); safecall;
    function Get_Caption: WideString; safecall;
    procedure Set_Caption(const Value: WideString); safecall;
    function Get_Default: WordBool; safecall;
    procedure Set_Default(Value: WordBool); safecall;
    function Get_DragCursor: Smallint; safecall;
    procedure Set_DragCursor(Value: Smallint); safecall;
    function Get_DragMode: TxDragMode; safecall;
    procedure Set_DragMode(Value: TxDragMode); safecall;
    function Get_Enabled: WordBool; safecall;
    procedure Set_Enabled(Value: WordBool); safecall;
    function Get_Font: IFontDisp; safecall;
    procedure Set_Font(const Value: IFontDisp); safecall;
    procedure _Set_Font(var Value: IFontDisp); safecall;
    function Get_Visible: WordBool; safecall;
    procedure Set_Visible(Value: WordBool); safecall;
    function Get_WordWrap: WordBool; safecall;
    procedure Set_WordWrap(Value: WordBool); safecall;
    function Get_DoubleBuffered: WordBool; safecall;
    procedure Set_DoubleBuffered(Value: WordBool); safecall;
    function Get_AlignDisabled: WordBool; safecall;
    function Get_VisibleDockClientCount: Integer; safecall;
    function DrawTextBiDiModeFlagsReadingOnly: Integer; safecall;
    procedure InitiateAction; safecall;
    function IsRightToLeft: WordBool; safecall;
    function UseRightToLeftReading: WordBool; safecall;
    function UseRightToLeftScrollBar: WordBool; safecall;
    procedure SetSubComponent(IsSubComponent: WordBool); safecall;
    procedure SaveToFile(const FileName: WideString); safecall;
    function Get_BmpFile: WideString; safecall;
    procedure Set_BmpFile(const Value: WideString); safecall;
    property Cancel: WordBool read Get_Cancel write Set_Cancel;
    property Caption: WideString read Get_Caption write Set_Caption;
    property Default: WordBool read Get_Default write Set_Default;
    property DragCursor: Smallint read Get_DragCursor write Set_DragCursor;
    property DragMode: TxDragMode read Get_DragMode write Set_DragMode;
    property Enabled: WordBool read Get_Enabled write Set_Enabled;
    property Font: IFontDisp read Get_Font write Set_Font;
    property Visible: WordBool read Get_Visible write Set_Visible;
    property WordWrap: WordBool read Get_WordWrap write Set_WordWrap;
    property DoubleBuffered: WordBool read Get_DoubleBuffered write Set_DoubleBuffered;
    property AlignDisabled: WordBool read Get_AlignDisabled;
    property VisibleDockClientCount: Integer read Get_VisibleDockClientCount;
    property BmpFile: WideString read Get_BmpFile write Set_BmpFile;
  end;

// *********************************************************************//
// DispIntf:  IGIFDisp
// Flags:     (4416) Dual OleAutomation Dispatchable
// GUID:      {4D74B586-FD74-4638-BC38-8058188FFF4E}
// *********************************************************************//
  IGIFDisp = dispinterface
    ['{4D74B586-FD74-4638-BC38-8058188FFF4E}']
    property Cancel: WordBool dispid 201;
    property Caption: WideString dispid -518;
    property Default: WordBool dispid 202;
    property DragCursor: Smallint dispid 203;
    property DragMode: TxDragMode dispid 204;
    property Enabled: WordBool dispid -514;
    property Font: IFontDisp dispid -512;
    property Visible: WordBool dispid 205;
    property WordWrap: WordBool dispid 206;
    property DoubleBuffered: WordBool dispid 207;
    property AlignDisabled: WordBool readonly dispid 208;
    property VisibleDockClientCount: Integer readonly dispid 209;
    function DrawTextBiDiModeFlagsReadingOnly: Integer; dispid 210;
    procedure InitiateAction; dispid 211;
    function IsRightToLeft: WordBool; dispid 212;
    function UseRightToLeftReading: WordBool; dispid 213;
    function UseRightToLeftScrollBar: WordBool; dispid 214;
    procedure SetSubComponent(IsSubComponent: WordBool); dispid 215;
    procedure SaveToFile(const FileName: WideString); dispid 216;
    property BmpFile: WideString dispid 217;
  end;

// *********************************************************************//
// DispIntf:  IGIFEvents
// Flags:     (4096) Dispatchable
// GUID:      {1D92C91E-9F2A-4DA8-9304-6494A53CD92E}
// *********************************************************************//
  IGIFEvents = dispinterface
    ['{1D92C91E-9F2A-4DA8-9304-6494A53CD92E}']
    procedure OnClick; dispid 201;
    procedure OnKeyPress(var Key: Smallint); dispid 202;
  end;


// *********************************************************************//
// OLE Control Proxy class declaration
// Control Name     : TGIF
// Help String      : GIF Control
// Default Interface: IGIF
// Def. Intf. DISP? : No
// Event   Interface: IGIFEvents
// TypeFlags        : (34) CanCreate Control
// *********************************************************************//
  TGIFOnKeyPress = procedure(ASender: TObject; var Key: Smallint) of object;

  TGIF = class(TOleControl)
  private
    FOnClick: TNotifyEvent;
    FOnKeyPress: TGIFOnKeyPress;
    FIntf: IGIF;
    function  GetControlInterface: IGIF;
  protected
    procedure CreateControl;
    procedure InitControlData; override;
  public
    function DrawTextBiDiModeFlagsReadingOnly: Integer;
    procedure InitiateAction;
    function IsRightToLeft: WordBool;
    function UseRightToLeftReading: WordBool;
    function UseRightToLeftScrollBar: WordBool;
    procedure SetSubComponent(IsSubComponent: WordBool);
    procedure SaveToFile(const FileName: WideString);
    property  ControlInterface: IGIF read GetControlInterface;
    property  DefaultInterface: IGIF read GetControlInterface;
    property DoubleBuffered: WordBool index 207 read GetWordBoolProp write SetWordBoolProp;
    property AlignDisabled: WordBool index 208 read GetWordBoolProp;
    property VisibleDockClientCount: Integer index 209 read GetIntegerProp;
  published
    property Anchors;
    property  ParentFont;
    property  TabStop;
    property  Align;
    property  ParentShowHint;
    property  PopupMenu;
    property  ShowHint;
    property  TabOrder;
    property  OnDragDrop;
    property  OnDragOver;
    property  OnEndDrag;
    property  OnEnter;
    property  OnExit;
    property  OnStartDrag;
    property Cancel: WordBool index 201 read GetWordBoolProp write SetWordBoolProp stored False;
    property Caption: WideString index -518 read GetWideStringProp write SetWideStringProp stored False;
    property Default: WordBool index 202 read GetWordBoolProp write SetWordBoolProp stored False;
    property DragCursor: Smallint index 203 read GetSmallintProp write SetSmallintProp stored False;
    property DragMode: TOleEnum index 204 read GetTOleEnumProp write SetTOleEnumProp stored False;
    property Enabled: WordBool index -514 read GetWordBoolProp write SetWordBoolProp stored False;
    property Font: TFont index -512 read GetTFontProp write SetTFontProp stored False;
    property Visible: WordBool index 205 read GetWordBoolProp write SetWordBoolProp stored False;
    property WordWrap: WordBool index 206 read GetWordBoolProp write SetWordBoolProp stored False;
    property BmpFile: WideString index 217 read GetWideStringProp write SetWideStringProp stored False;
    property OnClick: TNotifyEvent read FOnClick write FOnClick;
    property OnKeyPress: TGIFOnKeyPress read FOnKeyPress write FOnKeyPress;
  end;

procedure Register;

resourcestring
  dtlServerPage = 'Servers';

  dtlOcxPage = 'ActiveX';

implementation

uses ComObj;

procedure TGIF.InitControlData;
const
  CEventDispIDs: array [0..1] of DWORD = (
    $000000C9, $000000CA);
  CTFontIDs: array [0..0] of DWORD = (
    $FFFFFE00);
  CControlData: TControlData2 = (
    ClassID: '{832BE334-CA39-4F64-9988-E43C1596A9AC}';
    EventIID: '{1D92C91E-9F2A-4DA8-9304-6494A53CD92E}';
    EventCount: 2;
    EventDispIDs: @CEventDispIDs;
    LicenseKey: nil (*HR:$00000000*);
    Flags: $0000001C;
    Version: 401;
    FontCount: 1;
    FontIDs: @CTFontIDs);
begin
  ControlData := @CControlData;
  TControlData2(CControlData).FirstEventOfs := Cardinal(@@FOnClick) - Cardinal(Self);
end;

procedure TGIF.CreateControl;

  procedure DoCreate;
  begin
    FIntf := IUnknown(OleObject) as IGIF;
  end;

begin
  if FIntf = nil then DoCreate;
end;

function TGIF.GetControlInterface: IGIF;
begin
  CreateControl;
  Result := FIntf;
end;

function TGIF.DrawTextBiDiModeFlagsReadingOnly: Integer;
begin
  Result := DefaultInterface.DrawTextBiDiModeFlagsReadingOnly;
end;

procedure TGIF.InitiateAction;
begin
  DefaultInterface.InitiateAction;
end;

function TGIF.IsRightToLeft: WordBool;
begin
  Result := DefaultInterface.IsRightToLeft;
end;

function TGIF.UseRightToLeftReading: WordBool;
begin
  Result := DefaultInterface.UseRightToLeftReading;
end;

function TGIF.UseRightToLeftScrollBar: WordBool;
begin
  Result := DefaultInterface.UseRightToLeftScrollBar;
end;

procedure TGIF.SetSubComponent(IsSubComponent: WordBool);
begin
  DefaultInterface.SetSubComponent(IsSubComponent);
end;

procedure TGIF.SaveToFile(const FileName: WideString);
begin
  DefaultInterface.SaveToFile(FileName);
end;

procedure Register;
begin
  RegisterComponents(dtlOcxPage, [TGIF]);
end;

end.
