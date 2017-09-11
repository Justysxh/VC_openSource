unit JPGXControl1_TLB;

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
// File generated on 2006-12-01 10:03:13 from Type Library described below.

// ************************************************************************  //
// Type Lib: C:\JPG\JPGXControl1.tlb (1)
// LIBID: {345F0AC6-FABD-44EE-9F0D-6FEEEE8A5E9C}
// LCID: 0
// Helpfile: 
// HelpString: JPGXControl1 Library
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
  JPGXControl1MajorVersion = 1;
  JPGXControl1MinorVersion = 0;

  LIBID_JPGXControl1: TGUID = '{345F0AC6-FABD-44EE-9F0D-6FEEEE8A5E9C}';

  IID_IJPG: TGUID = '{F987E0CF-C4D9-4B53-8FB0-562869C8E384}';
  DIID_IJPGEvents: TGUID = '{EC890554-DAAC-47AC-8440-6AACE1A42A83}';
  CLASS_JPG: TGUID = '{662CA9D6-A177-44D4-A7BA-E6E477C95A39}';

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
  IJPG = interface;
  IJPGDisp = dispinterface;
  IJPGEvents = dispinterface;

// *********************************************************************//
// Declaration of CoClasses defined in Type Library                       
// (NOTE: Here we map each CoClass to its Default Interface)              
// *********************************************************************//
  JPG = IJPG;


// *********************************************************************//
// Declaration of structures, unions and aliases.                         
// *********************************************************************//
  PPUserType1 = ^IFontDisp; {*}


// *********************************************************************//
// Interface: IJPG
// Flags:     (4416) Dual OleAutomation Dispatchable
// GUID:      {F987E0CF-C4D9-4B53-8FB0-562869C8E384}
// *********************************************************************//
  IJPG = interface(IDispatch)
    ['{F987E0CF-C4D9-4B53-8FB0-562869C8E384}']
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
    function Get_BmpFile: WideString; safecall;
    procedure Set_BmpFile(const Value: WideString); safecall;
    function Get_Quality: SYSINT; safecall;
    procedure Set_Quality(Value: SYSINT); safecall;
    procedure BmpToJPG(const FileName: WideString); safecall;
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
    property Quality: SYSINT read Get_Quality write Set_Quality;
  end;

// *********************************************************************//
// DispIntf:  IJPGDisp
// Flags:     (4416) Dual OleAutomation Dispatchable
// GUID:      {F987E0CF-C4D9-4B53-8FB0-562869C8E384}
// *********************************************************************//
  IJPGDisp = dispinterface
    ['{F987E0CF-C4D9-4B53-8FB0-562869C8E384}']
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
    property BmpFile: WideString dispid 216;
    property Quality: SYSINT dispid 217;
    procedure BmpToJPG(const FileName: WideString); dispid 218;
  end;

// *********************************************************************//
// DispIntf:  IJPGEvents
// Flags:     (4096) Dispatchable
// GUID:      {EC890554-DAAC-47AC-8440-6AACE1A42A83}
// *********************************************************************//
  IJPGEvents = dispinterface
    ['{EC890554-DAAC-47AC-8440-6AACE1A42A83}']
    procedure OnClick; dispid 201;
    procedure OnKeyPress(var Key: Smallint); dispid 202;
  end;


// *********************************************************************//
// OLE Control Proxy class declaration
// Control Name     : TJPG
// Help String      : JPG Control
// Default Interface: IJPG
// Def. Intf. DISP? : No
// Event   Interface: IJPGEvents
// TypeFlags        : (34) CanCreate Control
// *********************************************************************//
  TJPGOnKeyPress = procedure(ASender: TObject; var Key: Smallint) of object;

  TJPG = class(TOleControl)
  private
    FOnClick: TNotifyEvent;
    FOnKeyPress: TJPGOnKeyPress;
    FIntf: IJPG;
    function  GetControlInterface: IJPG;
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
    procedure BmpToJPG(const FileName: WideString);
    property  ControlInterface: IJPG read GetControlInterface;
    property  DefaultInterface: IJPG read GetControlInterface;
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
    property BmpFile: WideString index 216 read GetWideStringProp write SetWideStringProp stored False;
    property Quality: Integer index 217 read GetIntegerProp write SetIntegerProp stored False;
    property OnClick: TNotifyEvent read FOnClick write FOnClick;
    property OnKeyPress: TJPGOnKeyPress read FOnKeyPress write FOnKeyPress;
  end;

procedure Register;

resourcestring
  dtlServerPage = 'Servers';

  dtlOcxPage = 'ActiveX';

implementation

uses ComObj;

procedure TJPG.InitControlData;
const
  CEventDispIDs: array [0..1] of DWORD = (
    $000000C9, $000000CA);
  CTFontIDs: array [0..0] of DWORD = (
    $FFFFFE00);
  CControlData: TControlData2 = (
    ClassID: '{662CA9D6-A177-44D4-A7BA-E6E477C95A39}';
    EventIID: '{EC890554-DAAC-47AC-8440-6AACE1A42A83}';
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

procedure TJPG.CreateControl;

  procedure DoCreate;
  begin
    FIntf := IUnknown(OleObject) as IJPG;
  end;

begin
  if FIntf = nil then DoCreate;
end;

function TJPG.GetControlInterface: IJPG;
begin
  CreateControl;
  Result := FIntf;
end;

function TJPG.DrawTextBiDiModeFlagsReadingOnly: Integer;
begin
  Result := DefaultInterface.DrawTextBiDiModeFlagsReadingOnly;
end;

procedure TJPG.InitiateAction;
begin
  DefaultInterface.InitiateAction;
end;

function TJPG.IsRightToLeft: WordBool;
begin
  Result := DefaultInterface.IsRightToLeft;
end;

function TJPG.UseRightToLeftReading: WordBool;
begin
  Result := DefaultInterface.UseRightToLeftReading;
end;

function TJPG.UseRightToLeftScrollBar: WordBool;
begin
  Result := DefaultInterface.UseRightToLeftScrollBar;
end;

procedure TJPG.SetSubComponent(IsSubComponent: WordBool);
begin
  DefaultInterface.SetSubComponent(IsSubComponent);
end;

procedure TJPG.BmpToJPG(const FileName: WideString);
begin
  DefaultInterface.BmpToJPG(FileName);
end;

procedure Register;
begin
  RegisterComponents(dtlOcxPage, [TJPG]);
end;

end.
